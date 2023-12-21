#include "module.h"
#include "fileControl.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#include "windows.h"

void showCheck(char *lock,char **record,int ch,int row,int max){
    system("cls");
    printf("按下Enter鍵刪除紀錄，按下Esc鍵退出\n");
    printf("%s\n",record[0]);
    for(int i=row+1;i<=row+10&&i<=max;i++){
        if(record[i]==NULL){printf("%c---已刪除---\n",lock[(i-1)%10]);continue;}
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
    if(max== -1){printf("尚未有紀錄，3秒後返回");Sleep(3000);return;}
    showCheck(lock,record,ch,row,max);
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
                if(ch<max){ch++;}
            }
            memset(lock, ' ', sizeof(lock));
            lock[ch%10]='>';
            row=ch/10*10;
            showCheck(lock,record,ch,row,max);
        }
        if(key==13){
            system("cls");
            printf("是否確認刪除以下資料(y/N)\n");
            printf("%s",record[ch+1]);
            while(1){
                key=getch();
                if(key=='y'){
                    record[ch+1]=NULL;
                    coverFile(&record,max);
                    break;
                }
                else{break;}
            }
            showCheck(lock,record,ch,row,max);
        }
        if(key==27){return;}
    }
}