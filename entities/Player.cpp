#include "Player.hpp"

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

bool Player::check_door(Room *room){
	if(room->currentRoom[this->y][this->x] == 4) return true;
	else return false;
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