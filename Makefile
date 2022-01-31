OBJS = main.o MainLoop.o
OUT = main.out

all: $(OBJS)
	g++ -o $(OUT) $(OBJS) -lncurses

main.o: src/main.cpp
	g++ -c src/main.cpp -lncurses

MainLoop.o: src/MainLoop.cpp src/MainLoop.hpp
	g++ -c src/MainLoop.cpp -lncurses

clean:
	rm -f $(OBJS) $(OUT)