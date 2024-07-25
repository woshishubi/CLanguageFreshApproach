#include <windows.h>
#include <stdio.h>

void setConsoleFontSize(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX fontInfo = {0};
    fontInfo.cbSize = sizeof(fontInfo);
    fontInfo.dwFontSize.X = x;
    fontInfo.dwFontSize.Y = y;
    fontInfo.FontFamily = FF_DONTCARE;
    fontInfo.FontWeight = FW_NORMAL;

    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
}


int main(){
    initGame(8);
    setConsoleFontSize(48, 48);

    turnOn (0,4);

    turnOn (0,5);

    turnOn (0,6);
    return 0;
}


