#include "player.h"
#include <curses.h>

Player::Player(WINDOW * mainWin_param, WINDOW * sideWin_param){
    mainWin = mainWin_param;
    sideWin = sideWin_param;

    int yMax, xMax;
    getmaxyx(mainWin, yMax, xMax);

    length = 10;
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
            if(direction[0] == 'r')
                break;
            direction[0] = 'l';
            break;
        case 'j':
            if(direction[0] == 'u')
                break;
            direction[0] = 'd';
            break;
        case 'k':
            if(direction[0] == 'd')
                break;
            direction[0] = 'u';
            break;
        case 'l':
            if(direction[0] == 'l')
                break;
            direction[0] = 'r';
            break;
    }

}

void Player::shiftArray(int *& arr){
    int arr_temp[30];

    for(int i = 0; i < 30; i++){
        arr_temp[i] = arr[i];
    }

    for(int i = length; i > 0; i--){
        arr[i] = arr_temp[i-1];
    }
}

int Player::checkCollision(){
    for(int i = 0; i < length; i++){
        if(yPos_hist[i] == yPos && xPos_hist[i] == xPos){
            return 1;
        }
    }
    return 0;
}

// private method
void Player::noneInput(){
    int *yPos_p = yPos_hist;
    int *xPos_p = xPos_hist;
    int yMax, xMax;

    getmaxyx(mainWin, yMax, xMax);

    if(direction[0] == 'u'){

        if(yPos - 1 == 0){
            yPos = yMax - 2;
        }else{
            yPos -= 1;
        }

    }else if(direction[0] == 'l'){

        if(xPos - 1 == 0){
            xPos = xMax - 2;
        }else{
            xPos -= 1;
        }

    }else if(direction[0] == 'd'){

        if(yPos + 2 == yMax){
            yPos = 1;
        }else{
            yPos += 1;
        }

    }else if(direction[0] == 'r'){

        if(xPos + 2 == xMax){
            xPos = 1;
        }else{
            xPos += 1;
        }

    }

    if(checkCollision()){
        mvwprintw(mainWin, 1, 15, "%s", "LOSEEE");
    }

    shiftArray(yPos_p);
    shiftArray(xPos_p);

    mvwprintw(mainWin, yPos, xPos, "%c", '@');
    mvwprintw(mainWin, yPos_hist[length], xPos_hist[length], "%c", ' ');

    yPos_hist[0] = yPos;
    xPos_hist[0] = xPos;

    for(int i = 0; i < length; i++){
        mvwprintw(mainWin, i+1, 1, "%d %d", yPos_hist[i], xPos_hist[i]);
    }

    wrefresh(mainWin);
}
