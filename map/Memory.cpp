#include "Memory.hpp"
#include <ncurses.h>

Memory::Memory(){
	this->head = new map_mem;
	this->active = this->head;
}

void Memory::push_map(int mapToPush[20][20]){
	p_map_mem last = this->active;
	p_map_mem new_map = new map_mem;

	for(int i=0; i<20; i++){
		for(int j=0; j<20; j++){
			new_map->map[i][j] = mapToPush[i][j];
		}
	}
	new_map->next = nullptr;

	if(this->head == nullptr){
		new_map->prec = nullptr;
		this->head = new_map;
	}else{
		while(last->next != nullptr){
			last = last->next;
		}
		last->next = new_map;
		new_map->prec = last;
	}
}

void Memory::modify_node(p_map_mem *act, int mapToPush[20][20]){
	p_map_mem temp = *act;
	for(int i=0; i<20; i++){
		for(int j=0; j<20; j++){
			temp->map[i][j] = mapToPush[i][j];
		}
	}
}