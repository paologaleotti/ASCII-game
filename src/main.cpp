#include "Graphics.hpp"
#include "../map/MapGen.hpp"
#include "../map/Memory.hpp"
#include "../entities/Player.hpp"
#include "../entities/Enemy.hpp"
#include "../room/Room.hpp"
#include <ncurses.h>

using namespace std;

/*
struct enemyList{
	Enemy enemy;
	enemyList *next;
};

typedef enemyList *p_enemyList;

p_enemyList head_push(p_enemyList head, Enemy e){
	p_enemyList temp = new enemyList;
	temp->enemy = e;
	temp->next = head;
	return temp;
}

void enemy_spawn(Room *room){

	p_enemyList head = new enemyList;

	for(int y = 1; y < 19; y++){
		for(int x = 1; x < 19; x++){
			if(room->currentRoom[x][y] == 3){
				Enemy e(room, 3, 3, 0, x, y, 100);
				head = head_push(head, e);
			}
		}

	}


}
*/

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
	cache.push_map(mg.map);

	Room activeRoom(cache.active->map);
	activeRoom.currentRoom[1][0] = 2;
	activeRoom.currentRoom[2][0] = 2;

	Player p(&activeRoom, 10, 3, false, 2, 2);
	int c = 0;

	// MAIN GAME LOOP
	while(true){
		p.render(&activeRoom);
		mw.print_room(&activeRoom, &p, cache.active->level_id);
		c = getch();

		// PORTA PER ANDARE AVANTI
		if(p.check_door(&activeRoom, c) == 4){
			p.render(&activeRoom, 0);
			if(cache.active->next == NULL){
				mg.gen_map();
				cache.push_map(mg.map);
				activeRoom.swap_matrix(cache.active->map);
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
			if(cache.active->prec != NULL){
				cache.active = cache.active->prec;
				p.render(&activeRoom, 0);
				activeRoom.swap_matrix(cache.active->map);
				p.x = 18;
				p.y = 17;
			}
			
		}

		// controllo il tasto premuto
		check_key(&p, &activeRoom, c);
		cache.modify_node(activeRoom.currentRoom);
		
	}
	endwin();
    return 0;
}