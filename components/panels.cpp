#include "../raylib/src/raylib.h"
#include <string>
#include "panels.h"

#define ButtonS 2 // button shadow

void Button::Render() {
    if (pressed) {
        DrawRectangle(x, y, w, ButtonS, DARKGRAY);
        DrawRectangle(x, y + ButtonS, w, h - ButtonS, GRAY);
        int midX = x+w/2;
        int midY = y+h/2;
        int wordLen = MeasureText(txt.c_str(), fontSize);
        DrawText(txt.c_str(), midX-wordLen/2, midY-fontSize/2 + ButtonS, fontSize, BLACK);
    } else {
        DrawRectangle(x, y, w, h, GRAY);
        int midX = x+w/2;
        int midY = y+h/2;
        int wordLen = MeasureText(txt.c_str(), fontSize);
        DrawText(txt.c_str(), midX-wordLen/2, midY-fontSize/2, fontSize, BLACK);
    }
}

bool Button::DetectPress(Vector2 mouse, bool mousePressed) {
    bool xCol = mouse.x > x && mouse.x < x + w;
    bool yCol = mouse.y > y && mouse.y < y + h;
    if (!mousePressed && pressed && xCol && yCol) { // actual press (let go of button)
        this->pressed = false;
        return true;
    }
    if (mousePressed && !pressed && xCol && yCol) { // toggle pressed
        this->pressed = true;
    }
    return false;
}

void ButtonContainer::Add(Button b) { // buttons need to be initialized (coordinates don't matter)
    int total = padding;
    for (Button& i : buttons) {
        if (orientation == 1) { // horizontal
            total += i.w + padding;
        } else if (orientation == 2) { // vertical
            total += i.h + padding;
        }
    }
    if (orientation == 1) {
        b.x = total;
        b.y = this->y + padding;
    } else if (orientation == 2) {
        b.x = this->x + padding;
        b.y = total;
    }
    this->buttons.push_back(b);
}

void ButtonContainer::Render() {
    DrawRectangle(x, y, w, h, LIGHTGRAY);
    for (Button b : buttons) {
        b.Render();
    }
}

std::string ButtonContainer::DetectPress(Vector2 mpos, bool mp) {
    std::string res = "";
    for (Button& b : this->buttons) {
        if (b.DetectPress(mpos, mp)) {
            res = b.txt;
        }
    }
    return res;
}