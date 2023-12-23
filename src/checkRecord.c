#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#include "windows.h"

#include "../include/module.h"
#include "../include/fileControl.h"
/*
    顯示檔案紀錄
    lock為選擇的指示陣列,type字元陣列,指標傳入
    record為全部記錄,type二為字元陣列,二重指標傳入
    row為顯示的起始位置,type整數,值傳入
    max為最大顯示紀錄,type整數,值傳入
*/
void showCheck(char *lock,char **record,int row,int max){
    system("cls");
    printf("按下Enter鍵刪除紀錄，按下Esc鍵退出\n");
    printf("%s\n",record[0]);
    for(int i=row+1;i<=row+10&&i<=max;i++){ //每次顯示10筆資料但不超過最大值
        if(record[i]==NULL){printf("%c---已刪除---\n",lock[(i-1)%10]);continue;}    //如果要顯示的值為NULL,則改為顯示已刪除
        printf("%c %s\n",lock[(i-1)%10],record[i]);
    }
}
void checkRecord(void){
    char **record;
    int max=0,ch=0,row=0;
    char lock[10];
    memset(lock, ' ', sizeof(lock));    
    lock[0]='>';
    max=readFile(&record);
    showCheck(lock,record,row,max);
    while(1){
        int key=0;
        key=getch();  //擷取鍵盤按鍵  
        if(key==224){   //按下方向鍵時一次會傳入兩個值，第一次固定224
            key=getch();    //第二次擷取，up72down80
            if(key==72){
                ch--;
                if(ch<0)ch=0;
            }
            if(key==80){
                ch++;
                if(ch>max-1){ch=max-1;}
            }
            memset(lock, ' ', sizeof(lock));   //每次變動前先將選則陣列清空
            lock[ch%10]='>';
            row=ch/10*10;
            showCheck(lock,record,row,max);
        }
        if(key==13){
            system("cls");
            printf("是否確認刪除以下資料(y/N)\n");
            printf("%s",record[ch+1]);
            while(1){
                key=getch();
                if(key=='y'){   //當按下y時,將選擇到的紀錄設定為NULL
                    record[ch+1]=NULL;
                    coverFile(&record,max); //寫入變更過的檔案
                    break;
                }
                else{break;}
            }
            showCheck(lock,record,row,max);
        }
        if(key==27){free(record);break;}    //按下Esc鍵退出本功能
    }
}