#include "MiscConversions.h"



D2D1_RECT_F MiscUtils::RectToD2DRect(RECT rect)
{
    return { (FLOAT)rect.left , (FLOAT)rect.top , (FLOAT)rect.right , (FLOAT)rect.bottom };
}

D2D1_ROUNDED_RECT MiscUtils::RectToRoundedRect(D2D1_RECT_F rect, float x, float y)
{
    return { rect, x, y };
}

BOOL MiscUtils::PointBelongsToRect(HWND hwnd, LPPOINT lp, D2D1_RECT_F rect)
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

BOOL MiscUtils::ScreenPointBelongsToRect(HWND hwnd, LPPOINT lp, D2D1_RECT_F rect)
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