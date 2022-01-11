#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>

#include "ObjectManager.h"

class GDI 
{
  private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool windowReady;
    ObjectManager objectManager;

  public:
    GDI(int WINDOWS_SIZE_X, int WINDOWS_SIZE_Y, ObjectManager objMngr);
    ~GDI();

    bool isWindowReady();

    void RunLoop();
};