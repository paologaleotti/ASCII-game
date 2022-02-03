#include "Room.hpp"

Room::Room(int matrix[20][20]){
	for(int i=0; i<20; i++){
		for(int j=0; j<20; j++){
			this->currentRoom[i][j] = matrix[i][j];
		}
	}
}

void Room::swap_matrix(int matrix[20][20]){
	for(int i=0; i<20; i++){
		for(int j=0; j<20; j++){
			this->currentRoom[i][j] = matrix[i][j];
		}
	}
}