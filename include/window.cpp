#include "window.h"
#include <curses.h>

Menu::Menu(WINDOW * mainWin_param, WINDOW * sideWin_param){
    mainWin = mainWin_param;
    sideWin = sideWin_param;
}

void Menu::showMenu(){
    int yMax, xMax;
    getmaxyx(mainWin, yMax, xMax);

    int xCenter = (xMax / 2) - 5;
    int yCenter = yMax / 2;

    for(int i = 0; i < sizeof(choice); i++){
        if(i == highlight){
            wattron(mainWin, A_REVERSE);
        }
        mvwprintw(mainWin, yCenter + i, xCenter, choice[i].c_str());
        wattroff(mainWin, A_REVERSE);
    }

    wrefresh(mainWin);

}

