#include <windows.h>
#include <stdio.h>

#define MAXLEN 100   //̰�������ĳ���Ϊ100

int snakeRows[MAXLEN ],snakeCols[MAXLEN ];

int len ;  //̰���ߵĵ�ǰ����

int direction;    // 0: up, 1: down, 2: left, 3: right


void initSnanke(){
    len = 4;  //̰���ߵĵ�ǰ����
    direction = 2; //��ʼ�˶���������
    int i;
    for(i = 0; i < len ; i++){
        snakeCols[i] = 3 + i;  //���ڵ�3��
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

     // �����˶�
     int i;
     for( i = len - 1;  i > 0;  i--){
          snakeRows [i] = snakeRows [i - 1];
          snakeCols [i] = snakeCols [i - 1];
     }

     // ��ͷ�˶�

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


