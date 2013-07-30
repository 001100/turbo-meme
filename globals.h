#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

// Field size
const int g_WIDTH = 11;
const int g_HEIGHT = 11;
// Field area
const int g_AREA = g_WIDTH*g_HEIGHT;

// Enum for game windows
enum wType {
    MAIN_WIN,
    LOG_WIN,
    FULL_WIN
};

#endif // GLOBALS_H_INCLUDED
