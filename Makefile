CC=g++
CFLAGS=`sdl2-config --libs --cflags` -D_REENTRANT -O0 -Wall -lSDL2_image -lm
EXE=game

$(EXE):game.o main.o textureManager.o
	$(CC) textureManager.o main.o game.o -o $(EXE) $(CFLAGS)

game.o:game.cpp game.hpp textureManager.hpp
	$(CC) game.cpp -c -o game.o

main.o:main.cpp game.hpp
	$(CC) main.cpp -c -o main.o

textureManager.o:textureManager.cpp textureManager.hpp
	$(CC) textureManager.cpp -c -o textureManager.o

clean:
	rm $(EXE) *.o
