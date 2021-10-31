CC=g++
CFLAGS=`sdl2-config --libs --cflags` -D_REENTRANT -O0 -Wall -lSDL2_image -lm
EXE=game

$(EXE):game.o main.o
	$(CC) main.o game.o -o $(EXE) $(CFLAGS)

game.o:game.cpp game.hpp
	$(CC) game.cpp -c -o game.o

main.o:main.cpp game.hpp
	$(CC) main.cpp -c -o main.o

clean:
	rm $(EXE) *.o
