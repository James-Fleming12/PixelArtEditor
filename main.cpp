#include "raylib/src/raylib.h"
#include "components/panels.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pixel Art Editor");
    bool pressed = false;

    Button test = Button(0, 0, 50, 20, "Hello", 16);
    Button test2 = Button(0, 0, 50, 20, "World", 16);
    ButtonContainer hotbar = ButtonContainer(0, 0, SCREEN_WIDTH, 30, 1, 5);
    hotbar.Add(test);
    hotbar.Add(test2);

    while(!WindowShouldClose()) {
        pressed = hotbar.DetectPress(GetMousePosition(), IsMouseButtonDown(0));

        BeginDrawing();
            ClearBackground(RAYWHITE);
            hotbar.Render();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}