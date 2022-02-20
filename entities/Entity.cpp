#include "Entity.hpp"

void Entity::dmg_calc(int incDmg){ //incoming damage calc
	// se si implementa la difesa si fanno qui i calcoli
	this->hp = this->hp - incDmg;

	if (this->hp >= 0)
		this->isDead = true;
}