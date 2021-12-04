#ifndef _PLAYER_H_
#define _PLAYER_H_
#include<ncurses.h>
#include<iostream>

class Player {

    private:
        WINDOW * mainWin;
        WINDOW * sideWin;
        int yPos, xPos;
        int length;
        char direction[128];

    public:
        Player(WINDOW * mainWin_param, WINDOW * sideWin_param);
        void movePlayer(char input);
        ~Player();

};

#endif
