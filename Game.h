#pragma once


class GC_Scene{ /* Main scene class. Contains initialization and deinitialization funcs as well as general in-game functions */
public:
    virtual void Init() = 0;
    virtual void Display() = 0;
    virtual void Input() = 0;
    virtual void Misc() = 0;
    virtual void Deinit() = 0;
};


void GC_LoadScene(int m); // Load a scene
void GC_Display(); // Call the current scene's display function
void GC_Input(); // Call the current scene's input function
void GC_Misc(); // Call the current scene's miscellaneous function
void GC_InitSceneList(); // Initialize the list of scenes