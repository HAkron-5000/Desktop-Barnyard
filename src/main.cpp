#ifndef UNICODE
#define UNICODE
#endif 

#include "DesktopBarnyardWindow.h"

#include <iostream>
#include <exception>

#include <Windows.h>

int main(){
    
    DesktopBarnyardWindow window;
    if (!window.Create(L"Barnyard", WS_OVERLAPPEDWINDOW)) {
        MessageBox(NULL, L"Failed to create window.", L"Error", MB_OK | MB_ICONERROR);
        return -1;
    }

    ShowWindow(window.Window(), 1);
    window.start();

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}