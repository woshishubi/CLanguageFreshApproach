#include <windows.h>
#include <stdio.h>

#define MAXLEN 100   //贪吃蛇最大的长度为100

int snakeRows[MAXLEN ],snakeCols[MAXLEN ];

int len ;  //贪吃蛇的当前长度

int direction;    // 0: up, 1: down, 2: left, 3: right


void initSnanke(){
    len = 4;  //贪吃蛇的当前长度
    direction = 2; //初始运动方向向下
    int i;
    for(i = 0; i < len ; i++){
        snakeCols[i] = 3 + i;  //都在第3列
        snakeRows[i] = 0;
    }

}

void showSnake(){
    clearScreen();
    int i ;
    for( i = 0; i < len; i++){
        turnOn(snakeRows[i],snakeCols[i]);
    }
}

void upDateSnake(){
     char key = getKey();
     switch(key){
         case 'w':direction = 0;break;
         case 's':direction = 1;break;
         case 'a':direction = 2;break;
         case 'd':direction = 3;break;
     }

     // 蛇身运动
     int i;
     for( i = len - 1;  i > 0;  i--){
          snakeRows [i] = snakeRows [i - 1];
          snakeCols [i] = snakeCols [i - 1];
     }

     // 蛇头运动

    if(direction == 0){
        snakeRows[0]--;
    }

    if(direction == 1){
        snakeRows[0]++;
    }

    if(direction == 2){
        snakeCols[0]--;
    }

    if(direction == 3){
        snakeCols[0]++;
    }


}


int main(){
    initGame(8);
    initSnanke();
    while(1){
        showSnake();
        upDateSnake();
    }

    return 0;
}


