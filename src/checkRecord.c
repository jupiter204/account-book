#include "module.h"
//#include "fileControl.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
int readFile(char ***result){
    char *tmp=(char*)malloc(sizeof(char)*100);
    int row=1;
    FILE *file=fopen("../account-book.csv","r");
    while (fscanf(file,"%s",tmp)!=EOF){
        if(row==1)*result=(char**)malloc(sizeof(char*));
        else *result=(char**)realloc(*result,row*sizeof(char*));
        (*result)[row-1]=(char*)malloc(sizeof(char)*strlen(tmp));
        strcpy((*result)[row-1],tmp);
        row++;
    }
    
    free(tmp);
    return row-=2;
}
void showIndex(char *lock,char **record,int ch,int row,int max){
    system("cls");
    for(int i=row;i<row+10&&i<=max;i++){
        printf("%c %s\n",lock[i%10],record[i]);
    }
}
void checkRecord(void){
    char **record;
    int max=0,ch=0,row=0;
    char lock[10];
    memset(lock, ' ', sizeof(lock));
    lock[0]='*';
    max=readFile(&record);
    showIndex(lock,record,ch,row,max);
    while(1){
        int key=0;
        key=getch();    //擷取鍵盤按鍵
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
            lock[ch%10]='*';
            row=ch/10*10;
            showIndex(lock,record,ch,row,max);
        }
    }
}
void main(void){
    system("chcp 65001");
    checkRecord();
    system("pause");
}