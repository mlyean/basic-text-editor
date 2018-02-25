#pragma once

#include <ncurses/ncurses.h>

#include "buffer.hpp"

class Editor
{
private:
    int x, y;
    char mode;
    Buffer* buff;
    std::string status, filename;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void deleteLine();
    void deleteLine(int);

    void saveFile();

public:
    Editor();
    Editor(std::string);

    char getMode() { return mode; }
    
    void handleInput(int);
    void printBuff();
    void printStatusLine();
    void updateStatus();
};