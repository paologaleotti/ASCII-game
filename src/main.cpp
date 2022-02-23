#include "../graphics/Graphics.hpp"
#include "../map/MapGen.hpp"
#include "../map/Memory.hpp"
#include "../entities/Player.hpp"
#include "../room/Room.hpp"
#include "../combat/Combat.hpp"
#include "../pickups/Pickups.hpp"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void check_key(Player *player,Combat *combat, Room *room, char c){
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
		combat->enemy_kill(room, player);
		break;
	default:
		break;
	}
}

MapGen generate(MapGen map) {
	map.gen_map();
	map.gen_enemy();
	map.gen_artifacts();
	map.gen_powerup();

	return map;
}

int main() {
	initscr();
	srand(time(NULL));

	MainWindow mainWind('#', '@', '&');
	MapGen mapGenerator;
	Memory mapMemory;
	Combat combatSystem;
	Pickups pickUp;

	mapGenerator = generate(mapGenerator);
	mapMemory.push_map(mapGenerator.map);

	Room activeRoom(mapMemory.active->map);
	activeRoom.currentRoom[1][0] = 2;
	activeRoom.currentRoom[2][0] = 2;

	Player player(&activeRoom, 10, 3, false, 2, 2);
	int c = 0;

	combatSystem.enemy_obj_assign(&activeRoom);
	pickUp.pickup_obj_assign(&activeRoom);

	// MAIN GAME LOOP
	while(c != 'q'){
		player.render(&activeRoom);
		mainWind.print_room(&activeRoom, &player, mapMemory.active->level_id);
		c = getch();

		// PORTA PER ANDARE AVANTI
		if(player.check_door(&activeRoom, c) == 4){
			player.render(&activeRoom, 0);
			if(mapMemory.active->next == NULL){
				mapGenerator = generate(mapGenerator);
				mapMemory.push_map(mapGenerator.map);
			}
			else {
				mapMemory.active = mapMemory.active->next;
			}

			activeRoom.swap_matrix(mapMemory.active->map);
			combatSystem.enemy_obj_assign(&activeRoom);
			pickUp.pickup_obj_assign(&activeRoom);

			player.x = 1;
			player.y = 2;
		}

		// PORTA PER TORNARE INDIETRO
		if(player.check_door(&activeRoom, c) == 5){
			if(mapMemory.active->prec != NULL){
				mapMemory.active = mapMemory.active->prec;
				player.render(&activeRoom, 0);
				activeRoom.swap_matrix(mapMemory.active->map);
				combatSystem.enemy_obj_assign(&activeRoom);
				pickUp.pickup_obj_assign(&activeRoom);
				player.x = 18;
				player.y = 17;
			}
			
		}

		player.add_score(&activeRoom, c);
		
		// controllo il tasto premuto
		check_key(&player, &combatSystem, &activeRoom, c);
		combatSystem.enemy_movement(&activeRoom);
		pickUp.check_if_exist(&activeRoom);
		// activeRoom.check_gate();
		mapMemory.modify_node(activeRoom.currentRoom);
		
	}
	endwin();
    return 0;
}