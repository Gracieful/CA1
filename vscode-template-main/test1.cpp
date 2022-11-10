#include "raylib.h"

int main()

/*
the code below will create a window on screen for a few seconds
*/ 
{
    /*Below "in width" and "int height" are variables*/
    int width {300};
    int height;
    height = 300;

    /* G window is an array called G Window */ 
    char WindowName[] = "G Window";

    /* if you put a number into the square brackets the array would know you're looking for number of Windownames. I.e char WindowName[5] = "name1,name2,name3,name4,name5". */
    /* you can call individuals from an array as well*/

   /* int WindowsArray [5]{50,25,35,100,69};
    InitWindow(WindowsArray[1],WindowsArray[5], "G Window"); */
   
    /* InitWindow is a function */
    InitWindow(width,height,WindowName);

/* 
the loop below will keep the window open but not give us an option to stop it. It will also give us a colour in the window. WindowShouldClose = when the window closes .
If you have (WindowShouldClose = (false)) it can also be written as (!WindowShouldClose())  
*/
    while (!WindowShouldClose())
    {
            BeginDrawing();
            ClearBackground(RED);
            SetTargetFPS(60);
    /* centerX and ceter Y are the co-ordinates for the shape you've drawn 
            int centerXText {25}; 
            int centerYText {25}; 
             DrawText("text", centerXText, centerYText, 40, GREEN);*/

     /* Below is code to draw a rectangle     
            int rectwidth {60};
            int rectheight {60};
            DrawRectangle(250, 150, rectwidth, rectheight, PURPLE);*/
           
     /* Below is code to draw a circle 
            int circleX {50}; 
            int circleY {50};
            int radius {10}; */  
     /*define color isn't working right now so I've commented it out
            #define BLUE(Color){100,79,75,100}; 

            DrawCircle(circleX, circleY, radius, BLUE);*/

     /* the circle is after the text so it'll appear on top of the text*/

    /*the IF statment below will make the circle move 10 every time you press D across the y axis
            if (IsKeyDown(KEY_D))
            {
                circleY = circleY + 100;
            }*/
    
        EndDrawing();
    }
} 
/* - NAOISES CODE THAT WORKS - 
#include "raylib.h"
int main(){
	int circle_posX = 250;
	int circle_posY = 250;
	int rect_posX = 400;
	int rect_posY = 400;
	int direction = 10;
InitWindow(500,500,"Naoise’s Window");
SetTargetFPS(60);  

	while(!WindowShouldClose()){
BeginDrawing();
ClearBackground(WHITE);    
DrawCircle(circle_posX,circle_posY, 50, BLUE); 
DrawRectangle(rect_posX,rect_posY, 50,50, RED);
if (IsKeyDown(KEY_D)&& circle_posX <500)
{
	circle_posX += 5;
}
if (IsKeyDown(KEY_A)&& circle_posX >0)
{
	circle_posX -= 5;
}
if (IsKeyDown(KEY_W))
{
	circle_posY -= 5;
}
if (IsKeyDown(KEY_S))
{
	circle_posY += 5;
}
 
rect_posY += direction;
if (rect_posY<0){
	direction *= -1;
}
if(rect_posY>400){
	direction *= -1;
}		
EndDrawing();
}
}

  */
 /*
    int centerX {100}; 
    centerX;

    int centerY {100};
    centerY; 

    int radius {200};
    radius; 

    DrawCircle(10, 10, 20, BLUE);

}
 
different data types are as follows
int: Whole numbers (1,2,300) 
char: Single letters or characters (a,t,h,!)
boolean: True or false values
float: decimal values of up to 7 points 
double: decimal value of up to 15 points (you don't always need double which is why it's handier to use floats. Float also saves on memory)
*/

/*
Variables are defined by 32 parts
it's name, value and type
These determine what can be done to a value. It doesn't matter what name or type it is, it's just a box to store values.

Variables must be delcared before use
e.g 
int numberofBalloons;
numofballoons = 9;

int = takes numbers;
numberofBalloons = name
numofballons = value

If you just write "int numberofBalloons" then it's unitialised 
once you create "numberofballoons = 6" then its initialised 

You can also write it as "int numberofBalloons{6}"

Expersions can also be used using the symbols below
== - equal to 
!= - notEqual to
< - less than 
> - greater than
<= - Lesser equal
>= - Greater equal

We use booleans when we want to create a certain level of conditions and rules. This will help make a loop 
below is an example of a loop
    int sheepeatenbywolf {99};
    while (sheepeatenbywolf>0);
    {
        printf(Om nom nom);
        sheepeatenbywolf = sheepeatenbywolf -1;
    } */

/* if the "while" part of the loop is kept empty or says "true" and nothing else then the loop will loop for ever and ever 

*/ 






