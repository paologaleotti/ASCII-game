#include "Entity.hpp"

    void Entity::dmgCalc(int incDMG){ //incoming damage calc
        // se si implementa la difesa si fanno qui i calcoli 
        HP = HP - incDMG;

        if(HP >= 0) isDead = true;
    } 
    
    
    void Entity::mvleft(){
        //TBD
    }

    void Entity::mvright(){
        //TBD
    }

    void Entity::mvup(){
        //TBD
    }

    void Entity::mvdown(){
        //TBD
    }