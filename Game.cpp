#include "Game.h"
#include "Scene1.h"
#include <vector>

int Scene = 0;

std::vector<GC_Scene*> SceneList;

void GC_LoadScene(int m){
    Scene = m;
}

void GC_InitSceneList(){
    
    SceneList.push_back(new Scene1());
}

void GC_Display(){
    SceneList.at(Scene)->Display();
}

void GC_Input(){
    SceneList.at(Scene)->Input();
}

void GC_Misc(){
    SceneList.at(Scene)->Misc();
}