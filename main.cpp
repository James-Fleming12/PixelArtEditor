#include "raylib/src/raylib.h"
#include "components/panels.h"
#include "components/editor.h"
#include <string>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pixel Art Editor");
    std::string pressed = "";
    float currentScroll;

    Vector2 mpos = {0,0};
    Vector2 oldPos = {0,0};

    Button test = Button(0, 0, 50, 20, "Hello", 16);
    Button test2 = Button(0, 0, 50, 20, "World", 16);
    Button main = Button(0, 0, 50, 20, "Menu", 16);
    ButtonContainer hotbar = ButtonContainer(0, 0, SCREEN_WIDTH, 30, 1, 5);
    ButtonContainer mainDrop = ButtonContainer(5, 35, 60, 200, 2, 5);
    hotbar.Add(main); 
    mainDrop.Add(test);
    mainDrop.Add(test2);
    mainDrop.render = false;

    ColorGrid grid = ColorGrid(SCREEN_WIDTH, SCREEN_HEIGHT);
    View v = View();

    while(!WindowShouldClose()) {
        currentScroll = GetMouseWheelMove();
        if (currentScroll != 0) {
            v.zoom += currentScroll;
            if (v.zoom < 1) {
                v.zoom = 1;
            }
        }
        if (IsMouseButtonDown(1)) {
            v.offset.x += mpos.x-GetMousePosition().x;
            v.offset.y += mpos.y-GetMousePosition().y;
        }
        mpos = GetMousePosition();
        if (IsMouseButtonDown(0)) {
            grid.PlacePixel((mpos.x+v.offset.x)/v.zoom, (mpos.y+v.offset.y)/v.zoom, {0, 0, 0, 255});
        }

        pressed = hotbar.DetectPress(mpos, IsMouseButtonDown(0));
        if (pressed != "") { // which button is pressed (based off of text within button)
            if (pressed == "Menu") {
                mainDrop.render = !mainDrop.render;
            }
            pressed = "";
        }
        if (mainDrop.render) {
            pressed = mainDrop.DetectPress(mpos, IsMouseButtonDown(0));
        }
        BeginDrawing();
            ClearBackground(RAYWHITE);
            grid.Render(v);
            grid.HandleMouse(mpos, v);
            hotbar.Render();
            if (mainDrop.render) { 
                mainDrop.Render(); 
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}