#include "CMWindow.h"
#include <cassert>

namespace CML
{
	LRESULT CALLBACK WindowProc(HWND asd, UINT uMsg, WPARAM wParam, LPARAM lParam);


	LRESULT CALLBACK WindowProc(HWND asd, UINT uMsg, WPARAM wParam, LPARAM lParam) //without this nothing works, so I say we keep it
	{
		switch (uMsg){
		case WM_CREATE:
		{
						  return 0;
		}
		case WM_DESTROY:
		{
						   PostQuitMessage(0);
						   DestroyWindow(asd);
						   return 0;
		}
		default:

			return DefWindowProc(asd, uMsg, wParam, lParam);

		}
		

	}

	CMWindow::CMWindow(int windowType, const wchar_t* CLASS_NAME, int windowWidht, int windowHeight)//constructor for window with "parameters"
	{
		

		WNDCLASS wc = {};

		_CLASS_NAME = CLASS_NAME;
		_windowWidht = windowWidht;
		_windowHeight = windowHeight;

		wc.lpfnWndProc = WindowProc;
		wc.hInstance = GetModuleHandle(nullptr);
		wc.lpszClassName = _CLASS_NAME;

		RegisterClass(&wc);

		_windowHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, _CLASS_NAME, L"CMWindow", WS_OVERLAPPEDWINDOW, 100, 100, _windowWidht, _windowHeight, //Windowhandle pointter creation
			NULL, NULL, GetModuleHandle(nullptr), NULL);
		if (_windowHandle == nullptr)
		{

			std::cout << "Window handle creation failed" << std::endl;

		}


	}
	CMWindow::CMWindow()
	{
		CMWindow(0, L"asd", 800, 600);
	}


	CMWindow::~CMWindow() //window destructor MARK 1 "The Eliminator"
	{
		/* I'm useful! */
		//delete _windowHandle;
	}


	HWND CMWindow::CMWindowHandle()// Return handle to the window
	{
		return _windowHandle;
	}

	void CMWindow::ShowCMWindow()//Showing the window since 2014
	{
		ShowWindow(_windowHandle, SW_SHOWNORMAL);//"Another 'witty' comment about the code"
	}


	void CMWindow::WindowMessageCheck(){
		MSG msg;//I don't even...

		while (PeekMessage(&msg, _windowHandle, NULL, NULL, PM_REMOVE))
		{
			
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}