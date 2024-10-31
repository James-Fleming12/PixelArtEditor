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

void ColorGrid::PlacePixel(int posx, int posy, RGB color) {
    this->grid[posy][posx] = color;
}

void ColorGrid::PlaceLine(Vector2 pos, Vector2 pos2, RGB color, View v) {
    pos.x = (pos.x+v.offset.x)/v.zoom;
    pos.y = (pos.y+v.offset.y)/v.zoom;
    pos2.x = (pos2.x+v.offset.x)/v.zoom;
    pos2.y = (pos2.y+v.offset.y)/v.zoom;
    int m_new = 2 * (pos2.y - pos.y);
    int slope_error_new = m_new - (pos2.x - pos.x); 
    for (int curr_x = pos.x, curr_y = pos.y; curr_x <= pos2.x; curr_x++) {
        PlacePixel(curr_x, curr_y, color);
        slope_error_new += m_new;
        if (slope_error_new >= 0) { 
            curr_y++; 
            slope_error_new -= 2 * (pos2.x - pos.x); 
        }
    } 
}