#include <windows.h>
#include <stdio.h>
#define SIZE 8

void turnOnLights(int row, int n){
    int i;
    for(i = 0; i <= n; i++){
        turnOn(row,i);
    }
}

void showRunningLight(int row){
    int num;
    for(num = 0; num < SIZE; num++){
        clearScreen();
        turnOnLights(row,num);
    }

    for(num = SIZE - 1; num >= 0; num--){
        clearScreen();
        turnOnLights(row,num);
    }

}



int main(){
    initGame(SIZE);

    while(1){

        showRunningLight(0);
    }

    return 0;
}


