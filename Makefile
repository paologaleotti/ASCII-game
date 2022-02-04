OBJS = main.o Graphics.o Entity.o Player.o Room.o MapGen.o
OUT = main.out

all: $(OBJS)
	g++ -o $(OUT) $(OBJS) -lncurses

main.o: src/main.cpp
	g++ -c src/main.cpp -lncurses

Graphics.o: src/Graphics.cpp src/Graphics.hpp
	g++ -c src/Graphics.cpp -lncurses

Entity.o: entities/Entity.cpp entities/Entity.hpp
	g++ -c entities/Entity.cpp -lncurses

Player.o: entities/Player.cpp entities/Player.hpp
	g++ -c entities/Player.cpp -lncurses

Room.o: room/Room.cpp room/Room.hpp
	g++ -c room/Room.cpp -lncurses

MapGen.o: map/MapGen.cpp map/MapGen.hpp
	g++ -c map/MapGen.cpp -lncurses

Memory.o: map/Memory.cpp map/Memory.hpp
	g++ -c map/Memory.cpp -lncurses

clean:
	rm -f $(OBJS) $(OUT)