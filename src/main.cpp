#include "Graphics.hpp"
#include <ncurses.h>

using namespace std;

int main() {
    initscr();

    MainWindow mw;
    mw.init();

    getch();

    endwin();
}