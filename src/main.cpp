#include "Graphics.hpp"
#include "../map/MapGen.hpp"
#include "../map/Memory.hpp"
#include "../entities/Player.hpp"
#include "../entities/Enemy.hpp"
#include "../room/Room.hpp"
#include "../combat/Combat.hpp"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

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
	case 'r':
		//player->enemy_kill(room);
		break;
	default:
		break;
	}
}

int main() {
	initscr();
	srand(time(NULL));

	MainWindow mw('#', '@', '&');
	MapGen mg;
	Memory cache;

	Combat combatSystem;

	mg.gen_map();
	mg.gen_enemy();
	cache.push_map(mg.map);

	Room activeRoom(cache.active->map);
	activeRoom.currentRoom[1][0] = 2;
	activeRoom.currentRoom[2][0] = 2;

	Player p(&activeRoom, 10, 3, false, 2, 2);
	int c = 0;

	combatSystem.enemy_obj_assign(&activeRoom);

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
				mg.gen_enemy();
				cache.push_map(mg.map);
				activeRoom.swap_matrix(cache.active->map);
				combatSystem.enemy_obj_assign(&activeRoom);
			}
			else{
				cache.active = cache.active->next;
				activeRoom.swap_matrix(cache.active->map);
				combatSystem.enemy_obj_assign(&activeRoom);
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
				combatSystem.enemy_obj_assign(&activeRoom);
				p.x = 18;
				p.y = 17;
			}
			
		}

		// controllo il tasto premuto
		check_key(&p, &activeRoom, c);
		combatSystem.enemy_movement(&activeRoom);
		cache.modify_node(activeRoom.currentRoom);
		
	}
	endwin();
    return 0;
}