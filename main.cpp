#include "raylib/src/raylib.h"
#include "components/panels.h"
#include <string>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pixel Art Editor");
    std::string pressed = "";
    bool HelloToggle = false; // for testing
    bool WorldToggle = false; // for testing

    Button test = Button(0, 0, 50, 20, "Hello", 16);
    Button test2 = Button(0, 0, 50, 20, "World", 16);
    ButtonContainer hotbar = ButtonContainer(0, 0, SCREEN_WIDTH, 30, 1, 5);
    hotbar.Add(test); 
    hotbar.Add(test2);

    while(!WindowShouldClose()) {
        pressed = hotbar.DetectPress(GetMousePosition(), IsMouseButtonDown(0));
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
            hotbar.Render();
            if (HelloToggle) { DrawText("Hello", 10, 35, 10, BLACK); }
            if (WorldToggle) { DrawText("World", 40, 35, 10, BLACK); }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}