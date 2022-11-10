#include "raylib.h"

int main()
{
    const int windowWidth = {400};
    const int windowHeight = {400};


    InitWindow(250,250, "Grace is Testing");

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RED);
        SetTargetFPS(60);


        Texture2D scarfy = LoadTexture("resources/scarfy.png");
        Rectangle scarfyRec;
        scarfyRec.width = scarfy.width/6;
        scarfyRec.height = scarfy.height;
        scarfyRec.x = 0;
        scarfyRec.y = 0; 
        Vector2 scarfyPos;
        scarfyPos.x = windowWidth/2 - scarfyRec.width/2;
        scarfyPos.y = windowHeight - scarfyRec.height;

        DrawTextureRec(scarfy, scarfyRec,scarfyPos, WHITE);
    
    UnloadTexture(scarfy);
    EndDrawing();
    }

CloseWindow();
}
