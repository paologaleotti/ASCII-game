#include "Player.hpp"
#include <ncurses.h>

Player::Player(Room *room, int hp, int dmg, bool isDead, int x, int y, int score){
	this->hp = hp;
	this->dmg = dmg;
	this->isDead = isDead;
	this->x = x;
	this->y = y;
	room->currentRoom[this->y][this->x] = 1;	//spawna il player
}

void Player::render(Room *room, bool spawn){
	room->currentRoom[this->y][this->x] = spawn;
}

bool Player::check_door(Room *room, int dir){
	switch (dir){
		case 'a':
			if (room->currentRoom[this->y][this->x-1] == 4) return true;
			break;
		case 'd':
			if (room->currentRoom[this->y][this->x+1] == 4) return true;
			break;
		case 'w':
			if (room->currentRoom[this->y+1][this->x] == 4) return true;
			break;
		case 's':
			if (room->currentRoom[this->y-1][this->x] == 4) return true;
			break;
		default: break;
	}
	return false;
}

void Player::mv_left(Room *room){
	Player::render(room, 0);
	this->x--;
	Player::render(room);
}

void Player::mv_right(Room *room){
	Player::render(room, 0);
	this->x++;
	Player::render(room);
}

void Player::mv_up(Room *room){
	Player::render(room, 0);
	this->y--;
	Player::render(room);
}

void Player::mv_down(Room *room){
	Player::render(room, 0);
	this->y++;
	Player::render(room);
}