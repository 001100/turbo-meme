#ifndef LOG_H
#define LOG_H

#include <string>
#include <vector>
#include "ncurses.h"

#include "output.h"

// TODO: Log have unrestricted storage - bad for memory.

class Log
{
    private:
        // Log strings objects storage.
        static std::vector<std::string> m_LogData;

    protected:
    public:
        static void Write(const char* text);
        static void Read(unsigned int NumOfLastEntries, wType win = LOG_WIN);
        static void FullscreenRead();
};

#endif // LOG_H
