#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "windows.h"

void showIndex(char lock[4]){
    system("cls");
    printf("歡迎使用簡易記帳簿\n請使用方向鍵選擇功能，按下迴車建確認選擇\n");
    printf("(%c) 鍵入紀錄\n",lock[0]);
    printf("(%c) 查看紀錄\n",lock[1]);
    printf("(%c) 刪除紀錄\n",lock[2]);
    printf("(%c) 離開應用\n",lock[3]);
}
int main(int argc,char argv[]){
    system("chcp 65001");//設定終端機編碼以利各使用者執行
    char lock[4]={'*',' ',' ',' '};
    showIndex(lock);
    int ch=0;
    while(1){
        int k=0;
        k=getch();
        if(k==224){
            memset(lock, ' ', sizeof(lock)); 
            k=getch();//up72down80
            if(k==72&&ch>0){ch--;}
            if(k==80&&ch<3){ch++;}
            lock[ch]='*';
            showIndex(lock);
        }
        if(k==13){
            switch (ch){
            case 0:
                system("cls");printf("你選擇了功能1，將於1秒鐘後返回");Sleep(1000);
                break;
            case 1:
                system("cls");printf("你選擇了功能2，將於1秒鐘後返回");Sleep(1000);
                break;
            case 2:
                system("cls");printf("你選擇了功能3，將於1秒鐘後返回");Sleep(1000);
                break;
            case 3:
                system("cls");printf("你選擇了功能4，將於1秒鐘後返回");Sleep(1000);
                break;
            }
            showIndex(lock);
        }
    }
    system("pause");
    return 0;
}