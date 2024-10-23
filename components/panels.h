#ifndef PANELS_H
#define PANELS_H

#include "../raylib/src/raylib.h"
#include <string>
#include <vector>

class Button{
    public:
    int x;
    int y;
    int w;
    int h;
    std::string txt;
    int fontSize;
    bool pressed;
    Button(int x, int y, int w, int h, std::string txt, int fontSize) : x(x),y(y),w(w),h(h),
          txt(txt), fontSize(fontSize), pressed(false) {}
    void Render();
    bool DetectPress(Vector2 mousepos, bool mousePressed); // if unpressed, the press is activated
};

class ButtonContainer {
    public:
    int x; 
    int y;
    int w;
    int h;
    std::vector<Button> buttons;
    ButtonContainer(int x, int y, int w, int h) : x(x),y(y),w(w),h(h) {}
    void AddButton(Button b);
    void Render();
};

#endif