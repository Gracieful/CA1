#include "raylib.h"

int main()
{
/* -- Variables -- */
    int screenwidth = 800;
    int screenheight = 800;
    int circle_posX = 400;
	int circle_posY = 750;
    int radius = 50;
	int rect_posX = 0;
	int rect_posY = 590;
    int rect_posXD = 0;
    int rect_posYD = 590;
	int directionB = 5;
    int directionA = 15;
    bool collision{};


 /*  DrawRectangle(screenwidth/2,posY,width,height,GREEN);*/

    InitWindow(screenwidth,screenheight,"G Window");
    InitAudioDevice();
    SetTargetFPS(60);  

/* -- audio -- */
    Sound ribbit = LoadSound("./Audio/croak.mp3");
    Sound backgroundnoise = LoadSound("./Audio/Background_noise.mp3");

/* -- code to call the texture --*/

    Texture2D frog = LoadTexture("./Textures/frog-sprite-backup.png");
    Texture2D background = LoadTexture("./Textures/background.png");
    Texture2D carA = LoadTexture("./Textures/tester_Car.png");
    Texture2D carB = LoadTexture("./Textures/tester_Car.png");
    Texture2D carC = LoadTexture("./Textures/tester_Car.png");
    Texture2D carD = LoadTexture("./Textures/tester_Car.png");

    Rectangle frogRec;
    Rectangle carARec;
    Rectangle carBRec;
    Rectangle carCRec;
    Rectangle carDRec;


/* -- this will block out the sprites you don't want --*/

 /*--   float frameHeight = (float)(frog.width/8.8); Commenting out as it wasn't blocking the image correctly. Assuming it's because the image wasn't divisable by 8(the amoun of images) --*/

    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(GREEN); 

        PlaySound(backgroundnoise);

        DrawTexture(background,0,(screenheight-background.height),BROWN);

        DrawText("Score", 100,100, 20, BLACK);

/*-- Code to create the frog --*/

        DrawTexture(frog,circle_posX,circle_posY,YELLOW);

/* -- Circle code  
        DrawCircle(circle_posX, circle_posY, radius, GREEN); --*/

/* -- frog movement --*/
        if (IsKeyDown(KEY_D)&& circle_posX <(screenwidth-frog.width))
            {
	            circle_posX += 5;
            }
        if (IsKeyDown(KEY_A)&& circle_posX >0)
            {
	            circle_posX -= 5;
            }
        if (IsKeyDown(KEY_W)&& circle_posY >0)
            {
	            circle_posY -= 5;
                PlaySound(ribbit);
            }
        if (IsKeyDown(KEY_S)&& circle_posY <(screenheight-frog.height))
            {
	            circle_posY += 5;
                PlaySound(ribbit);
            }

        
 /* -- car A -- */
 
        DrawTexture(carA,(rect_posX),(rect_posY),RAYWHITE);

        rect_posX += directionB;
        if (rect_posX<(-20))
        {
	        directionB *= -1;
        }
        if(rect_posX>(screenwidth-carA
        .width))
        {
	        rect_posX = -19;
        }

/* -- car B -- */

        DrawTexture(carB,(rect_posXD),(rect_posYD+(radius*-2)),RAYWHITE);

        rect_posXD += directionA;
        if (rect_posXD<(-20))
        {
	        directionA *= -1;
        }
        if(rect_posXD>(screenwidth-carB.width))
        {
	        rect_posXD = (-(carB.width/2));
        }

/* -- car C -- */

        DrawTexture(carC,(rect_posX),(rect_posY+(radius*-4)),RAYWHITE);

        rect_posX += directionB;
        if (rect_posX<(-20))
        {
	        directionB *= -1;
        }
        if(rect_posX>(screenwidth-carC.width))
        {
	        rect_posX = -19;
        }

/*-- car D --*/

        DrawTexture(carD,(rect_posXD),(rect_posYD+(radius*-6)),RAYWHITE);

        rect_posXD += directionA;
        if (rect_posXD<(-20))
        {
	        directionA *= -1;
        }
        if(rect_posXD>(screenwidth-carD.width))
        {
	        rect_posXD = (-(carD.width/2));
        }

/*--collosion code--*/



    EndDrawing();
}


CloseAudioDevice();
CloseWindow();

return 0;
}




