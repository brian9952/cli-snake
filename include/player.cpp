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

    for(int i = 0; i < length; i++){
        direction[i] = 'u';
    }
}

void Player::movePlayer(char input){ // 'n' for none

    switch(input){
        case 'n':
            this->noneInput();
            break;
    }

}

// private method
void Player::noneInput(){
    char temp[32];

    for(int i = 0; i < length; i++){

        if(direction[i] == 'u'){

            if(i == 0)
                head_yPos -= 1;

            mvwprintw(mainWin, head_yPos + i, head_xPos, "%c", '@');

            if(i == (length - 1)){
                tail_yPos -= 1;
                mvwprintw(mainWin, tail_yPos, tail_xPos, "%c", ' ');
            }

            mvwprintw(mainWin, 1, 1, "%d, %d", head_yPos, tail_yPos);

        }

    }

    //for(int i = 0; i < length; i++){
    //    mvwprintw(mainWin, yPos + i, xPos, "%c", '@');
    //}

    wrefresh(mainWin);
}
