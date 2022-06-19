#include <raylib.h>
#include <iostream>
#include "Game.h"

int main(){
    InitWindow(1280, 720, "Grilled Cheese");
    SetTargetFPS(120);
    GC_InitSceneList();
    while(!WindowShouldClose()){
        GC_Display();
        GC_Input();
        GC_Misc();
    }

}