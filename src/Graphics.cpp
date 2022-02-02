#include "Graphics.hpp"

MainWindow::MainWindow(char wallch, char playerch, char enemych){
	this->wallCh = wallch;
	this->playerCh = playerch;
	this->enemyCh = enemych;
}

char MainWindow::matrix_translate(int toConvert){
	switch (toConvert){
		case 0: return ' ';
		case 1: return this->playerCh;
		case 2: return this->wallCh;
		case 3: return this->enemyCh;
		case 4: return '|';
		default: return ' ';
	}
}

void MainWindow::print_room(Room *room, Player *player){
	clear();	// clear screen
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			printw("%c", matrix_translate(room->currentRoom[i][j]));
			printw("%c", ' ');
		}
		printw("\n");
	}
}