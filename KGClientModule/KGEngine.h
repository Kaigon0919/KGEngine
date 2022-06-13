#pragma once
#include <Windows.h>

namespace kg
{
	class KGWindow;
	class KGDevice;
};

namespace kg
{
	class KGEngine
	{
	public:
		explicit KGEngine() : m_pMainWindow(nullptr), m_pDevice(nullptr) {}
		~KGEngine();

	public:
		bool Init(_In_ const TCHAR* pWindowName, _In_ const HINSTANCE hInst,const int iWidth, const int iHeight, const int iIconID, const int iSmallIcon, const bool isShow = true, const bool bWindowMode = true) noexcept;
		int	Run(void) noexcept;
	private: // Updater, ������ �������Ͱ� �ʿ��ϸ� �׶� Ŭ������ �и�.
		void Logic();
		int Render(float dt);

	private: // member.
		KGWindow* m_pMainWindow;
		KGDevice* m_pDevice;

	private:
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


	};
}