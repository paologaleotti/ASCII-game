#include "Graphics.hpp"
#include "../map/MapGen.hpp"
#include "../map/Memory.hpp"
#include "../entities/Player.hpp"
#include "../entities/Enemy.hpp"
#include "../room/Room.hpp"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


struct enemyList{
	Enemy enemy;
	enemyList *next;
};

typedef enemyList *p_enemyList;

p_enemyList enemyHead = NULL;

p_enemyList head_push(p_enemyList head, Enemy e){
	p_enemyList temp = new enemyList;
	temp->enemy = e;
	temp->next = head;
	return temp;
}

p_enemyList enemy_obj_assign(p_enemyList head, Room *room){

	head = new enemyList;

	for(int y = 0; y < 20; y++){
		for(int x = 0; x < 20; x++){
			if(room->currentRoom[x][y] == 3){
				Enemy e(room, 3, 3, 0, x, y, 100);
				head = head_push(head, e);
			}
		}

	}

	return head;

}

void rand_mv(Room *room, Enemy *enemy){
	
	srand(time(NULL));
    int m = rand()%4;

	switch (m){
	case '0':
		enemy->mv_left(room);
		break;
	case '1':
		enemy->mv_right(room);
		break;
	case '2':
		enemy->mv_up(room);
		break;
	case '3':
		enemy->mv_down(room);
		break;
	default:
		break;
	}
}

void enemy_movement(p_enemyList head, Room *room){

	p_enemyList temp = head;
	while(temp!=NULL){
		rand_mv(room, &temp->enemy);
		temp = temp->next;
	}


}



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
		player->enemy_kill(room);
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

	enemyHead = enemy_obj_assign(enemyHead, &activeRoom);

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
				enemyHead = enemy_obj_assign(enemyHead, &activeRoom);
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
		enemy_movement(enemyHead, &activeRoom);
		check_key(&p, &activeRoom, c);
		cache.modify_node(activeRoom.currentRoom);
		
	}
	endwin();
    return 0;
}