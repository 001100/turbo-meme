#include "output.h"


void Draw(wType win, std::string text) {CursesOutput::CursesDraw(win, text);}
void Draw(wType win, int ly, int lx, std::string text)
    {CursesOutput::CursesDraw(win, ly, lx, text);}
void Refresh(wType win) {CursesOutput::CursesRefresh(win);}
void Clear(wType win) {CursesOutput::CursesClear(win);}
void InitWindows() {CursesOutput::InitCursesWindows();}
