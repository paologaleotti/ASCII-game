#include "Graphics.hpp"

MainWindow::MainWindow(char wallch, char playerch, char enemych){
	this->wallCh = wallch;
	this->playerCh = playerch;
	this->enemyCh = enemych;
	start_color();
	init_pair(WALL,   COLOR_BLUE,     COLOR_BLACK);
	init_pair(PLAYER,  COLOR_YELLOW,    COLOR_BLACK);
	init_pair(DOOR_EXIT,   COLOR_RED,      COLOR_BLACK);	
	init_pair(AIR,  COLOR_BLACK,    COLOR_BLACK);
	init_pair(DOOR_BACK,   COLOR_GREEN,    COLOR_BLACK);
	init_pair(ENEMY, COLOR_MAGENTA,  COLOR_BLACK);
}

char MainWindow::matrix_translate(int toConvert){
	switch (toConvert){
		case AIR: return ' ';
		case PLAYER: return this->playerCh;
		case WALL: return this->wallCh;
		case ENEMY: return this->enemyCh;
		case DOOR_EXIT: return '|';
		case DOOR_BACK: return '|';
		default: return ' ';
	}
}

void MainWindow::print_room(Room *room, Player *player){
	clear();	// clear screen
	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < 20; j++) {
			attron(COLOR_PAIR(room->currentRoom[i][j]));
			printw("%c", matrix_translate(room->currentRoom[i][j]));
			printw("%c", ' ');
			attroff(COLOR_PAIR(room->currentRoom[i][j]));
		}
		printw("\n");
	}
}