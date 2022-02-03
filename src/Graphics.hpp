#include "../entities/Player.hpp"
#include <ncurses.h>

#define AIR 0
#define PLAYER 1
#define WALL 2
#define ENEMY 3
#define DOOR_EXIT 4 
#define DOOR_BACK 5

class MainWindow {
private:
	// caratteri per la stampa della matrice
	char wallCh;
	char playerCh;
	char enemyCh;
	
	// traduce int nel giusto carattere
	char matrix_translate(int toConvert);

public:
	// costruttore
	MainWindow(char wallch, char playerch, char enemych);
	
	// stampa la matrice
    void print_room(Room *room, Player *player);
	
	// scambia la stanza con un'altra data come parametro
	void swap_room(Room *room);
};