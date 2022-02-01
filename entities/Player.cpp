#include "Player.hpp"
Player::Player(Room *room, int hp, int dmg, bool isDead, int x, int y, int score){
	this->hp = hp;
	this->dmg = dmg;
	this->isDead = isDead;
	this->x = x;
	this->y = y;
	room->currentRoom[this->y][this->x] = 1;	//spawna il player
}

void Player::mv_left(Room *room){
	room->currentRoom[this->y][this->x] = 0;
	this->x--;
	room->currentRoom[this->y][this->x] = 1;
}

void Player::mv_right(Room *room){
	room->currentRoom[this->y][this->x] = 0;
	this->x++;
	room->currentRoom[this->y][this->x] = 1;
}

void Player::mv_up(Room *room){
	room->currentRoom[this->y][this->x] = 0;
	this->y--;
	room->currentRoom[this->y][this->x] = 1;
}

void Player::mv_down(Room *room){
	room->currentRoom[this->y][this->x] = 0;
	this->y++;
	room->currentRoom[this->y][this->x] = 1;
}