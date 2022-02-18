#include "Pickups.hpp"

void Pickups::pickup_obj_assign(Room *room) {
    this->head = nullptr;

    for(int y = 0; y < 20; y++){
		for(int x = 0; x < 20; x++){
			if(room->currentRoom[y][x] == 7 || room->currentRoom[y][x] == 8){
				p_pickup_list tmp = new pickup_list;
                tmp->pickup.type = room->currentRoom[y][x];
                tmp->pickup.x = x;
                tmp->pickup.y = y;
                tmp->next = this->head;
                this->head = tmp;
			}
		}
	}
}

void Pickups::pickup_destroy(int x, int y) {
    p_pickup_list tmp = this->head, prec = nullptr;
    p_pickup_list to_destroy;
    
    while (tmp != nullptr) {
        if (tmp->pickup.x == x && tmp->pickup.y == y) {
            to_destroy = tmp;
        
            if (prec == nullptr) {
                this->head = this->head->next;
            } else {
                prec->next = tmp->next;
            }
            
            tmp = tmp->next;
            delete(to_destroy);
        } else {
            prec = tmp;
            tmp = tmp->next;
        }
    }
}

void Pickups::check_if_exist(Room *room) {
    p_pickup_list tmp = this->head;

    while (tmp != nullptr) {
        if (room->currentRoom[tmp->pickup.y][tmp->pickup.x] != tmp->pickup.type) {
            pickup_destroy(tmp->pickup.x, tmp->pickup.y);
        }
        tmp = tmp->next;
    }
}