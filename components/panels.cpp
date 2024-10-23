#include "../raylib/src/raylib.h"
#include "panels.h"
#include <iostream>

void Button::Render() {
    DrawRectangle(x, y, w, h, GRAY);
    Vector2 mid; mid.x = (x+w)/2.0; mid.y = (y+h)/2.0; // center text in middle of button
    std::cout << "MidX: " << mid.x << " MidY: " << mid.y << std::endl;
    DrawText(txt.c_str(), mid.x, mid.y, fontSize, BLACK);
}