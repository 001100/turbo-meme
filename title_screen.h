#ifndef TITLE_SCREEN_H_INCLUDED
#define TITLE_SCREEN_H_INCLUDED

//#include <ncurses.h> // For LINES/COLS
#include <vector>
#include <string>

#include "globals.h"

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
