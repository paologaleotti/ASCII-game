#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"
#include "../room/Room.hpp"


class Enemy : public Entity{
    public:
	int score;
	
	Enemy();
	Enemy(Room *room, int hp, int dmg, bool isDead=false, int x=0, int y=0, int score=0);
	void render(Room *room, bool spawn=true);
	bool mv_left(Room *room);
    bool mv_right(Room *room);
    bool mv_up(Room *room);
    bool mv_down(Room *room);

};
#endif