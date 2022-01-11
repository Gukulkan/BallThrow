#include "Ball.h"
#include <iostream>

Ball::Ball(const std::vector<Point>& crdnts) 
: index(0) 
, rerenderIndex(0)
, coordinates(crdnts)
{
}

void Ball::updateWithRender(SDL_Renderer *renderer)
{
    auto radius =  ballconstant::radius;
    auto squareRadius = radius * radius;
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; 
            int dy = radius - h; 
            if ((dx*dx + dy*dy) <= squareRadius)
            {
                SDL_RenderDrawPoint(renderer, coordinates[index].x + dx, coordinates[index].y + dy);
            }
        }
    }
    ++rerenderIndex;
    if(rerenderIndex == ballconstant::speed) {
      ++index;
      rerenderIndex = 0;
    }

    if(index >= coordinates.size()){
      index=0;
    }
}