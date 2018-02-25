#include <ncurses/ncurses.h>
#include <string>

#include "editor.hpp"

void curses_init()
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, true);
}

int main(int argc, char* argv[])
{
    Editor ed;
    if (argc > 1)
    {
        std::string fn = argv[1];
        ed = Editor(fn);
    }
    else
    {
        ed = Editor();
    }

    curses_init();

    while (ed.getMode() != 'x')
    {
        ed.updateStatus();
        ed.printStatusLine();
        ed.printBuff();
        int input = getch();
        ed.handleInput(input);
    }

    refresh();
    endwin();
    return 0;
}