#pragma once
#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>

struct Point {
  int x, y;
};

class Drawable 
{
  public:
    virtual void updateWithRender(SDL_Renderer* renderer);
};