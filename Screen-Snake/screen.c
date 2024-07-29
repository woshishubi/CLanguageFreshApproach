#include"screen.h"

#include <windows.h>

#define true 1
#define screenMaxsize 24




/*
  Analog electronic screen project
  Created by xushu on 2021/7/30

*/


int screensize = 8;

char screenValue[screenMaxsize][screenMaxsize];

/*设置窗口位置和大小*/
void console()
{
    SetConsoleTitle("Screen");

    HANDLE hConsole  = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bInfo;
    GetConsoleScreenBufferInfo(hConsole , &bInfo );// 获取窗口缓冲区信息
    COORD size = {80, 40};
    SetConsoleScreenBufferSize(hConsole ,size); // 重置缓冲区大小
    SMALL_RECT rect = {0,0, 120, 60};
    SetConsoleWindowInfo(hConsole ,1 ,&rect);// 重置窗口大小和位置
    CONSOLE_CURSOR_INFO cursorInfo = {1, 0};
    SetConsoleCursorInfo(hConsole , &cursorInfo);
}



/*设置光标位置*/
void gotoxy(int x,int y)
{
    COORD  pos = {x,y};
    HANDLE handle;
    handle=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle,pos);


    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = 0;
    cursor.dwSize = sizeof(cursor);
    SetConsoleCursorInfo(handle, &cursor);
}

/*初始化屏幕*/
void initScreen(){

    int i ,j = 0;

    for(i = 0; i < screenMaxsize; i++){
        for(j = 0 ; j < screenMaxsize; j++){
            screenValue[i][j]  = 0;

        }

    }

}



/*显示屏幕*/
void showScreen(){
    gotoxy(0,0);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    int i ,j = 0;
    printf("    ");
    for(i = 0; i < screensize; i++){
       if(i < 10)
            printf("%d ",i);
       else{
            printf("%d",i);
       }

    }

    printf("\n");
    for(i = 0; i < screensize; i++){

        printf("%2d\n",i);

    }


    printf("\n");

    for( i = 0; i < screensize; i++){
        for(j = 0; j < screensize;j++){
            gotoxy(2 + 2 * (j + 1), 1 + i);
            if(screenValue[i][j]  != 0){
              SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
              printf("■");


            }
            else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                printf("□");
            }

        }


    }
     printf("\n");

     gotoxy(20,1 + screenMaxsize);

}

/*点亮某行某列的灯*/
void turnOn(int row, int col){

     screenValue[row][col] = 1;
     showScreen();
}





/*初始化屏幕*/
void initGame(int n){
    system("cls");
    console();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);

    if(n < screenMaxsize)
        screensize = n;
    else{
        screensize = screenMaxsize;
    }
    initScreen();
    showScreen();

}



/*清屏*/

void clearScreen(){

    Sleep(500);
    initScreen();
    showScreen();

}




/*获得键值*/

char getKey(){
    char key = 0;

    if (kbhit()) //检测，如果有按键就执行if里面的
    {
        key = getch();//捕获按键

    }

    return key;

}
