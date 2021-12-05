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
            direction[0] = 'l';
            break;
        case 'j':
            direction[0] = 'd';
            break;
        case 'k':
            direction[0] = 'u';
            break;
        case 'l':
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

// private method
void Player::noneInput(){
    int *yPos_p = yPos_hist;
    int *xPos_p = xPos_hist;

    if(direction[0] == 'u'){
        yPos -= 1;
        mvwprintw(mainWin, yPos, xPos, "%c", '@');
        mvwprintw(mainWin, yPos_hist[length - 1], xPos_hist[length - 1], "%c", ' ');

        shiftArray(yPos_p);
        shiftArray(xPos_p);

    }else if(direction[0] == 'l'){
        xPos -= 1;
        mvwprintw(mainWin, yPos, xPos, "%c", '@');
        mvwprintw(mainWin, yPos_hist[length - 1], xPos_hist[length - 1], "%c", ' ');
        
        shiftArray(yPos_p);
        shiftArray(xPos_p);
    }else if(direction[0] == 'd'){
        yPos += 1;

        mvwprintw(mainWin, yPos, xPos, "%c", '@');
        mvwprintw(mainWin, yPos_hist[length - 1], xPos_hist[length - 1], "%c", ' ');

        shiftArray(yPos_p);
        shiftArray(xPos_p);
    }else if(direction[0] == 'r'){
        xPos += 1;

        mvwprintw(mainWin, yPos, xPos, "%c", '@');
        mvwprintw(mainWin, yPos_hist[length - 1], xPos_hist[length - 1], "%c", ' ');

        shiftArray(yPos_p);
        shiftArray(xPos_p);
    }

    yPos_hist[0] = yPos;
    xPos_hist[0] = xPos;

    for(int i = 0; i < length; i++){
        mvwprintw(mainWin, i+1, 1, "%d", yPos_hist[i]);
    }

    wrefresh(mainWin);
}
