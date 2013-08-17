#ifndef TITLE_SCREEN_H_INCLUDED
#define TITLE_SCREEN_H_INCLUDED

#include <vector>
#include <string>

class Menu
{
    private:
        std::vector<std::string> m_MenuElements;
        int _selectedPosition;
        int _menuSize;
    protected:
    public:
        Menu();
        void AddMenuElement(std::string NewMenuElement);


        int SetSelection(int positionDelta);
        int GetSelection() { return _selectedPosition; }

        void DrawMenu();
};

void TitleScreenActions();

#endif // TITLE_SCREEN_H_INCLUDED
