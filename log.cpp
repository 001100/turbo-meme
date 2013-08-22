#include "log.h"

std::vector<std::string> Log::m_LogData;

void Log::Read(unsigned int NumOfLastEntries, WINDOW* win)
{
if (NumOfLastEntries > m_LogData.size())
    {
    for (unsigned int Position = 0; Position < m_LogData.size(); ++Position)
    {
        wprintw(win, (m_LogData[Position]).c_str());
        wprintw(win, "\n");
    }
    }
else
    {
    for (unsigned int Position = m_LogData.size() - NumOfLastEntries;
                         Position < m_LogData.size(); ++Position)
    {
        wprintw(win, (m_LogData[Position]).c_str());
        wprintw(win, "\n");
    }
    }
}

void Log::Write(const char* text)
{
    m_LogData.push_back(text);
}

void Log::FullscreenRead()
{
    wclear(FULL_WIN);
    wrefresh(FULL_WIN);

    Read(LINES, FULL_WIN);
    wrefresh(FULL_WIN);

    getch();

    wclear(FULL_WIN);
    wrefresh(FULL_WIN);
}
