#include "Memory.hpp"

void Memory::push_map(p_map_mem *head, int mapToPush[20][20]){
	p_map_mem current = *head;
	p_map_mem new_map = new map_mem;

	for(int i=0; i<20; i++){
		for(int j=0; j<20; j++){
			new_map->map[i][j] = mapToPush[i][j];
		}
	}

	if(*head == nullptr){
		*head = new_map;
		new_map->prec = nullptr;
		new_map->next = nullptr;
	}else{
		while(current != nullptr){
			current = current->next;
		}
		new_map->prec = current->prec;
		new_map->next = nullptr;
		current = new_map;
	}
}