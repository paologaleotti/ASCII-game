#include "MainLoop.hpp"
#include <ncurses.h>

using namespace std;

int main() {
    //ciao a tutti :)
    initscr();

    MainLoop ml;
    ml.init();

    getch();

    endwin();
}