#include "raylib/src/raylib.h"
#include "components/panels.h"

int main(void) {
    InitWindow(800, 450, "Pixel Art Editor");
    
    Button test = Button(30, 30, 50, 20, "Hello", 16);

    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            test.Render();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}