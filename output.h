#ifndef OUTPUT_H
#define OUTPUT_H

void InitWindows();
void DrawInfoWin();
void IsTerminalResized();
int DrawField();
int SetOffset(int y, int x);
void CheckFieldToScreenSize(int& maxY, int& maxX);

#endif // OUTPUT_H
