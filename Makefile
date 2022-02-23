OBJS = main.o Graphics.o Entity.o Player.o Enemy.o Room.o MapGen.o Memory.o Combat.o Pickups.o
OUT = main.out

all: $(OBJS)
	g++ -o $(OUT) $(OBJS) -lncurses

main.o: src/main.cpp
	g++ -c src/main.cpp -lncurses

Graphics.o: graphics/Graphics.cpp graphics/Graphics.hpp
	g++ -c graphics/Graphics.cpp -lncurses

Entity.o: entities/Entity.cpp entities/Entity.hpp
	g++ -c entities/Entity.cpp

Player.o: entities/Player.cpp entities/Player.hpp
	g++ -c entities/Player.cpp -lncurses

Enemy.o: entities/Enemy.cpp entities/Enemy.hpp
	g++ -c entities/Enemy.cpp -lncurses

Room.o: room/Room.cpp room/Room.hpp
	g++ -c room/Room.cpp

MapGen.o: map/MapGen.cpp map/MapGen.hpp
	g++ -c map/MapGen.cpp

Memory.o: map/Memory.cpp map/Memory.hpp
	g++ -c map/Memory.cpp -lncurses

Combat.o: combat/Combat.cpp combat/Combat.hpp
	g++ -c combat/Combat.cpp

Pickups.o: pickups/Pickups.cpp pickups/Pickups.hpp
	g++ -c pickups/Pickups.cpp

clean, clear:
	rm -f $(OBJS) $(OUT)