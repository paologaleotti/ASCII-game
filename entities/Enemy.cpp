#include "Enemy.hpp"
#include <ncurses.h>


Enemy::Enemy(Room *room, int hp, int dmg, bool isDead, int x, int y, int score){
	this->hp = hp;
	this->dmg = dmg;
	this->isDead = isDead;
	this->x = x;
	this->y = y;
	room->currentRoom[this->y][this->x] = 3;	//spawna il nemico
}

Enemy::Enemy(){

}

void Enemy::render(Room *room, bool spawn){
	if(spawn) room->currentRoom[this->y][this->x] = 3;
	else room->currentRoom[this->y][this->x] = spawn;
}

void Enemy::mv_left(Room *room){
	if (room->currentRoom[this->y][this->x-1] != 2 && room->currentRoom[this->y][this->x-1] != 3){
		Enemy::render(room, 0);
		this->x--;
		Enemy::render(room);
	}
}

void Enemy::mv_right(Room *room){
	if (room->currentRoom[this->y][this->x+1] != 2 && room->currentRoom[this->y][this->x+1] != 3){
		Enemy::render(room, 0);
		this->x++;
		Enemy::render(room);
	}
}

void Enemy::mv_up(Room *room){
	if (room->currentRoom[this->y-1][this->x] != 2 && room->currentRoom[this->y-1][this->x] != 3){
		Enemy::render(room, 0);
		this->y--;
		Enemy::render(room);
	}
}

void Enemy::mv_down(Room *room){
	if (room->currentRoom[this->y+1][this->x] != 2 && room->currentRoom[this->y+1][this->x] != 3){
		Enemy::render(room, 0);
		this->y++;
		Enemy::render(room);
	}
}


	
