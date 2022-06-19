#include <raylib.h>
#include <iostream>
#include "Game.h"

int main(){
    InitWindow(1280, 720, "Grilled Cheese"); // Initialize Window
    SetTargetFPS(120); // Set Target FPS
    GC_InitSceneList(); // Initialize list of all Grilled Cheese scenes
    GC_LoadScene(0); // Load scene 0
    while(!WindowShouldClose()){
        SetExitKey(0);
        GC_Display();
        GC_Input();
        GC_Misc();
    }

}