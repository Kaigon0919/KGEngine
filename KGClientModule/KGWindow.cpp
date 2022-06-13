#include "KGWindow.h"
#include <assert.h>

namespace kg
{
	const HWND KGWindow::Create(const HINSTANCE hInst, LRESULT(*fpProc)(HWND, UINT, WPARAM, LPARAM), const TCHAR* pTitle, const TCHAR* pClass, int iWidth, int iHeight, int iIconID, int iSmallIcon, bool isShow, bool bWindowMode) noexcept
	{
		m_hInst = hInst;
		m_iWidth = iWidth;
		m_iHeight = iHeight;
		m_bWindowMode = bWindowMode;

		Register(pClass, fpProc, iIconID, iSmallIcon);
		CreateWnd(pTitle, pClass, isShow);

		return m_hWnd;
	}

	const HWND KGWindow::Create(const HINSTANCE hInst, const HWND hWnd, const int iWidth, const int iHeight, const bool bWindowMode) noexcept
	{
		assert(false && L"필요시 구현");
		return HWND();
	}

	const HWND KGWindow::Create(const WNDCLASSEX& wc, const TCHAR* const pTitle, const int iWidth, const int iHeight, const bool bShow) noexcept
	{
		assert(false && L"필요시 구현");
		return HWND();
	}

	void KGWindow::Register(const TCHAR* pClass, LRESULT(*fpProc)(HWND, UINT, WPARAM, LPARAM), int iIconID, int iSmallIconID)
	{
		WNDCLASSEX wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);

		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = fpProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = m_hInst;
		wcex.hIcon = LoadIcon(m_hInst, MAKEINTRESOURCE(iIconID));
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = NULL;// MAKEINTRESOURCEW(IDC_MY180629);
		wcex.lpszClassName = pClass;
		wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(iSmallIconID));

		RegisterClassEx(&wcex);
	}

	void KGWindow::Register(const WNDCLASSEX& wc)
	{
		RegisterClassEx(&wc);
	}

	void KGWindow::CreateWnd(const TCHAR* pTitle, const TCHAR* pClass, bool isShow)
	{
		m_hWnd = CreateWindow(pClass, pTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, m_iWidth, m_iHeight, nullptr, nullptr, m_hInst, nullptr);

		if (!m_hWnd)
		{
			return;
		}

		RECT rc = { 0, 0, m_iWidth, m_iHeight };

		AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
		SetWindowPos(m_hWnd, HWND_TOPMOST, 100, 100, rc.right - rc.left, rc.bottom - rc.top, SWP_NOMOVE | SWP_NOZORDER);

		SetShow(isShow);
	}

	void KGWindow::SetSize(int width, int height)
	{
		m_iWidth = width;
		m_iHeight = height;

		RECT Rc = { 0, 0, m_iWidth, m_iHeight };
		AdjustWindowRect(&Rc, WS_OVERLAPPEDWINDOW, FALSE);
		SetWindowPos(m_hWnd, 0, 0, 0, Rc.right - Rc.left, Rc.bottom - Rc.top, SWP_NOMOVE | SWP_NOZORDER);
	}

	void KGWindow::SetShow(bool bShow)
	{
		ShowWindow(m_hWnd, bShow ? SW_SHOW : SW_HIDE);
		UpdateWindow(m_hWnd);
	}

	void KGWindow::Show() const
	{
		ShowWindow(m_hWnd, SW_SHOW);
		UpdateWindow(m_hWnd);
	}

	void KGWindow::Hide() const
	{
		ShowWindow(m_hWnd, SW_HIDE);
		UpdateWindow(m_hWnd);
	}
};