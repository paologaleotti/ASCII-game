#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include "../room/Room.hpp"
#include <ncurses.h>


class Player : public Entity{
    public:
	int score;
	int maxHP;

	Player(Room *room, int maxHP, int hp, int dmg, bool isDead=false, int x=0, int y=0, int score=0);
	void render(Room *room, bool spawn=true);
	void mv_left(Room *room);
    void mv_right(Room *room);
    void mv_up(Room *room);
    void mv_down(Room *room);
	void pickup_artifact(Room *room);
	int check_door(Room *room, int dir);
	void add_score(Room *room, int dir);
};
#endif