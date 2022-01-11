#include <iostream>
#include <memory>
#include "GDI.h"
#include "Track.h"
#include "Ball.h"

namespace ballconstant 
{
 const int WINDOWS_SIZE_X = 400; 
 const int WINDOWS_SIZE_Y = 300;
}

int main(int argc, char* argv[])
{
    int ang = 30; // const
    int v = 60; // const
    for (int i = 0; i < argc; ++i) {
      std::string str (argv[i]);
      if(!str.compare("-ang")) {
        std::string str1 (argv[i+1]);
        ang = std::stoi( str1 );      
        std::cout << ang << std::endl;
      }
      if(!str.compare("-v")) {
        std::string str1 (argv[i+1]);
        v = std::stoi( str1 );     
        std::cout << v << std::endl;
      }
    }

    ObjectManager objectManager;
    std::shared_ptr<Track> track = std::make_shared<Track>(Track(v, ang, ballconstant::WINDOWS_SIZE_X, ballconstant::WINDOWS_SIZE_Y));
    objectManager.addObject(track.get());
    std::shared_ptr<Ball> ball = std::make_shared<Ball>(Ball(track->GetCoorditnates()));
    objectManager.addObject(ball.get());
    GDI gdi= GDI(ballconstant::WINDOWS_SIZE_X, ballconstant::WINDOWS_SIZE_Y, objectManager);

    gdi.RunLoop();
    return 0;
}
