#include "Track.h"
#include <iostream>

Track::Track(int v, int a, int WINDOWS_SIZE_X, int WINDOWS_SIZE_Y) 
{
  double radians = a * trackconstant::PI_180; 
  double t = 0;
  while(t < WINDOWS_SIZE_X) {
        
    int x = v * t * std::cos(radians);
    int y = -((v * t * std::sin(radians)) - (((t*t) * 9.8)/2));
    coordinates.push_back({x,y + WINDOWS_SIZE_Y});
    t += 0.1;

    if(y>0) {
      return;
    }
  }
 }

void Track::updateWithRender(SDL_Renderer *renderer)
{

    for (int i = 1; i < coordinates.size(); ++i){
      //SDL_RenderDrawPoint(renderer, i.x, i.y);
      SDL_RenderDrawLine(renderer, coordinates[i-1].x, coordinates[i-1].y, coordinates[i].x, coordinates[i].y);
    }
}

std::vector<Point> Track::GetCoorditnates()
{
  return coordinates;
}