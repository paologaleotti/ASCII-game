#include "Player.hpp"

Player::Player(Room *room, int hp, int dmg, bool isDead, int x, int y, int score){
	this->hp = hp;
	this->dmg = dmg;
	this->isDead = isDead;
	this->x = x;
	this->y = y;
	this->score = score;
	room->currentRoom[this->y][this->x] = 1;	//spawna il player
}

void Player::render(Room *room, bool spawn){
	room->currentRoom[this->y][this->x] = spawn;
}

int Player::check_door(Room *room, int dir){
	int toCheck = 0;
	switch (dir){
		case 'a':
			toCheck = room->currentRoom[this->y][this->x-1];
			if (toCheck == 4 || toCheck == 5) return toCheck;
			break;
		case 'd':
			toCheck = room->currentRoom[this->y][this->x+1];
			if (toCheck == 4 || toCheck == 5) return toCheck;
			break;
		case 'w':
			toCheck = room->currentRoom[this->y-1][this->x];
			if (toCheck == 4 || toCheck == 5) return toCheck;
			break;
		case 's':
			toCheck = room->currentRoom[this->y+1][this->x];
			if (toCheck == 4 || toCheck == 5) return toCheck;
			break;
		default:
			toCheck = 0; 
			break;
	}
	return false;
}

void Player::mv_left(Room *room){
	if (room->currentRoom[this->y][this->x-1] != 2 && room->currentRoom[this->y][this->x-1] != 3 && room->currentRoom[this->y][this->x-1] != 6){
		Player::render(room, 0);
		this->x--;
	}
}

void Player::mv_right(Room *room){
	if (room->currentRoom[this->y][this->x+1] != 2 && room->currentRoom[this->y][this->x+1] != 3 && room->currentRoom[this->y][this->x+1] != 6){
		Player::render(room, 0);
		this->x++;
	}
}

void Player::mv_up(Room *room){
	if (room->currentRoom[this->y-1][this->x] != 2 && room->currentRoom[this->y-1][this->x] != 3 && room->currentRoom[this->y-1][this->x] != 6){
		Player::render(room, 0);
		this->y--;
	}
}

void Player::mv_down(Room *room){
	if (room->currentRoom[this->y+1][this->x] != 2 && room->currentRoom[this->y+1][this->x] != 3 && room->currentRoom[this->y+1][this->x] != 6){
		Player::render(room, 0);
		this->y++;
	}

}

void Player::add_score(Room *room, int dir) {
	int y = this->y, x = this->x;
	switch (dir) {
		case 'w': y--;
		break;
		case 'a': x--;
		break;
		case 's': y++;
		break;
		case 'd': x++;
		break;
	
		default:
		break;
	}

	if(room->currentRoom[y][x] == 7) {
		this->score += 5;
	} else if(room->currentRoom[y][x] == 8) {
		this->hp = this->score%10;
	}
}
