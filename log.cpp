#include "log.h"

std::vector<std::string> Log::m_LogData;

void Log::Read(unsigned int NumOfLastEntries, wType win)
{
if (NumOfLastEntries > m_LogData.size())
    {
    for (unsigned int Position = 0; Position < m_LogData.size(); ++Position)
    {
        Draw(win, m_LogData[Position]);
        Draw(win, "\n");
    }
    }
else
    {
    for (unsigned int Position = m_LogData.size() - NumOfLastEntries;
                         Position < m_LogData.size(); ++Position)
    {
        Draw(win, m_LogData[Position]);
        Draw(win, "\n");
    }
    }
}

void Log::Write(const char* text)
{
    m_LogData.push_back(text);
}

void Log::FullscreenRead()
{
    Read(LINES, FULL_WIN);
    Refresh(FULL_WIN);

    getch();

    Clear(FULL_WIN);
    Refresh(FULL_WIN);
}
