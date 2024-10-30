#include "editor.h"

View::View() {
    offset = {0, 0};
    zoom = 1;
}

ColorGrid::ColorGrid(int width, int height) {
    this->w = width;
    this->h = height;
    this->grid = new RGB*[height];
    for (int i = 0; i < h; i++) {
        grid[i] = new RGB[w];
        for (int j = 0; j < w; j++) {
            grid[i][j].r = 255;
            grid[i][j].g = 255;
            grid[i][j].b = 255;
            grid[i][j].t = 255;
        }
    }
}

ColorGrid::~ColorGrid() {
    for (int i = 0; i < h; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}

void ColorGrid::Render(View v) {
    for (int i = 0 ; i < h; i++) {
        for (int j = 0; j < w ; j++) {
            DrawRectangle(j*v.zoom-v.offset.x, i*v.zoom-v.offset.y, v.zoom, v.zoom,
                          (Color){grid[i][j].r, grid[i][j].g, grid[i][j].b, grid[i][j].t});
        }
    }
}

void ColorGrid::HandleMouse(Vector2 pos, View v) {
    int xIndex = (pos.x+v.offset.x)/v.zoom;
    int yIndex = (pos.y+v.offset.y)/v.zoom;
    DrawRectangleLines(xIndex*v.zoom-v.offset.x, yIndex*v.zoom-v.offset.y, 
                       v.zoom, v.zoom, BLACK);
}

void ColorGrid::PlacePixel(Vector2 pos, RGB color) {
    this->grid[int(pos.y)][int(pos.x)] = color;
}