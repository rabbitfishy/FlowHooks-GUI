#pragma once
#include <Windows.h>
#include "../Singleton.hpp"

class MainWindow : public Singleton<MainWindow>
{
public:
	bool Init(int Width, int Height);
	void Shutdown();
	void Display();
	bool RunLoop();

	~MainWindow()
	{
		Shutdown();
	}

	HWND Hwnd()
	{
		return hWnd_;
	}
private:
	WNDCLASSEX WndClass_ = { 0 };
	HWND hWnd_ = nullptr;
};