.PHONY: run

run: main.o
	./main

main.o:
	g++ -o main Game.cpp GDI.cpp ObjectManager.cpp Track.cpp Drawable.cpp Ball.cpp -lSDL2 -lSDL2main
 
