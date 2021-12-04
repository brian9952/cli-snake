#include "player.h"
#include <curses.h>

Player::Player(WINDOW * mainWin_param, WINDOW * sideWin_param){
    mainWin = mainWin_param;
    sideWin = sideWin_param;

    int yMax, xMax;
    getmaxyx(mainWin, yMax, xMax);

    length = 5;
    head_yPos = yMax / 2;
    head_xPos = xMax / 2;

    tail_yPos = head_yPos + 5;
    tail_xPos = head_xPos;

    direction[0] = {'u'};
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
    char temp[32];

    for(int i = 0; i < length; i++){

        direction[i + 1] = direction[i];

    }

    mvwprintw(mainWin, 1, 1, "%s", direction);

    //for(int i = 0; i < length; i++){
    //    mvwprintw(mainWin, yPos + i, xPos, "%c", '@');
    //}

    wrefresh(mainWin);
}

void Player::leftInput(){
    direction[0] = 'h';
}
