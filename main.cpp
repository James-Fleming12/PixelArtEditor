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
    bool HelloToggle = false; // for testing
    bool WorldToggle = false; // for testing

    Vector2 mpos = {0,0};
    Vector2 oldPos = {0,0};

    Button test = Button(0, 0, 50, 20, "Hello", 16);
    Button test2 = Button(0, 0, 50, 20, "World", 16);
    ButtonContainer hotbar = ButtonContainer(0, 0, SCREEN_WIDTH, 30, 1, 5);
    hotbar.Add(test); 
    hotbar.Add(test2);

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
            grid.PlaceLine(mpos, oldPos, {0, 0, 0, 255}, v);
        }

        pressed = hotbar.DetectPress(mpos, IsMouseButtonDown(0));
        if (pressed != "") { // which button is pressed (based off of text within button)
            if (pressed == "Hello") {
                HelloToggle = !HelloToggle;
            }
            if (pressed == "World") {
                WorldToggle = !WorldToggle;
            }
            pressed = "";
        }
        BeginDrawing();
            ClearBackground(RAYWHITE);
            grid.Render(v);
            grid.HandleMouse(mpos, v);
            hotbar.Render();
            if (HelloToggle) { DrawText("Hello", 10, 35, 10, WHITE); }
            if (WorldToggle) { DrawText("World", 40, 35, 10, WHITE); }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}