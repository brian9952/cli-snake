#ifndef _WINDOW_H_
#define _WINDOW_H_

#include<ncurses.h>
#include<iostream>

class Menu {

    private:
        WINDOW * mainWin;
        WINDOW * sideWin;
        std::string choice[3] = {"Start", "Settings", "Exit"};

    public:
        Menu(WINDOW * mainWin_param, WINDOW * sideWin_param);
        WINDOW * getMainWindow();
        WINDOW * getSideWindow();
        void clearWindow();
        void showLogo();
        void showMenu(int highlight);
        void sideMenu(int highlight);
        void showTutor();
        char getInput();
        ~Menu();

};

#endif
