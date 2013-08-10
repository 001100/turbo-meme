#include "title_screen.h"


void Menu::AddMenuElement(std::string NewMenuElement)
{
    m_MenuElements.push_back(NewMenuElement);
}

void Menu::DrawMenu()
{
    wclear(MAIN_WIN);
    wclear(LOG_WIN);
    wclear(FULL_WIN);
    // Draw at the center of the screen.
    int y = LINES/2;
    int x = COLS/2;

    for (unsigned int iii = 0; iii < m_MenuElements.size(); iii++)
    {
        mvwprintw(FULL_WIN, y, x, m_MenuElements[iii].c_str());
        y++; // Draw at the next line.
    }

    wrefresh(FULL_WIN);
    getch();
    wclear(FULL_WIN);
}

