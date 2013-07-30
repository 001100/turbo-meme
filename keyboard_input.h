#ifndef KEYBOARD_INPUT_H
#define KEYBOARD_INPUT_H

#include <string>
#include <cstdlib> // For exit().

#include <ncurses.h> // Here for getch().

#include "tile.h"
#include "field.h"
#include "player.h"

class KeyboardInput
{
    private:
    protected:
    public:
        static void KeyPresses();
};

#endif // KEYBOARD_INPUT_H
