#ifndef EDITOR_H
#define EDITOR_H

#include <vector>
#include "../raylib/src/raylib.h"

typedef unsigned char uint;

struct RGB {
    uint r;
    uint g;
    uint b;
    uint t; // transparency
};

class View {
    public:
    Vector2 offset;
    unsigned int zoom;
    View();
};

class ColorGrid {
    public:
    int w;
    int h;
    RGB** grid;
    ColorGrid(int width, int height);
    ~ColorGrid();
    void Render(View v);
    void HandleMouse(Vector2 pos, View v);
    void PlacePixel(int posy, int posx, RGB color);
    void PlaceLine(Vector2 pos, Vector2 oldpos, RGB color, View v);
};

#endif 