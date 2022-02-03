#include "Graphics.hpp"
#include "../map/MapGen.hpp"
#include <ncurses.h>

using namespace std;

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
	MapGen mg; 
	mg.gen_map();
	Room r(mg.map);
	Player p(&r, 10, 3, false, 2, 2);
	int c = 0;

	// MAIN GAME LOOP
	while(true){
		mw.print_room(&r, &p);

		c = getch();
		if(p.check_door(&r, c)){
			mg.gen_map();
			r.swap_matrix(mg.map);
			p.x = 1;
			p.y = 2;
		}
		check_key(&p, &r, c);
		p.render(&r);
	}
	endwin();
    return 0;
}