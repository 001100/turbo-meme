#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

#include <ncurses.h>

// Debug macross
#define _DBG false

// Field size.
extern const int g_WIDTH;// = 11;
extern const int g_HEIGHT;// = 11;

// Field area.
extern const int g_AREA;// = g_WIDTH*g_HEIGHT;

// Ingame screens.
enum sType {
    MAIN_SCR,       // MAIN+LOG windows
    TITLE_SCR
};

// Global windows pointers
extern WINDOW* MAIN_WIN;
extern WINDOW* LOG_WIN;
extern WINDOW* FULL_WIN;
extern WINDOW* INFO_WIN;

#endif // GLOBALS_H_INCLUDED
