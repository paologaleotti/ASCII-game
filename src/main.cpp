#include "Graphics.hpp"
#include "../entities/Player.hpp"
#include <ncurses.h>


using namespace std;

int main() {
	// MAT TEMPORANEA
	int currentRoom[10][10]= {
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		2, 0, 0, 0, 0, 0, 0, 0, 0, 2,
		2, 0, 0, 1, 0, 0, 0, 0, 0, 2,
		2, 0, 0, 0, 0, 0, 0, 0, 0, 2,
		2, 0, 0, 0, 0, 0, 0, 0, 0, 2,
		2, 0, 0, 0, 0, 0, 3, 0, 0, 2,
		2, 0, 0, 0, 0, 0, 0, 0, 0, 2,
		2, 0, 0, 0, 3, 0, 0, 0, 0, 2,
		2, 0, 0, 0, 0, 0, 0, 0, 0, 2,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	};
	initscr();
	MainWindow mw('#', '@', '&');
	Player p(10, 3);
	

	// MAIN GAME LOOP
	while(true){
		mw.printRoom(currentRoom);
		getch();
	}
	endwin();
    return 0;
}