#include "events.hpp"

void updateEvents(Input *in)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
                in->key[event.key.keysym.sym] = true;
                break;
            case SDL_KEYUP:
                in->key[event.key.keysym.sym] = false;
                break;
            case SDL_MOUSEMOTION:
                in->mousex=event.motion.x;
                in->mousey=event.motion.y;
                in->mousexrel=event.motion.xrel;
                in->mouseyrel=event.motion.yrel;
                break;
            case SDL_MOUSEBUTTONDOWN:
                in->mousebuttons[event.button.button] = true;
                break;
            case SDL_MOUSEBUTTONUP:
                in->mousebuttons[event.button.button] = false;
                break;
            case SDL_QUIT:
                in->quit = true;
                break;
            default:
                break;
        }
    }
}