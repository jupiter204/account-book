#include "conio.h"
#include "stdio.h"
void main(void){
    while(1){
        int key=0;
        key=getch();
        if(key){
            printf("%d\n",key);
        }
    }
}