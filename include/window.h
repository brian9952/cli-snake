#ifndef _WINDOW_H_
#define _WINDOW_H_
#include<ncurses.h>
#include<iostream>

class Menu {

    private:
        std::string choice[3] = {"Start", "Setting", "Exit"};
        int highlight;

    public:
        void showMenu(WINDOW * mainWin);
        void showTutor(WINDOW * sideWin);

};

#endif
