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

void Player::shiftArray(int *& arr){
    int arr_temp[10];

    for(int i = 0; i < 10; i++){
        arr_temp[i] = arr[i];
    }

    for(int i = length; i > 0; i--){
        arr[i] = arr_temp[i-1];
    }
}

// private method
void Player::noneInput(){

    switch(direction[0]){
        case 'u':
            yPos -= 1;

            int *yPos_p = yPos_hist;
            int *xPos_p = xPos_hist;

            mvwprintw(mainWin, yPos, xPos, "%c", '@');
            mvwprintw(mainWin, yPos_hist[length], xPos_hist[length], "%c", ' ');
            for(int i = 0; i < length; i++){
                mvwprintw(mainWin, i+1, 1, "%d", yPos_hist[i]);
            }
            //mvwprintw(mainWin, 2, 1, "%d", length);
            
            shiftArray(yPos_p);
            shiftArray(xPos_p);

            yPos_hist[0] = yPos;
            xPos_hist[0] = xPos;
            

            break;
    }

    wrefresh(mainWin);
}

void Player::leftInput(){
    direction[0] = 'h';
}
