#pragma once

#include <SDL/SDL.h>

typedef struct Input Input;
struct Input
{
    bool key[SDLK_LAST];
    int mousex,mousey;
    int mousexrel,mouseyrel;
    bool mousebuttons[8];
    bool quit;
};

void updateEvents(Input *in);