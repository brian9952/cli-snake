#ifndef _PLAYER_H_
#define _PLAYER_H_
#include<ncurses.h>
#include<iostream>

class Player {

    private:
        WINDOW * mainWin;
        WINDOW * sideWin;
        int head_yPos, head_xPos;
        int tail_yPos, tail_xPos;
        int length;
        char direction[128]; // 'u' for up, 'l' for left, 'r' for right, 'd' for down

        void noneInput();

    public:
        Player(WINDOW * mainWin_param, WINDOW * sideWin_param);
        void movePlayer(char input);
        ~Player();

};

#endif
