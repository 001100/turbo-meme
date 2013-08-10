#ifndef TITLE_SCREEN_H_INCLUDED
#define TITLE_SCREEN_H_INCLUDED

#include <vector>
#include <ncurses.h> // For LINES/COLS
#include <iostream>
#include <string>

#include "globals.h"
#include "output.h"

class Menu
{
    private:
        std::vector<std::string> m_MenuElements;
    protected:
    public:
        void AddMenuElement(std::string NewMenuElement);

        void DrawMenu();

};

#endif // TITLE_SCREEN_H_INCLUDED
