#include "window.h"
#include <curses.h>

Menu::Menu(WINDOW * mainWin_param, WINDOW * sideWin_param){
    mainWin = mainWin_param;
    sideWin = sideWin_param;
    keypad(mainWin, true);
}

void Menu::showMenu(int highlight){
    int yMax, xMax;
    getmaxyx(mainWin, yMax, xMax);

    int xCenter = (xMax / 2) - 5;
    int yCenter = yMax / 2;

    for(int i = 0; i < 3; i++){
        if(i == highlight){
            wattron(mainWin, A_REVERSE);
        }
        mvwprintw(mainWin, yCenter + i, xCenter, choice[i].c_str());
        wattroff(mainWin, A_REVERSE);
    }

    wrefresh(mainWin);
}

void Menu::sideMenu(int highlight){
    mvwprintw(sideWin, 1, 1, "%s", "                       ");
    int yMax, xMax;
    getmaxyx(sideWin, yMax, xMax);

    switch(highlight){
        case 0:
            mvwprintw(sideWin, 1, 1, "%s", "Play the game");
            break;
        case 1:
            mvwprintw(sideWin, 1, 1, "%s", "Gameplay configuration");
            break;
        case 2:
            mvwprintw(sideWin, 1, 1, "%s", "Exit game");
            break;
    }

    mvwprintw(sideWin, 4, 1, "%s", "Menu Controls");
    mvwprintw(sideWin, 5, 1, "%s", "-------------");
    mvwprintw(sideWin, 6, 1, "%s", "'j' = scroll down");
    mvwprintw(sideWin, 7, 1, "%s", "'k' = scroll up");
    mvwprintw(sideWin, 8, 1, "%s", "'Enter' = input choice");

    mvwprintw(sideWin, 12, 1, "%s", "Game Controls");
    mvwprintw(sideWin, 13, 1, "%s", "-------------");
    mvwprintw(sideWin, 14, 1, "%s", "'h' = left direction");
    mvwprintw(sideWin, 15, 1, "%s", "'j' = down direction");
    mvwprintw(sideWin, 16, 1, "%s", "'k' = up direction");
    mvwprintw(sideWin, 17, 1, "%s", "'l' = right direction");
    mvwprintw(sideWin, 18, 1, "%s", "'x' = exit to main menu");

    wrefresh(sideWin);

}

char Menu::getInput(){
    char c = wgetch(mainWin);
    return c;
}

Menu::~Menu(){
    delwin(mainWin);
    delwin(sideWin);
}
