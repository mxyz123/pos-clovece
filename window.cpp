#include "window.h"

LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg){
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

Window::Window(/* args */) : m_hInstance(GetModuleHandle(nullptr))
{
    const char* CLASS_NAME = "pos clovece";

    WNDCLASS wndClass = {};
    wndClass.lpszClassName = CLASS_NAME;
    wndClass.hInstance = m_hInstance;
    wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.lpfnWndProc = WindowProc;

    RegisterClass(&wndClass);

    DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

    int width = 500;
    int height = 500;

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;

    AdjustWindowRect(&rect, style, false);

    m_hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Človeče nehnevaj sa",
        style,
        rect.left,
        rect.top,
        rect.right - rect.left,
        rect.bottom - rect.top,
        NULL,
        NULL,
        m_hInstance,
        NULL
    );

    ShowWindow(m_hwnd, SW_SHOW);
}

Window::~Window()
{
    const char* CLASS_NAME = "pos clovece";

    UnregisterClass(CLASS_NAME, m_hInstance);
}

bool Window::ProcessMessage()
{
    MSG msg = {};
    while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE)){
        if (msg.message == WM_QUIT){
            return false;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return true;
}
