#include "Player.hpp"

Player::Player(int hp, int dmg, bool isDead, int x, int y, int score){
	this->hp = hp;
	this->dmg = dmg;
	this->isDead = isDead;
	this->x = x;
	this->y = y;
}

void Player::mv_left(){
	this->x--;
}

void Player::mv_right(){
	this->x++;
}

void Player::mv_up(){
	this->y--;
}

void Player::mv_down(){
	this->y++;
}