#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

// Field size.
const int g_WIDTH = 11;
const int g_HEIGHT = 11;

// Field area.
const int g_AREA = g_WIDTH*g_HEIGHT;

// Enum for ingame screens.
enum sType {
    MAIN_SCR,       // MAIN+LOG windows
    TITLE_SCR
};

#endif // GLOBALS_H_INCLUDED
