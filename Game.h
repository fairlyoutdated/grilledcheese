#pragma once


class GC_Scene{
public:
    virtual void Display() = 0;
    virtual void Input() = 0;
    virtual void Misc() = 0;
};


void GC_LoadScene(int m);
void GC_Display();
void GC_Input();
void GC_Misc();
void GC_InitSceneList();