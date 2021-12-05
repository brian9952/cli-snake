#ifndef _PLAYER_H_
#define _PLAYER_H_
#include<ncurses.h>
#include<iostream>

class Player {

    private:
        WINDOW * mainWin;
        WINDOW * sideWin;
        int yPos, xPos;
        int yPos_hist[30], xPos_hist[30];
        int length;
        char direction[0]; // 'u' for up, 'l' for left, 'r' for right, 'd' for down

        void shiftArray(int *& arr);
        void noneInput();

    public:
        Player(WINDOW * mainWin_param, WINDOW * sideWin_param);
        void movePlayer(char input);
        ~Player();

};

#endif
