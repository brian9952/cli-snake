#include "player.h"
#include <curses.h>

Player::Player(WINDOW * mainWin_param, WINDOW * sideWin_param){
    mainWin = mainWin_param;
    sideWin = sideWin_param;

    int yMax, xMax;
    getmaxyx(mainWin, yMax, xMax);

    length = 5;

    for(int i = 0; i < length; i++){
        direction[i] = '@';
    }

    for(int i = 0; i < length; i++){
        mvwprintw(mainWin, yMax / 2, 1 + i, "%c", '@');
    }

    wrefresh(mainWin);
}

void Player::movePlayer(char input){
}
