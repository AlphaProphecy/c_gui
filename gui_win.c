#include <windows.h>

LRESULT WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
        HDC hdc = GetDC(hWnd);
        RECT rect = {50, 50, 200, 200};
        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
        FillRect(hdc, &rect, brush);
        DeleteObject(brush);
        ReleaseDC(hWnd, hdc);
        return 0;

    default:
        return DefWindowProcA(hWnd, msg, wParam, lParam);
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR b, int nCmdShow)
{
    WNDCLASSA class = {
        0,
        WinProc,
        0,
        0,
        hInstance,
        NULL,
        NULL,
        NULL,
        NULL,
        "myWindowClass"};

    RegisterClassA(&class);

    HWND hWnd = CreateWindowA(
        "myWindowClass",
        "My Window",
        WS_CAPTION | WS_POPUP | WS_SYSMENU,
        50,
        50,
        500,
        500,
        NULL,
        NULL,
        hInstance,
        NULL);

    ShowWindow(hWnd, nCmdShow);

    MSG msg;

    while (GetMessageA(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    return 0;
}