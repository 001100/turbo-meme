#include "curses_output.h"

WINDOW* CursesOutput::m_MainWin;
WINDOW* CursesOutput::m_LogWin;
WINDOW* CursesOutput::m_FullWin;
//WINDOW* CursesOutput::m_FullWin;

//CursesOutput::CursesOutput()
//{
//    m_MainWin = newwin(LINES - 6, COLS, 0, 0);
//    m_LogWin  = newwin(5, COLS, LINES - 5, 0);
//}

//CursesOutput::~CursesOutput()
//{
//    delwin(m_MainWin);
//    delwin(m_LogWin);
//}

void CursesOutput::InitCursesWindows()
{
    m_MainWin = newwin(LINES - 9, COLS, 0, 0);
    m_LogWin  = newwin(8, COLS, LINES - 8, 0);
    m_FullWin = newwin(LINES, COLS, 0, 0);
}

void CursesOutput::CursesDraw(wType win, std::string text)
{
    switch(win)
    {
        case MAIN_WIN: wprintw(m_MainWin, text.c_str()); break;
        case LOG_WIN:  wprintw(m_LogWin,  text.c_str()); break;
        case FULL_WIN: wprintw(m_FullWin, text.c_str()); break;
    }
}

void CursesOutput::CursesDraw(wType win, int ly, int lx, std::string text)
{
    switch(win)
    {
        case MAIN_WIN: mvwprintw(m_MainWin, ly, lx, text.c_str()); break;
        case LOG_WIN:  mvwprintw(m_LogWin,  ly, lx, text.c_str()); break;
        case FULL_WIN: mvwprintw(m_FullWin, ly, lx, text.c_str()); break;
    }
}

void CursesOutput::CursesRefresh(wType win)
{
    switch(win)
    {
        case MAIN_WIN: wrefresh(m_MainWin); break;
        case LOG_WIN:  wrefresh(m_LogWin);  break;
        case FULL_WIN: wrefresh(m_FullWin); break;
    }
}

void CursesOutput::CursesClear(wType win)
{
    switch(win)
    {
        case MAIN_WIN: wclear(m_MainWin); break;
        case LOG_WIN:  wclear(m_LogWin);  break;
        case FULL_WIN: wclear(m_FullWin); break;
    }
}


