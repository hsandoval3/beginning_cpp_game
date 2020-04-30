main: main.o game.o
	g++ main.o game.o -o main -lSDL2

main.o: main.cpp
	g++ -c main.cpp

game.o: game.cpp
	g++ -c game.cpp

.PHONY: clean
clean:
	rm *.o main
