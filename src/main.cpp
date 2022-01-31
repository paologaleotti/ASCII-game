#include "MainLoop.hpp"
#include <ncurses.h>

using namespace std;

int main() {
    initscr();

    MainLoop ml;
    ml.init();

    getch();

    endwin();
}
// sono un commento