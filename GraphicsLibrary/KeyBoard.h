#pragma once
#include <Windows.h>
#include <iostream>

class KeyBoard// : public MiscUtils
{
public:

    static struct Points
    {
        static inline POINT point = { 0,0 };

    }Points;


    void PushChar(wchar_t wParam, std::wstring& string, int MaxStrSize);


    void RemoveChar(std::wstring& str);
    

    BOOL CursorBelongsToRect(HWND hwnd, D2D1_RECT_F rect);


    BOOL PointBelongsToRect(HWND hwnd, LPPOINT lp, D2D1_RECT_F rect);


    BOOL ScreenPointBelongsToRect(HWND hwnd, LPPOINT lp, D2D1_RECT_F rect);
};

