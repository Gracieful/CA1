#include "raylib.h"

int main()
{
/* -- Variables -- */
    const int screenwidth(800);
    const int screenheight(800);
    int circle_posX = 400;
	int circle_posY = 750;
    int radius = 50;
	int rect_posX = 0;
	int rect_posY = 590;
    int rect_posXD = 0;
    int rect_posYD = 590;
	int directionB = 5;
    int directionA = 15;
    int velocity(10);
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
    Texture2D carA = LoadTexture("./Textures/car_A.png");
    Texture2D carB = LoadTexture("./Textures/car_A.png");
    Texture2D carC = LoadTexture("./Textures/car_A.png");
    Texture2D carD = LoadTexture("./Textures/car_A.png");

/* -- Below is the variables for the frog character -- */
    
    Rectangle frogRec;
/*-- keeping the wdith and height equal as there is currently no sprites --*/
    frogRec.width = frog.width;
    frogRec.height = frog.height;
    frogRec.x = 0;
    frogRec.y = 0;

    Vector2 frogPos; 
    frogPos.x = circle_posX;
    frogPos.y = circle_posY;

/* -- Below is the variables for car A. If this works I'll be apply to other cars-- */

    Rectangle carARec;
    carARec.width = carA.width;
    carARec.height = carB.height;
    carARec.x = 0;
    carARec.y = 0;

    Vector2 carAPos;
    carAPos.x = rect_posX; 
    carAPos.y = rect_posY;


 /*--   float frameHeight = (float)(frog.width/8.8); Commenting out as it wasn't blocking the image correctly. Assuming it's because the image wasn't divisable by 8(the amoun of images) --*/

    while(!WindowShouldClose())
    {
/* -- This is the code to get the window running and to load everything -- */
        BeginDrawing();

        ClearBackground(WHITE); 

        DrawTexture(background,0,(screenheight-background.height),GREEN);
/*
        DrawText("Score", 100,100, 20, BLACK); - commented out to test debug is picking up most recent revision
*/
        PlaySound(backgroundnoise);

/* -- delta time can be used to to make easier animations by using the frame time -- */
        const float deltaTime{GetFrameTime()};

/* -- Below is the code to make the collison box code. When the boxes collide the if collision statement should apply. 
These variables need to be after the while statment to keep it constant -- */

        Rectangle froggieRec 
        {
            frogPos.x,
            frogPos.y,
            frogRec.height,
            frogRec.width,
        };

        Rectangle carAcrashRec 
        {
            carAPos.x,
            carAPos.y,
            carARec.height,
            carARec.width,
        };

        if (CheckCollisionRecs(froggieRec,carAcrashRec))
        {
            collision = true;
        }

/*-- Code to create the frog --*/

        DrawTexture(frog,frogRec,frogPos,YELLOW);


/* -- Circle code  this was used to test before importing sprites 
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
        DrawTexture(carA,(rect_posX),(rect_posY+(radius*-4)),WHITE);

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

        DrawTexture(carB,(rect_posXD),(rect_posYD+(radius*-8)),GREEN);

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

        DrawTexture(carC,(rect_posX),(rect_posY+(radius*-4)),PINK);

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

        DrawTexture(carD,(rect_posXD),(rect_posYD+(radius*-6)),RED);

        rect_posXD += directionA;
        if (rect_posXD<(-20))
        {
	        directionA *= -1;
        }
        if(rect_posXD>(screenwidth-carD.width))
        {
	        rect_posXD = (-(carD.width/2));
        }

/*--collosion code. You need to keep the textures in the else part of the statement as "if(collsiion)" is when collision is true--*/
        if (collision)
        {

        DrawTexture(frog,frogRec,frogPos,RED);

        }
        else
        {

        DrawTexture(frog,frogRec,frogPos,YELLOW);
        DrawTexture(carA,(rect_posX),(rect_posY+(radius*-4)),WHITE);
        DrawTexture(carB,(rect_posXD),(rect_posYD+(radius*-8)),GREEN);
        DrawTexture(carC,(rect_posX),(rect_posY+(radius*-4)),PINK);
        DrawTexture(carD,(rect_posXD),(rect_posYD+(radius*-6)),RED);


        }


    EndDrawing();
}

UnloadTexture(frog);
UnloadTexture(carA);
UnloadTexture(carB);
UnloadTexture(carC);
UnloadTexture(carD);
CloseAudioDevice();
CloseWindow();

return 0;
}




