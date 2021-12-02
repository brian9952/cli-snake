#ifndef _WINDOW_H_
#define _WINDOW_H_

#include<ncurses.h>
#include<iostream>

class Menu {

    private:
        WINDOW * mainWin;
        WINDOW * sideWin;
        std::string choice[3] = {"Start", "Settings", "Exit"};
        int highlight = 0;

    public:
        Menu(WINDOW * mainWin_param, WINDOW * sideWin_param);
        void showMenu();
        void showTutor();

};

#endif
