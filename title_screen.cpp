#include "title_screen.h"

#include <ncurses.h>
#include <iomanip>

#include "globals.h"
#include "game.h"

Menu::Menu(): _selectedPosition(0), _menuSize(0)
{

}

void Menu::AddMenuElement(std::string NewMenuElement)
{
    m_MenuElements.push_back(NewMenuElement);
    _menuSize = m_MenuElements.size();
}

int Menu::SetSelection(int positionDelta)
{
int delta = 0;
switch (positionDelta)
{
    case KEY_UP: delta  = -1; break;
    case KEY_DOWN: delta = 1; break;
}
// If we move beyond top limt then move selection to the bottom.
if (_selectedPosition + delta < 0) {
    _selectedPosition = _menuSize - 1;
    return 0; }
// ...and vice versa.
if (_selectedPosition + delta >= _menuSize) {
    _selectedPosition = 0;
    return 0; }
// If we in boundaries then move selection +/- 1.
    _selectedPosition += delta;
    return 0;
}

void Menu::DrawMenu()
{
    // Draw at the center of the screen.
    int y = LINES/2;
    int x = COLS/2;

//    wprintw(FULL_WIN, std::to_string(_menuSize).c_str());
//    wprintw(FULL_WIN, std::to_string(m_MenuElements.size()).c_str());
    mvwprintw(FULL_WIN, y + _selectedPosition, x-2, "* ");

    for (int iii = 0; iii < _menuSize; iii++)
    {
        mvwprintw(FULL_WIN, y, x, m_MenuElements[iii].c_str());
        y++; // Draw at the next line.
    }

    wrefresh(FULL_WIN);
    wclear(FULL_WIN);
}

void TitleScreenActions()
{
    switch (GAME->TitleScreenMenu.GetSelection()) {
    case 0:
        GAME->InitGameStart();
        break;
    case 1:
        wprintw(FULL_WIN, "Load is not currently available!");
        wrefresh(FULL_WIN);
        getch();
        wclear(FULL_WIN);
        break;
    case 2:
        GAME->SetStartStatus(true);
        GAME->SetQuitStatus(true);
        break;
    }
}



