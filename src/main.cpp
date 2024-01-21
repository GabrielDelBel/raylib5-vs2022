#include "raylib.h"
#include "Math.h"
#include<iostream>

const int LEGS_COUNT = 4;

 class Table 
{
public: // makes all following variables public
    float x, y;
    float width, height;
    float weight;
    float legs[LEGS_COUNT];
    float legWidth, legHeight;
    Color colour;
    Color red;
    Color green;

    void DrawTable() //Class method can use variables in the class
    {
        // top
        DrawRectangle(x,y,width,height, colour);
        for (int i = 0; i < LEGS_COUNT; i++)
        {
            DrawRectangle(legs[i], y, legWidth, legHeight, BROWN);
        }
    }
};

int main()
{

    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window"); // Command creates window, requires raylib.h
    SetTargetFPS(60); // sets target fps, uses raylib.h

    Table woodTable;
    woodTable.height = 60.0f;
    woodTable.width = 140.0f;
    woodTable.x = screenWidth / 2.0f - woodTable.width/ 2.0f;
    woodTable.y = screenHeight * 0.75f - woodTable.height;
    woodTable.colour = GRAY;
    woodTable.legHeight = woodTable.height * 3.0f;
    woodTable.legWidth = 10.0f;

    woodTable.legs[0] = woodTable.x;
    woodTable.legs[1] = woodTable.x + woodTable.legWidth * 3.0f;
    woodTable.legs[2] = woodTable.x + woodTable.width - (woodTable.legWidth * 3.0f);
    woodTable.legs[3] = woodTable.x + woodTable.width - (woodTable.legWidth);


    const char* sentence = "asgudgywaugd"; // C string, draw text uses c strings instead of string

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(RAYWHITE); //Don't need rgb values if existing colour is written.
        DrawText(sentence, screenWidth/2.0f, screenHeight/2.0f,20, YELLOW);
        woodTable.DrawTable();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
