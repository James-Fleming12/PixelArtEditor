#ifndef PANELS_H
#define PANELS_H

#include <string>

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
    void TogglePress(); // if unpressed, the press is activated
};

#endif