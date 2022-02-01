#include "Graphics.hpp"
#include <ncurses.h>

MainWindow::MainWindow(char wallch, char playerch, char enemych){
	this->wallCh = wallch;
	this->playerCh = playerch;
	this->enemyCh = enemych;
}

char MainWindow::matrixTranslate(int toConvert){
	switch (toConvert){
		case 0: return ' ';
		case 1: return this->playerCh;
		case 2: return this->wallCh;
		case 3: return this->enemyCh;
		default: return ' ';
	}
}

void MainWindow::printRoom(int room[][10]) {
	clear();	// clear screen

	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			printw("%c", matrixTranslate(room[i][j]));
		}
		printw("\n");
	}
}