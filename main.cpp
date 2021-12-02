#include<ncurses.h>
#include<iostream>
#include "include/window.cpp"

void initCurses();
WINDOW *createMainWindow(WINDOW * win, int yMax, int xMax);
WINDOW *createSideWindow(WINDOW * win, int yMax, int xMax);

int main(int argc, char ** argv){
    initCurses();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    WINDOW * mainWin;
    WINDOW * sideWin;
    refresh();

    mainWin = createMainWindow(mainWin, yMax, xMax);
    sideWin = createSideWindow(sideWin, yMax, xMax);

    // object declaration
    Menu *win = new Menu(mainWin, sideWin);

    win->showMenu();

    getch();
    endwin();

    return 0;
}

void initCurses(){
    initscr();
    noecho();
    cbreak();
}

WINDOW *createMainWindow(WINDOW * win, int yMax, int xMax){
    win = newwin(yMax, xMax - 20, 0, 0);
    box(win, 0, 0);
    wrefresh(win);

    return win;
}

WINDOW *createSideWindow(WINDOW * win, int yMax, int xMax){
    win = newwin(yMax, 20, 0, xMax - 20);
    box(win, 0, 0);
    wrefresh(win);

    return win;
}
