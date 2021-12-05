#include "player.h"
#include <curses.h>

Player::Player(WINDOW * mainWin_param, WINDOW * sideWin_param){
    mainWin = mainWin_param;
    sideWin = sideWin_param;

    int yMax, xMax;
    getmaxyx(mainWin, yMax, xMax);

    length = 5;
    yPos = yMax / 2;
    xPos = xMax / 2;

    direction[0] = {'u'};

    for(int i = 0; i < length; i++){
        yPos_hist[i] = yPos + i;
        xPos_hist[i] = xPos;

        mvwprintw(mainWin, yPos + i, xPos, "%c", '@');
    }

}

void Player::movePlayer(char input){ // 'n' for none

    switch(input){
        case 'n':
            this->noneInput();
            break;
        case 'h':
            this->leftInput();
            break;
    }

}

// private method
void Player::noneInput(){

    wrefresh(mainWin);
}

void Player::leftInput(){
    direction[0] = 'h';
}
