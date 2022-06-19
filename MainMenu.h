#pragma once
#include "Game.h"

class MainMenu : public GC_Scene{
    public:
        void Init();
        void Display();
        void Input();
        void Misc();
        void Deinit();
};