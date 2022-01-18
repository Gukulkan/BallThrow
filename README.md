# BallThrow

Project was builded for testing physics teory.

![Alt Text](https://github.com/Gukulkan/BallThrow/blob/c3dfe52f5922a3a99682f9b848a196002e03cf98/2022-01-18%2018.25.22.gif)


The main task was:
* We have a ball
* with trow this ball with angle and speed
* should be animated
* should show trajectory 
* angle and speed could be seted up from command line

You can run and test it build

`g++ -o main Game.cpp GDI.cpp ObjectManager.cpp Track.cpp Drawable.cpp Ball.cpp -lSDL2 -lSDL2main`

and run 

`./main`
