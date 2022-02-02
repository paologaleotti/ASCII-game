#include "Room.hpp"

Room::Room(int matrix[10][10]){
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			this->currentRoom[i][j] = matrix[i][j];
		}
	}
}

void Room::swap_matrix(int matrix[10][10]){
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			this->currentRoom[i][j] = matrix[i][j];
		}
	}
}