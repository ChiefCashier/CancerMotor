#pragma once

#ifndef WIN32_LEAN_AND_MEAN 
#define WIN32_LEAN_AND_MEAN 
#endif


#include <Windows.h>
#include <iostream>

#include "glew.h"
#include "ResourceManager.h"
#include "CMImage.h"


namespace CML
{
	class CMWindow
	{
	public:

		//constructors
		CMWindow();
		CMWindow(int windowType, const wchar_t* CLASS_NAME,
				 int windowWidht, int windowHeight);

		//destructors
		~CMWindow();

		//window handle makers
		HWND CMWindowHandle();

		//and the rest
		void ShowCMWindow();
		void WindowMessageCheck();
		int _windowWidht, _windowHeight;

	private:

		//things and stuff
		wchar_t _windowName;

		int _windowType;
		const wchar_t* _CLASS_NAME;

		//thingamabob(s)
		HWND _windowHandle;

	};
}