#include "MainLoop.hpp"
#include <ncurses.h>

void MainLoop::init() {
    WINDOW *win = newwin(10, 20, 5, 5);
    refresh();

    /*
    box(win, 0, 0);
    wrefresh(win);
    */

    int c = (int)'+';
    
    wborder(win, 0, 0, 0, 0, c, c, c, c);
    mvwprintw(win, 0, 4, "aaaa");
    wrefresh(win);
}

void MainLoop::loop() {

}
