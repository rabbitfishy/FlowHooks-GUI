#include <cstring>

#include "Input.hpp"
#include "../MainWindow/MainWindow.hpp"

#define GET_X_LPARAM(lp) ((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp) ((int)(short)HIWORD(lp))

namespace FHGUI
{
	void Input::Update()
	{
		std::memcpy(PrevPressedKeys_, PressedKeys_, sizeof(PrevPressedKeys_));

		bool OutOfFocus = GetForegroundWindow() != MainWindow::Get().Hwnd();
		for (int i = 0; i < MAX_KEYS; ++i) {
			PressedKeys_[i] = OutOfFocus ? false : (GetAsyncKeyState(i) & 0xFFFF);
		}
	}

	bool Input::OnWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg) {
		case WM_MOUSEMOVE:
			MousePos_ = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };
			return true;
		}

		return false;
	}
}