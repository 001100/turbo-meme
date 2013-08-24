#ifndef OUTPUT_H
#define OUTPUT_H

void InitWindows();
void DrawInfoWin();
void IsTerminalResized();
void DrawField();
void SetOffset(int y, int x);
void CheckFieldToScreenSize(int& maxY, int& maxX);
void DrawPassabilityField();
void CenterOnPlayer();
void SetFreeCameraMod();

#endif // OUTPUT_H
