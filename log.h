#ifndef LOG_H
#define LOG_H

#include <string>
#include <vector>
#include "ncurses.h"

#include "output.h"

// TODO: Log have unrestricted storage - bad for memory.

extern WINDOW* LOG_WIN;
extern WINDOW* FULL_WIN;

class Log
{
    private:
        // Log strings objects storage.
        static std::vector<std::string> m_LogData;

    protected:
    public:
        static void Write(const char* text);
        static void Read(unsigned int NumOfLastEntries, WINDOW* win = LOG_WIN);
        static void FullscreenRead();
};

#endif // LOG_H
