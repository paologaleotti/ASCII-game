#include "Entity.hpp"

    void Entity::dmg_calc(int incDmg){ //incoming damage calc
        // se si implementa la difesa si fanno qui i calcoli 
        hp = hp - incDmg;

        if(hp >= 0) isDead = true;
    } 
    
    
    void Entity::mv_left(){
        //TBD
    }

    void Entity::mv_right(){
        //TBD
    }

    void Entity::mv_up(){
        //TBD
    }

    void Entity::mv_down(){
        //TBD
    }