#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

#include <ncurses.h>

// Debug macross
#define _DBG false

// Field size.
extern const int g_WIDTH;
extern const int g_HEIGHT;

// Field area.
extern const int g_AREA;// = g_WIDTH*g_HEIGHT;

// Ingame screens.
enum sType {
    MAIN_SCR,       // MAIN+LOG+INFO windows
    TITLE_SCR
};

// Global windows pointers
extern WINDOW* MAIN_WIN;
extern WINDOW* LOG_WIN;
extern WINDOW* FULL_WIN;
extern WINDOW* INFO_WIN;

// Colors
enum Color {
    NO_COLOR, // Color pair in ncurses can't be zero
    RED_ON_BLACK,
    WHITE_ON_BLACK,
    BLUE_ON_BLACK,
    GREEN_ON_BLACK,
    YELLOW_ON_BLACK,

    COLOR_COUNT
};

#endif // GLOBALS_H_INCLUDED
