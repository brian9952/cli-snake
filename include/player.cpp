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
    int yPos_temp, xPos_temp;

    for(int i = 0;i < length; i++){
        if(direction[i] == 'u'){
            if(i == 0)
                yPos_temp = yPos - 1;
            
            mvwprintw(mainWin, yPos - i, xPos, "%c", '@');
        }

        if(i == length)
            switch(direction[i]){
                case 'u':
                    
            }
    }

    yPos = yPos_temp;

    //for(int i = 0; i < length; i++){
    //    mvwprintw(mainWin, yPos + i, xPos, "%c", '@');
    //}

    wrefresh(mainWin);
}
