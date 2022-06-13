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
		m_pDevice = new KGDevice(); // 굳이 동적으로 갖고있을 필요가 있나??? => 자답, 디바이스의 경우 세팅변경에 따른 delete 처리후 재생성 해주는것이 편할수도 있다.
		// 동적할당은 필요할때 생성하고 삭제할수 있다는 장점이 있다. 지울일이 없다면 정적, 있다면 동적할당을 사용하자.
		
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
			// PeekMessage : 메세지가 없을때는 FALSE를 반환하면서 바로 빠져나온다.
			// 메세지가 있을 경우 TRUE를 반환하게 된다.
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
		case WM_DESTROY: // 소멸자로 가지는지 확인.
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}

		return 0;
	}

}