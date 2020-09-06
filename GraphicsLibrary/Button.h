#pragma once
#include "Time.h"
#include "BaseTemplate.h"


template <typename T>
class Button 
{
public:

    std::chrono::system_clock::time_point start;
    std::wstring ButtonLabel;
    T* ptr;

    bool started = false;
    D2D1_RECT_F rect;
    ID2D1Brush* brush;
    IDWriteTextFormat* Format;
    IDWriteTextFormat* ShrinkedFormat;
    ID2D1Brush* brushText;
    DWRITE_TEXT_ALIGNMENT alignment;
    bool ShouldAnimate = false;
    int style;


    Button(T* ptr, ID2D1Brush* brush, std::wstring ButtonLabel, IDWriteTextFormat* Format, IDWriteTextFormat* ShrinkedFormat, ID2D1Brush* brushText, DWRITE_TEXT_ALIGNMENT alignment, int style)
    {
        this->ptr = ptr;
        this->brush = brush;
        this->ButtonLabel = ButtonLabel;
        this->Format = Format;
        this->ShrinkedFormat = ShrinkedFormat;
        this->brushText = brushText;
        this->alignment = alignment;
        this->style = style;
    }

    void DrawButton(float RadiusX, float RadiusY)
    {
        if (ShouldAnimate)
        {
            ShrinkButton();
        }

        switch (style)
        {
        case 0:
        {
            ptr->pRenderTarget->FillRoundedRectangle(ptr->RectToRoundedRect(rect, RadiusX, RadiusY), brush);
        }
        case 1:
        {
            ptr->pRenderTarget->DrawRoundedRectangle(ptr->RectToRoundedRect(rect, RadiusX, RadiusY), brush, 1.1, 0);
        }
        }

        ptr->drawText(ShouldAnimate ? ShrinkedFormat : Format, ButtonLabel, rect, brushText, alignment);
    }

    void ShrinkButton()
    {
        rect.left += 20;
        rect.right -= 20;
        rect.top += 10;
        rect.bottom -= 10;
    }


    ~Button()
    {
        RtlZeroMemory(&rect, sizeof(rect));
        brush->Release();
        Format->Release();
    }
};

