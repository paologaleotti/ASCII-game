#include "Graphics.hpp"

#define AIR 0
#define PLAYER 1
#define WALL 2
#define ENEMY 3
#define DOOR_EXIT 4
#define DOOR_BACK 5
#define BARRICADE 6
#define ARTIFACT 7
#define POWERUP 8
#define NS_AIR 9
#define UI_SCORE 10
#define UI_HP 11
#define UI_LEVEL 12


MainWindow::MainWindow(char wallch, char playerch, char enemych){
	this->wallCh = wallch;
	this->playerCh = playerch;
	this->enemyCh = enemych;
	start_color();
	init_pair(WALL,   COLOR_BLUE,     COLOR_BLUE);
	init_pair(PLAYER,  COLOR_YELLOW,    COLOR_BLACK);
	init_pair(DOOR_EXIT,   COLOR_RED,      COLOR_BLACK);	
	init_pair(AIR,  COLOR_BLACK,    COLOR_BLACK);
	init_pair(NS_AIR,  COLOR_BLACK,    COLOR_BLACK);
	init_pair(DOOR_BACK,   COLOR_GREEN,    COLOR_BLACK);
	init_pair(ENEMY, COLOR_MAGENTA,  COLOR_BLACK);
	init_pair(BARRICADE, COLOR_RED,  COLOR_BLACK);
	init_pair(ARTIFACT, COLOR_YELLOW,  COLOR_BLACK);
	init_pair(POWERUP, COLOR_CYAN,  COLOR_BLACK);
	init_pair(UI_SCORE, COLOR_BLACK,  COLOR_YELLOW);
	init_pair(UI_HP, COLOR_BLACK,  COLOR_RED);
	init_pair(UI_LEVEL, COLOR_BLACK,  COLOR_GREEN);
}

char MainWindow::matrix_translate(int toConvert){
	switch (toConvert){
		case AIR: return ' ';
		case PLAYER: return this->playerCh;
		case WALL: return this->wallCh;
		case ENEMY: return this->enemyCh;
		case DOOR_EXIT: return '|';
		case DOOR_BACK: return '|';
		case BARRICADE: return 'X';
		case ARTIFACT: return '+';
		case POWERUP: return '^';
		default: return ' ';
	}
}

void MainWindow::print_room(Room *room, Player *player, int level_id){
	clear();	// clear screen

	attron(COLOR_PAIR(UI_LEVEL));
	printw(" LEVEL: %d ", level_id);
	attroff(COLOR_PAIR(UI_LEVEL));

	attron(COLOR_PAIR(UI_HP));
	printw(" HP: %d ", player->hp);
	attroff(COLOR_PAIR(UI_HP));	

	attron(COLOR_PAIR(UI_SCORE));
	printw(" SCORE: %d \n", player->score);
	attroff(COLOR_PAIR(UI_SCORE));

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