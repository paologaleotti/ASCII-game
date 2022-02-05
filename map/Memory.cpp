#include "Memory.hpp"
#include <ncurses.h>

Memory::Memory(){
	this->last = nullptr;
	this->active = last;
}

void Memory::fill_map(p_mem *ptr, int map[20][20]){
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			(*ptr)->map[i][j] = map[i][j];
		}
	}
}

void Memory::push_map(int mapToPush[20][20]) {

    if (this->last == nullptr) {
        this->last = new mem;
        Memory::fill_map(&this->last, mapToPush);
        this->last->prec = nullptr;
        this->last->next = nullptr;
    } else {
        p_mem tmp = this->last;
        this->last->next = new mem;
        this->last = this->last->next;
        Memory::fill_map(&this->last, mapToPush);
        this->last->prec = tmp;
        this->last->next = nullptr;
    }
    this->active = this->last;
}

void Memory::modify_node(int mapToPush[20][20]){
	Memory::fill_map(&this->active, mapToPush);
}