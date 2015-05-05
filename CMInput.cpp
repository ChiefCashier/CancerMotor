#include "CMInput.h"
namespace CML
{
	POINT pt;
	CMInput::CMInput()
	{
	}


	CMInput::~CMInput()
	{
	}
	void CMInput::Update(WPARAM p)
	{

	}
	bool CMInput::isKeyPressed(Key key)
	{

		int vkey = 0;
		switch (key)
		{
		default:                   vkey = 0;             break;
		case CMInput::A:          vkey = 'A';           break;
		case CMInput::B:          vkey = 'B';           break;
		case CMInput::C:          vkey = 'C';           break;
		case CMInput::D:          vkey = 'D';           break;
		case CMInput::E:          vkey = 'E';           break;
		case CMInput::F:          vkey = 'F';           break;
		case CMInput::G:          vkey = 'G';           break;
		case CMInput::H:          vkey = 'H';           break;
		case CMInput::I:          vkey = 'I';           break;
		case CMInput::J:          vkey = 'J';           break;
		case CMInput::K:          vkey = 'K';           break;
		case CMInput::L:          vkey = 'L';           break;
		case CMInput::M:          vkey = 'M';           break;
		case CMInput::N:          vkey = 'N';           break;
		case CMInput::O:          vkey = 'O';           break;
		case CMInput::P:          vkey = 'P';           break;
		case CMInput::Q:          vkey = 'Q';           break;
		case CMInput::R:          vkey = 'R';           break;
		case CMInput::S:          vkey = 'S';           break;
		case CMInput::T:          vkey = 'T';           break;
		case CMInput::U:          vkey = 'U';           break;
		case CMInput::V:          vkey = 'V';           break;
		case CMInput::W:          vkey = 'W';           break;
		case CMInput::X:          vkey = 'X';           break;
		case CMInput::Y:          vkey = 'Y';           break;
		case CMInput::Z:          vkey = 'Z';           break;
		case CMInput::Num0:       vkey = '0';           break;
		case CMInput::Num1:       vkey = '1';           break;
		case CMInput::Num2:       vkey = '2';           break;
		case CMInput::Num3:       vkey = '3';           break;
		case CMInput::Num4:       vkey = '4';           break;
		case CMInput::Num5:       vkey = '5';           break;
		case CMInput::Num6:       vkey = '6';           break;
		case CMInput::Num7:       vkey = '7';           break;
		case CMInput::Num8:       vkey = '8';           break;
		case CMInput::Num9:       vkey = '9';           break;
		case CMInput::Escape:     vkey = VK_ESCAPE;     break;
		case CMInput::LControl:   vkey = VK_LCONTROL;   break;
		case CMInput::LShift:     vkey = VK_LSHIFT;     break;
		case CMInput::LAlt:       vkey = VK_LMENU;      break;
		case CMInput::LSystem:    vkey = VK_LWIN;       break;
		case CMInput::RControl:   vkey = VK_RCONTROL;   break;
		case CMInput::RShift:     vkey = VK_RSHIFT;     break;
		case CMInput::RAlt:       vkey = VK_RMENU;      break;
		case CMInput::RSystem:    vkey = VK_RWIN;       break;
		case CMInput::Menu:       vkey = VK_APPS;       break;
		case CMInput::LBracket:   vkey = VK_OEM_4;      break;
		case CMInput::RBracket:   vkey = VK_OEM_6;      break;
		case CMInput::SemiColon:  vkey = VK_OEM_1;      break;
		case CMInput::Comma:      vkey = VK_OEM_COMMA;  break;
		case CMInput::Period:     vkey = VK_OEM_PERIOD; break;
		case CMInput::Quote:      vkey = VK_OEM_7;      break;
		case CMInput::Slash:      vkey = VK_OEM_2;      break;
		case CMInput::BackSlash:  vkey = VK_OEM_5;      break;
		case CMInput::Tilde:      vkey = VK_OEM_3;      break;
		case CMInput::Equal:      vkey = VK_OEM_PLUS;   break;
		case CMInput::Dash:       vkey = VK_OEM_MINUS;  break;
		case CMInput::Space:      vkey = VK_SPACE;      break;
		case CMInput::Return:     vkey = VK_RETURN;     break;
		case CMInput::BackSpace:  vkey = VK_BACK;       break;
		case CMInput::Tab:        vkey = VK_TAB;        break;
		case CMInput::PageUp:     vkey = VK_PRIOR;      break;
		case CMInput::PageDown:   vkey = VK_NEXT;       break;
		case CMInput::End:        vkey = VK_END;        break;
		case CMInput::Home:       vkey = VK_HOME;       break;
		case CMInput::Insert:     vkey = VK_INSERT;     break;
		case CMInput::Delete:     vkey = VK_DELETE;     break;
		case CMInput::Add:        vkey = VK_ADD;        break;
		case CMInput::Subtract:   vkey = VK_SUBTRACT;   break;
		case CMInput::Multiply:   vkey = VK_MULTIPLY;   break;
		case CMInput::Divide:     vkey = VK_DIVIDE;     break;
		case CMInput::Left:       vkey = VK_LEFT;       break;
		case CMInput::Right:      vkey = VK_RIGHT;      break;
		case CMInput::Up:         vkey = VK_UP;         break;
		case CMInput::Down:       vkey = VK_DOWN;       break;
		case CMInput::Numpad0:    vkey = VK_NUMPAD0;    break;
		case CMInput::Numpad1:    vkey = VK_NUMPAD1;    break;
		case CMInput::Numpad2:    vkey = VK_NUMPAD2;    break;
		case CMInput::Numpad3:    vkey = VK_NUMPAD3;    break;
		case CMInput::Numpad4:    vkey = VK_NUMPAD4;    break;
		case CMInput::Numpad5:    vkey = VK_NUMPAD5;    break;
		case CMInput::Numpad6:    vkey = VK_NUMPAD6;    break;
		case CMInput::Numpad7:    vkey = VK_NUMPAD7;    break;
		case CMInput::Numpad8:    vkey = VK_NUMPAD8;    break;
		case CMInput::Numpad9:    vkey = VK_NUMPAD9;    break;
		case CMInput::F1:         vkey = VK_F1;         break;
		case CMInput::F2:         vkey = VK_F2;         break;
		case CMInput::F3:         vkey = VK_F3;         break;
		case CMInput::F4:         vkey = VK_F4;         break;
		case CMInput::F5:         vkey = VK_F5;         break;
		case CMInput::F6:         vkey = VK_F6;         break;
		case CMInput::F7:         vkey = VK_F7;         break;
		case CMInput::F8:         vkey = VK_F8;         break;
		case CMInput::F9:         vkey = VK_F9;         break;
		case CMInput::F10:        vkey = VK_F10;        break;
		case CMInput::F11:        vkey = VK_F11;        break;
		case CMInput::F12:        vkey = VK_F12;        break;
		case CMInput::F13:        vkey = VK_F13;        break;
		case CMInput::F14:        vkey = VK_F14;        break;
		case CMInput::F15:        vkey = VK_F15;        break;
		case CMInput::Pause:      vkey = VK_PAUSE;      break;
		}


		return (GetAsyncKeyState(vkey) & 0x8000) != 0;
	}
	bool CMInput::isMouseKeyPressed(CMInput::MouseKey key)
	{
		int vkey = 0;
		switch (key)
		{
		case CMInput::Mouse1:
			vkey = VK_LBUTTON;
			break;
		case CMInput::Mouse2:
			vkey = VK_RBUTTON;
			break;
		case CMInput::Mouse3:
			vkey = VK_MBUTTON;
			break;
		default:
			return false;


		}
		return(GetAsyncKeyState(vkey) & 0x8000 != 0);
	}
	/*
	TODO: Return vector2
	return null/-1 values if mouse is outside window
	merge getMouseX and getMouseY
	*/

	int CMInput::getMouseX(HWND windowh)
	{
		GetCursorPos(&pt);
		ScreenToClient(windowh, &pt);
		return pt.x;
	}
	int CMInput::getMouseY(HWND windowh)
	{
		GetCursorPos(&pt);
		ScreenToClient(windowh, &pt);
		return pt.y;
	}
}