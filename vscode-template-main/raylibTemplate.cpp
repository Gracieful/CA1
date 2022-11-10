#include "raylib.h"

int main()
{

    InitWindow(250,250, "Grace is Testing");
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RED);
        SetTargetFPS(60);
    }

CloseWindow();
}
