#pragma once
#include "Game.h"

class Scene1 : public GC_Scene{
    public:
        void Init();
        void Display();
        void Input();
        void Misc();
        void Deinit();
};