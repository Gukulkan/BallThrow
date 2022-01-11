#include "GDI.h"
#include "Drawable.h" 

GDI::GDI(int WINDOWS_SIZE_X, int WINDOWS_SIZE_Y, ObjectManager objMngr) 
{
  if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        window = NULL;
        renderer = NULL;
        windowReady = SDL_CreateWindowAndRenderer(WINDOWS_SIZE_X, WINDOWS_SIZE_Y, 0, &window, &renderer) == 0;
        objectManager = objMngr;
  }
}

GDI::~GDI() 
{
    if (renderer) {
      SDL_DestroyRenderer(renderer);
    }
    if (window) {
       SDL_DestroyWindow(window);
    }
    SDL_Quit();
}

void GDI::RunLoop()
{
  SDL_bool done = SDL_FALSE;

  while (!done) {
    SDL_Event event;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    
    for (Drawable* obj : objectManager.getDrawableObjects()) 
    {
      obj->updateWithRender(renderer);
    }

    SDL_RenderPresent(renderer);

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = SDL_TRUE;
      }
    }
  }
}

bool GDI::isWindowReady() 
{
  return windowReady;
}