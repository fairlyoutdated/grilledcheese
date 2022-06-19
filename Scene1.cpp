#include "Scene1.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bacteria = 0;

int level[144]; // This is the level grid. 1=block 0=air.

int origlevel[]= {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 
        0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
        1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 1, 1, 1, 
        2, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 1, 1, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 
    };
int lx = 16; // Level Width
int ly = 9; // Level Height

float playerx = 600, playery = 0; // Player position

float jetpack = 0; // Jetpack velocity

float jetpackmax = 3;

float playerspeed = 150;

float gravity = 0; // Gravity velocity

int ground = 710;

int ceiling = 0;

int left = 0;
int right = 1280;

bool grounded = false;

bool flying = false; // Checks if player is flying

bool floor_colmatch = false; // used for collision detection with platforms

bool ceiling_colmatch = false;

bool left_colmatch = false;
bool right_colmatch = false;

void Scene1::Init(){
    bacteria = 0;
    memcpy(level, origlevel, sizeof origlevel);
     // This is the level grid. 1=block 0=air.
    lx = 16; // Level Width
    ly = 9; // Level Height

    playerx = 600, playery = 0; // Player position

    jetpack = 0; // Jetpack velocity

    jetpackmax = 3;

    playerspeed = 150;

    gravity = 0; // Gravity velocity

    ceiling = 0;

    ground = 710; // Ground level

    left = 0;
    right = 1280;

    grounded = false; // Check if player is on the ground

    flying = false; // Checks if player is flying

    floor_colmatch = false; // used for collision detection with platforms

    left_colmatch = false;
    right_colmatch = false;
}

void Scene1::Display(){
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText(TextFormat("Bacteria collected: %i", bacteria), 0, 0, 30, YELLOW);
    DrawFPS(0,60);
    // DrawText("GRILLED CHEESE", 0, 0, 20, WHITE);

    /* Render Level */

    for(int y = 0; y < ly; y++){
        for(int x = 0; x < lx; x++){
            if(level[y*lx + x] == 1) DrawRectangle(x*80, y*80, 80, 80, GRAY); // Platforms
            if(level[y*lx + x] == 2) DrawRectangle(x*80, y*80, 80, 80, GREEN); // Bacteria
        }
    }

    DrawCircle(playerx, playery, 30, WHITE);
    EndDrawing();
}

void Scene1::Input(){
    if(IsKeyDown(KEY_W) && jetpack < jetpackmax) jetpack += GetFrameTime();
    if((!IsKeyDown(KEY_W) || jetpack >= jetpackmax) && jetpack > 0) jetpack -= GetFrameTime();
    flying = IsKeyDown(KEY_W);
    //if(IsKeyDown(KEY_S)) playery++;
    if(IsKeyDown(KEY_A)) playerx -= playerspeed * GetFrameTime();
    if(IsKeyDown(KEY_D)) playerx += playerspeed * GetFrameTime();
    if(IsKeyPressed(KEY_ESCAPE)) GC_LoadScene(0);

    
}

void Scene1::Misc(){
    /* Player movement physics */
    playery-=jetpack;

    if(jetpack < 0) jetpack = 0;
    // printf("%f\n", jetpack);
    if(!flying)gravity+=GetFrameTime();
    if(gravity > 0 && flying) gravity -= GetFrameTime();
    
    if(playery >= ground) grounded = true;
    else grounded = false;
    
    if(gravity < 0 || grounded) gravity = 0; 
    playery+=gravity;

    if(playery > 720) playery = 720; 
    if(playery < ceiling) playery = ceiling;
    if(playerx < left) playerx = left;
    if(playerx > right) playerx = right;   

    /* level collisions */
    for(int y = 0; y < ly; y++){
        for(int x = 0; x < lx; x++){
            if(level[y*lx + x] == 1 && (int)playerx/80 == x && (int)(playery/80)+1 == y) {
                ground = (y*80)-10;
                floor_colmatch = true;
            }
            if(level[y*lx + x] == 1 && (int)playerx/80 == x && (int)(playery/80)-1 == y) {
                ceiling = ((y+1)*80+10);
                ceiling_colmatch = true;
            }
            if(level[y*lx + x] == 2 && (int)playerx/80 == x && (int)(playery/80) == y) {
                level[y*lx + x] = 0;
                bacteria++;
                // floor_colmatch = true;
            }

            if(level[y*lx + x] == 1 && (int)(playerx/80)-1 == x && (int)(playery/80) == y) {
                left = ((x+1)*80)+10;
                left_colmatch = true;
            }
            if(level[y*lx + x] == 1 && (int)(playerx/80)+1 == x && (int)(playery/80) == y) {
                right = ((x)*80-10);
                right_colmatch = true;
            }
        }
    }
    if(!floor_colmatch) ground = 710;
    if(!ceiling_colmatch) ceiling = 0;
    if(!left_colmatch) left = 0;
    if(!right_colmatch) right = 1280;

    floor_colmatch = false;
    ceiling_colmatch = false;
    left_colmatch = false;
    right_colmatch = false;
}

void Scene1::Deinit(){
    // There is nothing to deinitialize.
}