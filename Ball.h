#include <vector>
#include "Drawable.h"

namespace ballconstant 
{
  const int radius = 3;
  const int speed = 10;
}

class Ball: public Drawable 
{
  private:
    std::vector<Point> coordinates;
    int index;
    int rerenderIndex;

  public:
    Ball(const std::vector<Point>& coordinates); 
    void updateWithRender(SDL_Renderer* renderer) override;
};