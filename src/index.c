#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "windows.h"
#include "module.h"

void showIndex(char *lock,char **text){
    system("cls");
    printf("歡迎使用本系統\n");
    printf("請使用方向鍵選擇功能，按下迴車建確認選擇\n");
    for(int i=0;i<sizeof(lock)/2;i++){
        printf("(%c) %s\n",lock[i],text[i]);
    }
}
int main(int argc,char argv[]){
    system("chcp 65001");   //設定終端機編碼以利各使用者執行
    char lock[4]={'*',' ',' ',' '};
    char *text[4]={"新增紀錄","查看紀錄","刪除紀錄","儲存離開"};
    showIndex(lock,text);
    int ch=0;
    while(1){
        int key=0;
        key=getch();    //擷取鍵盤按鍵
        if(key==224){   //按下方向鍵時一次會傳入兩個值，第一次固定224
            memset(lock, ' ', sizeof(lock)); 
            key=getch();    //第二次擷取，up72down80
            if(key==72&&ch>0){ch--;}
            if(key==80&&ch<3){ch++;}
            lock[ch]='*';
            showIndex(lock,text);
        }
        if(key==13){
            switch (ch){
            case 0:
                system("cls");addRecord();
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
            showIndex(lock,text);
        }
    }
    system("pause");
    return 0;
}