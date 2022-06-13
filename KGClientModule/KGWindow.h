#pragma once
#include<Windows.h>
#include<functional>

namespace kg
{
	class KGWindow
	{
	public:
		HINSTANCE	GetWindowInstance()	const{ return m_hInst;}
		HWND		GetWindowHandle()	const{ return m_hWnd;}
	public:
		const HWND Create(_In_ const HINSTANCE hInst, _In_ LRESULT(CALLBACK* fpProc)(HWND, UINT, WPARAM, LPARAM), const TCHAR* pTitle, const TCHAR* pClass, int iWidth, int iHeight, int iIconID, int iSmallIcon, bool isShow = true, bool bWindowMode = true) noexcept;
		const HWND Create(_In_ const HINSTANCE hInst, _In_ const HWND hWnd, _In_ const int iWidth, _In_ const int iHeight, _In_ const bool bWindowMode = true) noexcept;
		const HWND Create(_In_ const WNDCLASSEX& wc, _In_ const TCHAR* const pTitle, _In_ const int iWidth, _In_ const int iHeight, _In_ const bool bShow = true) noexcept;

	private:
		void Register(_In_ const TCHAR* pClass, _In_ LRESULT(CALLBACK* fpProc)(HWND, UINT, WPARAM, LPARAM), _In_ const int iIconID, _In_ const int iSmallIconID);
		void Register(_In_ const WNDCLASSEX& wc);
		void CreateWnd(_In_ const TCHAR* pTitle, _In_ const TCHAR* pClass, _In_ bool isShow = true);

	public:
		void SetSize(_In_ const int width, _In_ const int height);
		void SetShow(_In_ const bool bShow);
		void Show()const;
		void Hide()const;

	private:
		HINSTANCE	m_hInst;
		HWND		m_hWnd;

		int m_iWidth;
		int m_iHeight;
		bool m_bWindowMode;

		std::function<void()> m_fpUpdateFunc;
	};
}

