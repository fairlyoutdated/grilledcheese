@echo off

REM Change "G:/cpp/mingw64/include" and "G:/cpp/mingw64/lib" to your include and lib paths.

g++ main.cpp Game.cpp SoloLevel1.cpp MainMenu.cpp Splash.cpp -o grilledcheese -I"G:/cpp/mingw64/include" -L"G:/cpp/mingw64/lib" -lraylib -lm -lwinmm -lgdi32