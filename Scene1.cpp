#include "Scene1.h"
#include <raylib.h>

float playerx = 600, playery = 0;

float jumpforce = 0;

float gravity = 0;

void Scene1::Display(){
    BeginDrawing();
    ClearBackground(BLACK);
    // DrawText("GRILLED CHEESE", 0, 0, 20, WHITE);
    DrawCircle(playerx, playery, 30, WHITE);
    EndDrawing();
}

void Scene1::Input(){
    if(IsKeyDown(KEY_W)) playery--;
    if(IsKeyDown(KEY_S)) playery++;
    if(IsKeyDown(KEY_A)) playerx--;
    if(IsKeyDown(KEY_D)) playerx++;

    
}

void Scene1::Misc(){
    
    
}