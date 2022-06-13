#include "KGDevice.h"

namespace kg
{
    KGDevice::KGDevice() : m_hWnd(), m_pDevice(nullptr), m_pContext(nullptr), m_pSwapChain(nullptr), m_pTargetView(nullptr), m_pDepthStencilView(nullptr), m_iWidth(), m_iHeight(),
        m_iSampleCount(32), m_iSampleQuality()
    {
    }

    KGDevice::~KGDevice()
    {
        m_hWnd = 0;
        m_iWidth = 0;
        m_iHeight = 0;
        m_iSampleCount = 0;
        m_iSampleQuality = 0;

        if (m_pDepthStencilView)
        {
            m_pDepthStencilView->Release();
            m_pDepthStencilView = nullptr;
        }
        if (m_pTargetView)
        {
            m_pTargetView->Release();
            m_pTargetView = nullptr;
        }
        if (m_pSwapChain)
        {
            m_pSwapChain->Release();
            m_pSwapChain = nullptr;
        }

        m_pContext->ClearState();
        if (m_pContext)
        {
            m_pContext->Release();
            m_pContext = nullptr;
        }
        if (m_pDevice)
        {
            m_pDevice->Release();
            m_pDevice = nullptr;
        }
    }

    bool KGDevice::Init(HWND hWnd, unsigned int iWidth, unsigned int iHeight, bool bWindowMode)
    {
        if (0 == hWnd)
        {
            assert(false && "hWnd 값이 비정상입니다.");
            return false;
        }

        m_hWnd = hWnd;

        unsigned int iFlag = 0;

#ifdef _DEBUG
        iFlag = D3D11_CREATE_DEVICE_DEBUG;
#endif
        m_iWidth = iWidth;
        m_iHeight = iHeight;

        iFlag |= D3D11_CREATE_DEVICE_BGRA_SUPPORT;

        D3D_FEATURE_LEVEL	eFLevel = D3D_FEATURE_LEVEL_11_0;
        D3D_FEATURE_LEVEL	eFLevel1 = D3D_FEATURE_LEVEL_11_0;

        if (FAILED(D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, iFlag, &eFLevel, 1, D3D11_SDK_VERSION, &m_pDevice, &eFLevel1, &m_pContext)))
        {
            assert(false && L"Fail Create device");
            return false;
        }

        if (FAILED(m_pDevice->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, m_iSampleCount, &m_iSampleQuality)))
        {
            assert(false && "Failed to Function of CheckMultisampleQualityLevels");
            return false;
        }

        if (m_iSampleQuality <= 0)
        {
            m_iSampleCount = 1;
            m_iSampleQuality = 0;
            if (FAILED(m_pDevice->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, m_iSampleCount, &m_iSampleQuality)))
            {
                assert(false && "Fail Multisample");
                return false;
            }
        }

        if (!CreateSwapChain(bWindowMode))
        {
            return false; // 함수 내부에 assert가 있기때문에 생략.
        }

        if (!CreateDepthStencilView())
        {
            return false;
        }

        if (!CreateViewPort())
        {
            return false;
        }

        return true;
    }

    void KGDevice::ClearTarget(const float r, const float g, const float b, const float a)
    {
        float fClearColor[4] = { r,g,b,a };

        ClearTarget(fClearColor);
    }

    void KGDevice::ClearTarget(const float fClearColor[4])
    {
        if (nullptr == m_pContext)
        {
            assert(false && L"Error, Contenxt is nullptr");
            return;
        }

        m_pContext->ClearRenderTargetView(m_pTargetView, fClearColor);
        m_pContext->ClearDepthStencilView(m_pDepthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    }

    void KGDevice::Present()
    {
        if (m_pSwapChain)
        {
            m_pSwapChain->Present(0, 0);
        }
    }

    bool KGDevice::CreateSwapChain(bool bWindowMode)
    {
        DXGI_SWAP_CHAIN_DESC	tSwapDesc = {};
        tSwapDesc.BufferDesc.Width = m_iWidth;
        tSwapDesc.BufferDesc.Height = m_iHeight;
        tSwapDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        tSwapDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
        tSwapDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
        tSwapDesc.BufferDesc.RefreshRate.Numerator = 60;
        tSwapDesc.BufferDesc.RefreshRate.Denominator = 1;
        tSwapDesc.BufferCount = 1;
        tSwapDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        tSwapDesc.OutputWindow = m_hWnd;
        tSwapDesc.SampleDesc.Count = m_iSampleCount;
        tSwapDesc.SampleDesc.Quality = m_iSampleQuality ? (m_iSampleQuality - 1) : 0;
        tSwapDesc.Windowed = bWindowMode;
        tSwapDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

        IDXGIDevice* pIdxDevice = nullptr;
        IDXGIAdapter* pIdxAdapter = nullptr;
        IDXGIFactory* pIdxFactory = nullptr;

        if (FAILED(m_pDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)&pIdxDevice)))
        {
            assert(false && "Fail Get IDXGIDevice");
            return false;
        }

        if (FAILED(pIdxDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&pIdxAdapter)))
        {
            assert(false && "Fail Get IDXGIAdapter");
            return false;
        }

        if (FAILED(pIdxAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&pIdxFactory)))
        {
            assert(false && "Fail Get IDXGIFactory");
            return false;
        }

        if (FAILED(pIdxFactory->CreateSwapChain(m_pDevice, &tSwapDesc, &m_pSwapChain)))
        {
            assert(false && "Fail CreateSwapChain");
            return false;
        }

        if (pIdxFactory)
        {
            pIdxFactory->Release();
            pIdxFactory = nullptr;
        }

        if (pIdxAdapter)
        {
            pIdxAdapter->Release();
            pIdxAdapter = nullptr;
        }

        if (pIdxDevice)
        {
            pIdxDevice->Release();
            pIdxDevice = nullptr;
        }

        return true;
    }

    bool KGDevice::CreateDepthStencilView()
    {
        ID3D11Texture2D* pBuffer = nullptr;
        if (FAILED(m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBuffer)))
        {
            assert(false && "Failed to get the ID3D11Texture2D buffer of the swap chain.");
            return false;
        }

        if (FAILED(m_pDevice->CreateRenderTargetView(pBuffer, nullptr, &m_pTargetView)))
        {
            assert(false && "Failed to Create RenderTargetView.");
            return false;
        }

        if (pBuffer)
        {
            pBuffer->Release();
            pBuffer = nullptr;
        }

        D3D11_TEXTURE2D_DESC	tDesc = {};
        tDesc.Width = m_iWidth;
        tDesc.Height = m_iHeight;
        tDesc.ArraySize = 1;
        tDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
        tDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
        tDesc.Usage = D3D11_USAGE_DEFAULT;
        tDesc.MipLevels = 1;
        tDesc.SampleDesc.Count = m_iSampleCount;
        tDesc.SampleDesc.Quality = m_iSampleQuality ? (m_iSampleQuality - 1) : 0; 

        if (FAILED(m_pDevice->CreateTexture2D(&tDesc, nullptr, &pBuffer)))
        {
            assert(false && "Failed to Create Texture2D of the DepthStencilView");
            return false;
        }

        if (FAILED(m_pDevice->CreateDepthStencilView(pBuffer, nullptr, &m_pDepthStencilView)))
        {
            assert(false && "Failed to Create DepthStencilView");
            return false;
        }

        if (pBuffer)
        {
            pBuffer->Release();
            pBuffer = nullptr;
        }

        m_pContext->OMSetRenderTargets(1, &m_pTargetView, m_pDepthStencilView);
        return true;
    }

    bool KGDevice::CreateViewPort()
    {
        D3D11_VIEWPORT	tVP = {};

        tVP.TopLeftX = 0.f;
        tVP.TopLeftY = 0.f;
        tVP.Width = (float)m_iWidth;
        tVP.Height = (float)m_iHeight;
        tVP.MinDepth = 0.f;
        tVP.MaxDepth = 1.f;

        m_pContext->RSSetViewports(1, &tVP);
        return true;
    }

    Vector2f KGDevice::GetWindowToViewportRatio() const
    {
        RECT rcWindow = {};
        GetClientRect(m_hWnd, &rcWindow);

        Vector2f vSize;
        vSize.x = (float)(rcWindow.right - rcWindow.left);
        vSize.y = (float)(rcWindow.bottom - rcWindow.top);

        Vector2f vViewport;
        vViewport.x = (float)m_iWidth;
        vViewport.y = (float)m_iHeight;

        return vViewport / vSize;
    }

};
