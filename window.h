#pragma once
#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Window
{
private:
    HINSTANCE m_hInstance;
    HWND m_hwnd;
public:
    Window(/* args */);
    ~Window();
    bool ProcessMessage();
};