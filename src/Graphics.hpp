#include "../entities/Player.hpp"
#include <ncurses.h>

class MainWindow {
private:
	char wallCh;
	char playerCh;
	char enemyCh;

	char matrix_translate(int toConvert);

public:
	MainWindow(char wallch, char playerch, char enemych);
    void print_room(Room *room, Player *player);
	void swap_room(Room *room);
};