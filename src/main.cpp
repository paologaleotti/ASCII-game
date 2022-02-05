#include "Graphics.hpp"
#include "../map/MapGen.hpp"
#include "../map/Memory.hpp"
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
	Memory cache;

	mg.gen_map();
	Room activeRoom(mg.map);

	Player p(&activeRoom, 10, 3, false, 2, 2);
	int c = 0;
	// MAIN GAME LOOP
	while(true){
		mw.print_room(&activeRoom, &p);
		c = getch();

		// PORTA PER ANDARE AVANTI
		if(p.check_door(&activeRoom, c) == 4){
			if(cache.active->next == nullptr){
				cache.push_map(activeRoom.currentRoom);
				cache.active = cache.active->next;
				mg.gen_map();
				activeRoom.swap_matrix(mg.map);
			}
			else{
				cache.active = cache.active->next;
				activeRoom.swap_matrix(cache.active->map);
			}
			p.x = 1;
			p.y = 2;
		}

		// PORTA PER TORNARE INDIETRO
		if(p.check_door(&activeRoom, c) == 5){
			if(cache.active->prec != nullptr){
				if(cache.active->next == nullptr){
					cache.push_map(activeRoom.currentRoom);
				}
				cache.active = cache.active->prec;
				activeRoom.swap_matrix(cache.active->map);
				p.x = 18;
				p.y = 18;
			}
		}

		// controllo il tasto premuto
		check_key(&p, &activeRoom, c);
		p.render(&activeRoom);
	}
	endwin();
    return 0;
}