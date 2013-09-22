#include "keyboard_input.h"

#include <string>
#include <cstdlib> // For exit().

#include <ncurses.h> // Here for getch().

#include "game.h"
#include "field.h"
#include "player.h"
#include "log.h"
#include "output.h"

static bool KeyCheck = false;
static int pressedKey;

void MainScreenKeys()
{
    switch (pressedKey)
        {
        // Exit key
        case 'q': GAME->SetQuitStatus(true); break;
        // Restart the game
        case 'r': GAME->RestartGame(); break;
        // Movement keys
        case 'u': PLAYER->TileMovement(-1, 0); break;
        case 'm': PLAYER->TileMovement( 1, 0); break;
        case 'h': PLAYER->TileMovement( 0,-1); break;
        case 'k': PLAYER->TileMovement( 0, 1); break;
        // Draw tile passability map.
        case 'p': DrawPassabilityField(); break;
        // Display fullscreen log.
        case 'l': Log::FullscreenRead(); break;
        // Camera movement
        case 'x':     SetFreeCameraMod(); break;
        case KEY_UP:    SetOffset(-1, 0); break;
        case KEY_DOWN:  SetOffset( 1, 0); break;
        case KEY_LEFT:  SetOffset( 0,-1); break;
        case KEY_RIGHT: SetOffset( 0, 1); break;
        // If no proper key inputed.
        default:
            KeyCheck = true;
            break;
        }
}

void TitleScreenKeys()
{
    switch (pressedKey)
        {
        // Use action for coresponding selection
        case '\n': TitleScreenActions(); break;
        // Change selected menu position.
        case KEY_UP:   GAME->TitleScreenMenu.SetSelection(KEY_UP);   break;
        case KEY_DOWN: GAME->TitleScreenMenu.SetSelection(KEY_DOWN); break;
        // If no proper key inputed.
        default:
            KeyCheck = true;
            break;
        }
}

void KeyPresses(sType screen)
{
do {
    pressedKey = getch();
    KeyCheck = false;

    switch (screen) {
        case MAIN_SCR:  MainScreenKeys();  break;
        case TITLE_SCR: TitleScreenKeys(); break;
    }
} while (KeyCheck);
}
