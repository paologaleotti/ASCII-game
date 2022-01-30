all: MainLoop.o main.o
	g++ -o main.out MainLoop.o main.o -lncurses

main.o: src/main.cpp
	g++ -c src/main.cpp -lncurses

MainLoop.o: src/MainLoop.cpp src/MainLoop.hpp
	g++ -c src/MainLoop.cpp -lncurses

clean:
	rm *.o main.out