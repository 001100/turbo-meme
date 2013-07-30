#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>

#include "globals.h"
#include "curses_output.h"

void Draw(wType win, std::string text);
void Draw(wType win, int ly, int lx, std::string text);
void Refresh(wType win);
void InitWindows();
void Clear(wType win);

#endif // OUTPUT_H
