#include "raylib/src/raylib.h"
#include "components/panels.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pixel Art Editor");
    
    Button test = Button(30, 30, 50, 20, "Hello", 16);
    bool pressed = false;

    while(!WindowShouldClose()) {
        pressed = test.DetectPress(GetMousePosition(), IsMouseButtonDown(0));

        BeginDrawing();
            ClearBackground(RAYWHITE);
            test.Render();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}