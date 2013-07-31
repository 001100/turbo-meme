#ifndef CURSES_OUTPUT_H
#define CURSES_OUTPUT_H

#include <ncurses.h>
#include <string>

#include "globals.h"

class CursesOutput
{
    private:
        static WINDOW* m_MainWin;
        static WINDOW* m_LogWin;
        static WINDOW* m_FullWin;

    protected:
    public:
        static void CursesDraw(wType win, std::string text);
        static void CursesDraw(wType win, int ly, int lx, std::string text);
        static void CursesRefresh(wType win);
        static void CursesClear(wType win);
        static void InitCursesWindows();
};

#endif // CURSES_OUTPUT_H
