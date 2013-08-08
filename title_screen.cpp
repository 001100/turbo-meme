#include "title_screen.h"


void Menu::AddMenuElement(std::string NewMenuElement)
{
    m_MenuElements.push_back(NewMenuElement);
}

void Menu::DrawMenu()
{
    Clear(MAIN_WIN);
    Clear(LOG_WIN);
    Clear(FULL_WIN);
    // Draw at the center of the screen.
    int y = LINES/2;
    int x = COLS/2;

    for (unsigned int iii = 0; iii < m_MenuElements.size(); iii++)
    {
        Draw(FULL_WIN, y, x, m_MenuElements[iii]);
        y++; // Draw at the next line.
    }

    Refresh(FULL_WIN);
    getch();
    Clear(FULL_WIN);
}

void TitleScreen()
{
    Draw(FULL_WIN, LINES/2, COLS/2, "Start New Game");
    Refresh(FULL_WIN);
    getch();
    Clear(FULL_WIN);
}

