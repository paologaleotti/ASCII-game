#include "Enemy.hpp"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

Enemy::Enemy(Room *room, int hp, int dmg, bool isDead, int x, int y, int score){
	this->hp = hp;
	this->dmg = dmg;
	this->isDead = isDead;
	this->x = x;
	this->y = y;
	room->currentRoom[this->y][this->x] = 3;	//spawna il nemico
}

void Enemy::render(Room *room, bool spawn){
	room->currentRoom[this->y][this->x] = spawn;
}

void Enemy::mv_left(Room *room){
	if (room->currentRoom[this->y][this->x-1] != 2){
		Enemy::render(room, 0);
		this->x--;
		Enemy::render(room);
	}
}

void Enemy::mv_right(Room *room){
	if (room->currentRoom[this->y][this->x+1] != 2){
		Enemy::render(room, 0);
		this->x++;
		Enemy::render(room);
	}
}

void Enemy::mv_up(Room *room){
	if (room->currentRoom[this->y-1][this->x] != 2){
		Enemy::render(room, 0);
		this->y--;
		Enemy::render(room);
	}
}

void Enemy::mv_down(Room *room){
	if (room->currentRoom[this->y+1][this->x] != 2){
		Enemy::render(room, 0);
		this->y++;
		Enemy::render(room);
	}

}

void Enemy::rand_mv(Enemy *enemy, Room *room){
	
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