#ifndef COMBAT_HPP
#define COMBAT_HPP

#include "../entities/Enemy.hpp"
#include "../entities/Player.hpp"
#include "../room/Room.hpp"
#include <time.h>
#include <stdlib.h>

class Combat {
    private:
        struct enemyList{
            Enemy enemy;
            enemyList *next;
        };
        
    public:
        typedef enemyList *p_enemyList;
        p_enemyList head;
	
    Combat();
    void head_push(Enemy e);
    void enemy_obj_assign(Room *room);
    void rand_mv(p_enemyList p, Room *room);
    void enemy_movement(Room *room);
    void enemy_kill(Room *room, Player *player);
    void enemy_destroy(int x,int y);

};
#endif