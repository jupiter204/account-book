#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "windows.h"

#include "../include/module.h"
/*  
    11-18,此段會在終端機顯示使用者介面,需要引入兩個變數
    lock為選擇的指示陣列,type字元陣列,指標傳入
    text為需要顯示的選項,type字元陣列,指標傳入
*/
void showIndex(char *lock,char **text){
    system("cls");
    printf("歡迎使用本系統\n");
    printf("請使用方向鍵選擇功能，按下迴車建確認選擇\n");
    for(int i=0;i<3;i++){
        printf("(%c) %s\n",lock[i],text[i]);
    }
}
int main(void){
    system("chcp 65001");   //設定終端機的編碼為utf-8BOM
    char lock[3]={'*',' ',' '};
    char *text[3]={"新增紀錄","查看及刪除紀錄","結束程式"};
    showIndex(lock,text);
    int ch=0;   //紀錄使用者選擇的編號
    while(1){
        int key=0;      //暫存使用者鍵盤輸入的編碼
        key=getch();    //擷取鍵盤按鍵
        if(key==224){   //按下方向鍵時一次會傳入兩個值，第一次固定224
            memset(lock, ' ', sizeof(lock));    //每次變動前先將選則陣列清空
            key=getch();    //第二次擷取，上為72下為80
            if(key==72&&ch>0){ch--;}
            if(key==80&&ch<3){ch++;}
            lock[ch]='*';
            showIndex(lock,text);
        }
        if(key==13){    //判斷是否為Enter鍵
            switch (ch){    //依照使用者選擇編號呼叫對應的副程式
            case 0:
                system("cls");addRecord();
                break;
            case 1:
                system("cls");checkRecord();
                break;
            case 2:
                system("cls");printf("Bye Bye!!");Sleep(1000);
                return 0;
            }
            showIndex(lock,text);
        }
    }
    return 0;
}