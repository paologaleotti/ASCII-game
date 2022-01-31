#include "Graphics.hpp"
#include <ncurses.h>

using namespace std;

int main() {
    //ciao a tutti :)
    initscr();

    MainWindow mw;
    mw.init();

    getch();

    endwin();
}