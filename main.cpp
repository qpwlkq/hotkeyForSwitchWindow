#include "pch.h"
#include <iostream>
#include <windows.h>
#include <Psapi.h>

int main()
{
    std::cout << "start:" << std::endl;
    int i = 0;
    HWND window = FindWindowEx(GetDesktopWindow(), NULL, NULL, NULL);
    while (window)
    {
        wchar_t buffer[MAX_PATH];
        DWORD dwProcId = 0;

        GetWindowThreadProcessId(window, &dwProcId);
        HANDLE hProc = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, dwProcId);
        if (!GetProcessImageFileNameW(hProc, buffer, MAX_PATH)) {
            return ;
        }

        CloseHandle(hProc);
            
        int length = wcslen(buffer);
        if (length > 16)
        {
            wchar_t *name = &buffer[length - 16];
            if (wcscmp(name, L"LiveTeleCast.exe") == 0)
            {
                if (IsWindowVisible(window))
                {
                    DWORD styles, ex_styles;
                    bool is_WS_EX_TOOLWINDOW = false, is_WS_CHILD = false;
                    styles = (DWORD)GetWindowLongPtr(window, GWL_STYLE);
                    ex_styles = (DWORD)GetWindowLongPtr(window, GWL_EXSTYLE);

                    if (ex_styles & WS_EX_TOOLWINDOW) {
                        is_WS_EX_TOOLWINDOW = true;
                    }
                    else if (styles & WS_CHILD) {
                        is_WS_CHILD = true;
                    }
                    else
                    {
                        i++;
                        std::wcout << " is visible:" << IsWindowVisible(window) << " is_WS_EX_TOOLWINDOW:" << is_WS_EX_TOOLWINDOW << " is_WS_CHILD:" << is_WS_CHILD << " exe:" << buffer << std::endl;
                    }

                    
                }
                
            }
        }
        
        

        window = FindWindowEx(GetDesktopWindow(), window, NULL, NULL);
    }
    std::cout << "LiveTeleCast window number: " << i; 
}