#include<ncurses.h>
#include<iostream>
#include "include/window.cpp"

void initCurses();
WINDOW *createMainWindow(WINDOW * win, int yMax, int xMax);
WINDOW *createSideWindow(WINDOW * win, int yMax, int xMax);
int menuSelection(int choice, int highlight);

int main(int argc, char ** argv){
    initCurses();

    int yMax, xMax;
    int highlight = 0;
    getmaxyx(stdscr, yMax, xMax);
    WINDOW * mainWin;
    WINDOW * sideWin;
    refresh();

    mainWin = createMainWindow(mainWin, yMax, xMax);
    sideWin = createSideWindow(sideWin, yMax, xMax);

    // object declaration
    Menu *win = new Menu(mainWin, sideWin);

    while(1){
        win->showMenu(highlight);
        int c = win->getInput();
        highlight = menuSelection(c, highlight);
    }

    getch();
    endwin();

    return 0;
}

void initCurses(){
    initscr();
    noecho();
    cbreak();
    curs_set(0);
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

int menuSelection(int choice, int highlight){

    switch(choice){
        case 'j':
            highlight++;
            if(highlight > 2)
                highlight = 2;
            break;
        case 'k':
            highlight--;
            if(highlight < 0)
                highlight = 0;
            break;
        default:
            break;
    }

    return highlight;
}
