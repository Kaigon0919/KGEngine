#pragma once
#include<d3d11_4.h>
#include"Base/KGVector2.h"

#pragma comment(lib, "d3d11")
#pragma comment(lib, "d3dcompiler")
#pragma comment(lib, "dxguid")

namespace kg
{
	class KGDevice
	{
	public:
		explicit KGDevice();
		~KGDevice();

	public:
		ID3D11Device*			GetDevice()			const { return m_pDevice; }
		ID3D11DeviceContext*	GetContext()		const { return m_pContext; }
		IDXGISwapChain*			GetSwapChain()		const { return m_pSwapChain; }

	public:
		bool Init(_In_ const HWND hWnd, _In_ const unsigned int iWidth, _In_ const unsigned int iHeight, _In_ const bool bWindowMode);
		void ClearTarget(_In_ const float r, _In_ const float g, _In_ const float b, _In_ const float a);
		void ClearTarget(_In_ const float fClearColor[4]);
		void Present();

	private:
		bool CreateSwapChain(bool bWindowMode);
		bool CreateDepthStencilView();
		bool CreateViewPort();

	public:
		// 뷰포트와 윈도우 사이즈의 비율.
		Vector2f GetWindowToViewportRatio() const;

	private:
		HWND					m_hWnd;
		ID3D11Device*			m_pDevice;
		ID3D11DeviceContext*	m_pContext;
		IDXGISwapChain*			m_pSwapChain;
		ID3D11RenderTargetView* m_pTargetView;
		ID3D11DepthStencilView* m_pDepthStencilView;

		unsigned int m_iWidth;
		unsigned int m_iHeight;
		unsigned int m_iSampleCount;
		unsigned int m_iSampleQuality;
	};
};