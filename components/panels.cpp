#include "../raylib/src/raylib.h"
#include "panels.h"

void Button::Render() {
    DrawRectangle(x, y, w, h, GRAY);
    int midX = x+w/2;
    int midY = y+h/2;
    int wordLen = MeasureText(txt.c_str(), fontSize);
    DrawText(txt.c_str(), midX-wordLen/2, midY-fontSize/2, fontSize, BLACK);
}