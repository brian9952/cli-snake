#ifndef _PLAYER_H_
#define _PLAYER_H_
#include<ncurses.h>
#include<iostream>

class Player {

    private:
        WINDOW * mainWin;
        WINDOW * sideWin;
        int yPos, xPos;
        int yPos_prey[30], xPos_prey[30];
        int yPos_eaten, xPos_eaten;
        int yPos_hist[30], xPos_hist[30];
        int length;
        char direction[0]; // 'u' for up, 'l' for left, 'r' for right, 'd' for down

        void shiftArray(int *& arr);
        int generateRandom(int max);

        void updateLength();

        int noneInput();

    public:
        Player(WINDOW * mainWin_param, WINDOW * sideWin_param);
        int movePlayer(char input);
        int checkCollision(int yPos, int xPos, int yPos_hist[30], int xPos_hist[30]);
        void generatePrey();
        int checkPrey();
        ~Player();

};

#endif
