#ifndef OUTPUT_H
#define OUTPUT_H

void InitWindows();
void DrawInfoWin();
void IsTerminalResized();
int DrawField();
int SetOffset(int y, int x);
int CheckFieldToScreenSize(int& y, int& x);

#endif // OUTPUT_H
