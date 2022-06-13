#include "KGEngine.h"
#include "KGWindow.h"

#include "RendererEngine/KGDevice.h"

namespace kg
{
	KGEngine::~KGEngine()
	{

		if (nullptr != m_pDevice)
		{
			delete m_pDevice;
			m_pDevice = nullptr;
		}

		if (nullptr != m_pMainWindow)
		{
			delete m_pMainWindow;
			m_pMainWindow = nullptr;
		}
	}

	bool KGEngine::Init(_In_ const TCHAR* pWindowName, _In_ const HINSTANCE hInst, int iWidth, int iHeight, int iIconID, int iSmallIcon, bool isShow/* = true*/, bool bWindowMode/* = true*/) noexcept
	{
		m_pMainWindow = new KGWindow();
		m_pDevice = new KGDevice(); // ���� �������� �������� �ʿ䰡 �ֳ�??? => �ڴ�, ����̽��� ��� ���ú��濡 ���� delete ó���� ����� ���ִ°��� ���Ҽ��� �ִ�.
		// �����Ҵ��� �ʿ��Ҷ� �����ϰ� �����Ҽ� �ִٴ� ������ �ִ�. �������� ���ٸ� ����, �ִٸ� �����Ҵ��� �������.
		
		if (0 == m_pMainWindow->Create(hInst, WndProc, pWindowName, pWindowName, iWidth, iHeight, iIconID, iSmallIcon, bWindowMode))
		{
			return false;
		}

		if (false == m_pDevice->Init(m_pMainWindow->GetWindowHandle(), iWidth, iHeight, bWindowMode))
		{
			return false;
		}

		return true;
	}

	int	KGEngine::Run(void) noexcept
	{
		MSG msg = MSG();

		while(WM_QUIT != msg.message)
		{
			// PeekMessage : �޼����� �������� FALSE�� ��ȯ�ϸ鼭 �ٷ� �������´�.
			// �޼����� ���� ��� TRUE�� ��ȯ�ϰ� �ȴ�.
			if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				this->Logic();
			}
		}

		return (int)msg.wParam;
	}

	void KGEngine::Logic()
	{
		int flag = 0;

		flag = Render(0);
	}

	int KGEngine::Render(float dt)
	{
		m_pDevice->ClearTarget(1.f, 1.f, 1.f, 1.f);

		m_pDevice->Present();

		return 0;
	}


	LRESULT CALLBACK KGEngine::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		case WM_MOUSEWHEEL:
			break;
		case WM_DESTROY: // �Ҹ��ڷ� �������� Ȯ��.
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}

		return 0;
	}

}