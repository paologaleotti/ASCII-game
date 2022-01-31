OBJS = main.o Graphics.o
OUT = main.out

all: $(OBJS)
	g++ -o $(OUT) $(OBJS) -lncurses

main.o: src/main.cpp
	g++ -c src/main.cpp -lncurses

Graphics.o: src/Graphics.cpp src/Graphics.hpp
	g++ -c src/Graphics.cpp -lncurses

clean:
	rm -f $(OBJS) $(OUT)