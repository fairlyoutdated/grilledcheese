#include "MainMenu.h"
#include <raylib.h>
#include <iostream>
#include "Game.h"


int selection = 0;


void MainMenu::Init(){

    // Nothing much to initialize...

}

void MainMenu::Display(){
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Grilled Cheese", 0, 0, 72, WHITE);
    switch(selection){
        case -1:
            selection = 2;
            break;
        case 0:
            DrawText("W/S on QWERTY, Z/S on AZERTY", 0,80, 30, YELLOW);
            break;
        case 1:
            DrawText("Play", 0,80, 30, GREEN);
            break;
        case 2:
            DrawText("Quit", 0,80, 30, RED);
            break;
        case 3:
            selection = 0;
            break;
    }
    EndDrawing();
}

void MainMenu::Input(){
    if(IsKeyPressed(KEY_W)) selection--;
    if(IsKeyPressed(KEY_S)) selection++;
    if(IsKeyPressed(KEY_ENTER)){
        switch(selection){
            case 1:
                GC_LoadScene(1);
                break;
            case 2:
                _exit(0);
                break;
        }
    }
}

void MainMenu::Misc(){}
void MainMenu::Deinit(){}