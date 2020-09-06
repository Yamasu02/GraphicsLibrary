#pragma once
#include "D2Dheaders.h"

class MiscUtils
{
public:

    D2D1_RECT_F RectToD2DRect(RECT rect);

    D2D1_ROUNDED_RECT RectToRoundedRect(D2D1_RECT_F rect, float x, float y);

    BOOL PointBelongsToRect(HWND hwnd, LPPOINT lp, D2D1_RECT_F rect);

    BOOL ScreenPointBelongsToRect(HWND hwnd, LPPOINT lp, D2D1_RECT_F rect);
};