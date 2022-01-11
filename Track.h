#include <vector>
#include "Drawable.h"

namespace trackconstant 
{
  const double PI_180 = 3.14159/180;
}

class Track: public Drawable 
{
  private:
    std::vector<Point> coordinates; 

  public:
    Track(int v, int a, int WINDOWS_SIZE_X, int WINDOWS_SIZE_Y);
    void updateWithRender(SDL_Renderer* renderer) override;
    std::vector<Point> GetCoorditnates();
};