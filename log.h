#ifndef LOG_H
#define LOG_H

#include <string>
#include <vector>
//#include "ncurses.h"

#include "globals.h"

// TODO: Log has unrestricted storage - bad for memory.

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
