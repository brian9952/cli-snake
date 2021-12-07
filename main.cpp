#include<ncurses.h>
#include<iostream>
#include<unistd.h>
#include "include/window.cpp"
#include "include/player.cpp"

void initCurses();
WINDOW *createMainWindow(WINDOW * win, int yMax, int xMax);
WINDOW *createSideWindow(WINDOW * win, int yMax, int xMax);
int menuSelection(int choice, int highlight);

int main(int argc, char ** argv){
    initCurses();

    int yMax, xMax;
    int highlight = 0;
    getmaxyx(stdscr, yMax, xMax);
    WINDOW * mainWin;
    WINDOW * sideWin;
    refresh();

    mainWin = createMainWindow(mainWin, yMax, xMax);
    sideWin = createSideWindow(sideWin, yMax, xMax);

    // object declaration
    Menu *win = new Menu(mainWin, sideWin);
    refresh();

    // main menu looping
    while(1){
        win->showMenu(highlight);
        win->sideMenu(highlight);
        int c = win->getInput();
        highlight = menuSelection(c, highlight);

        if(c == 10){
            delete win;
            mainWin = createMainWindow(mainWin, yMax, xMax);
            sideWin = createSideWindow(sideWin, yMax, xMax);

            if(highlight == 0){
                int ch, collision;
                nodelay(stdscr, TRUE);
                Player * player = new Player(mainWin, sideWin);
                while(1){
                    refresh();
                    ch = getch();
                    flushinp();
                    if(ch == ERR){
                        collision = player->movePlayer('n');
                        usleep(100000);
                    }else{
                        player->movePlayer(ch);
                    }
                }

            }else if(highlight == 1){
                // settings

            }else{
                // exit
                break;
            }

        }
    }


    endwin();

    return 0;
}

void initCurses(){
    initscr();
    noecho();
    cbreak();
    curs_set(0);
}

WINDOW *createMainWindow(WINDOW * win, int yMax, int xMax){
    win = newwin(yMax, xMax - 25, 0, 0);
    box(win, 0, 0);
    wrefresh(win);

    return win;
}

WINDOW *createSideWindow(WINDOW * win, int yMax, int xMax){
    win = newwin(yMax, 25, 0, xMax - 25);
    box(win, 0, 0);
    wrefresh(win);

    return win;
}

int menuSelection(int choice, int highlight){

    switch(choice){
        case 'j':
            highlight++;
            if(highlight > 2)
                highlight = 2;
            break;
        case 'k':
            highlight--;
            if(highlight < 0)
                highlight = 0;
            break;
        default:
            break;
    }

    return highlight;
}
