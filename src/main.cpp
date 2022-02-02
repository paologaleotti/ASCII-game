#include "Graphics.hpp"
#include <ncurses.h>

using namespace std;

int temp[10][10]= {
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		2, 0, 0, 0, 0, 0, 0, 0, 0, 2,
		2, 0, 0, 0, 0, 0, 0, 0, 0, 2,
		2, 0, 0, 0, 0, 0, 0, 0, 0, 2,
		2, 0, 0, 0, 0, 0, 0, 0, 0, 4,
		2, 0, 0, 0, 0, 0, 0, 3, 0, 2,
		2, 0, 0, 0, 0, 0, 0, 0, 0, 2,
		2, 0, 0, 0, 3, 0, 0, 0, 0, 2,
		2, 0, 0, 0, 0, 0, 0, 0, 0, 2,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
};

int temp2[10][10]= {
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		2, 0, 0, 2, 0, 0, 0, 0, 0, 2,
		2, 0, 0, 2, 0, 0, 0, 0, 0, 2,
		2, 0, 0, 2, 0, 0, 0, 0, 0, 2,
		2, 0, 0, 0, 0, 0, 0, 0, 0, 2,
		2, 0, 0, 0, 0, 0, 0, 3, 0, 2,
		2, 0, 0, 0, 0, 0, 0, 0, 0, 2,
		2, 0, 0, 0, 3, 0, 0, 0, 0, 2,
		2, 0, 0, 0, 0, 0, 0, 0, 0, 2,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
};

void check_key(Player *player, Room *room, char c){
	switch (c){
	case 'a':
		player->mv_left(room);
		break;
	case 'd':
		player->mv_right(room);
		break;
	case 'w':
		player->mv_up(room);
		break;
	case 's':
		player->mv_down(room);
		break;
	default:
		break;
	}
}

int main() {
	
	initscr();
	MainWindow mw('#', '@', '&');
	Room r(temp);
	Player p(&r, 10, 3, false, 3, 1);

	// MAIN GAME LOOP
	while(true){
		mw.print_room(&r, &p);
		//////////////////////////
		if(p.check_door(&r)){
			r.swap_matrix(temp2);
		}
		//// NON FUNZIONANTE /////
		int c = getch();
		check_key(&p, &r, c);
		p.render(&r);
	}
	endwin();
    return 0;
}