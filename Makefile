main: MainLoop.o
	g++ -o main.out MainLoop.o

MainLoop.o: src/MainLoop.cpp src/MainLoop.hpp
	g++ -c src/MainLoop.cpp -lncurses

clean:
	rm *.o main.out