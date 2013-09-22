#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

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

#endif // MENU_H_INCLUDED
