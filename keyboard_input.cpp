#include "keyboard_input.h"
extern Field* FIELD;
extern Player* PLAYER;

void KeyboardInput::KeyPresses()
{
    bool KeyCheck = false;

    do {
    int pressedKey = getch();
    KeyCheck = false;
    switch (pressedKey)
    {
        // Exit key
        case 'q': exit(0);
        // Movement keys
        case 'u': PLAYER->TileMovement(-1, 0); break;
        case 'm': PLAYER->TileMovement( 1, 0); break;
        case 'h': PLAYER->TileMovement( 0,-1); break;
        case 'k': PLAYER->TileMovement( 0, 1); break;
        // Draw tile passability map.
        case 'p': FIELD->DrawPassabilityField(); break;
        // Display fullscreen log.
        case 'l': Log::FullscreenRead(); break;
        // If no proper key inputed.
        default:
            KeyCheck = true;
            break;
    }
    } while (KeyCheck);
}
