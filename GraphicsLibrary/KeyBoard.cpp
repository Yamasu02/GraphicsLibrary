#include "D2Dheaders.h"
#include "KeyBoard.h"


void KeyBoard::PushChar(wchar_t wParam, std::wstring& string, int MaxStrSize)
{
    if (isgraph(wParam) && string.size() <= MaxStrSize)
    {
        string.push_back(wParam);
    }
}

void KeyBoard::RemoveChar(std::wstring& str)
{
    if (str.size() > 0)
    {
        str.pop_back();
        str.resize(str.size());
    }
}

BOOL KeyBoard::CursorBelongsToRect(HWND hwnd, D2D1_RECT_F rect)
{
    return PointBelongsToRect(hwnd, &Points.point, rect);
}

BOOL KeyBoard::PointBelongsToRect(HWND hwnd, LPPOINT lp, D2D1_RECT_F rect)
{
    if (lp->x >= rect.left && lp->x <= rect.right && lp->y >= rect.top && lp->y <= rect.bottom)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

BOOL KeyBoard::ScreenPointBelongsToRect(HWND hwnd, LPPOINT lp, D2D1_RECT_F rect)
{
    if (ScreenToClient(hwnd, lp))
    {
        if (PointBelongsToRect(hwnd, lp, rect))
        {
            return true;
        }
    }
    return false;
}
