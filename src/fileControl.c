#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"

#include "../include/fileControl.h"

#define _file "./account-book.csv"

int checkFile(void){
    FILE *file=fopen(_file,"r");
    if(file==NULL){
        fclose(file);
        FILE *file=fopen(_file,"a");
        if(file==NULL){system("cls");printf("開啟檔案時發生錯誤，請檢查是否已經開啟檔案\n如果以開啟檔案，請關閉後再嘗試");Sleep(2000);return 1;}
        fprintf(file,"\xEF\xBB\xBF");
        fprintf(file,"日期,事由,金額\n");
        fclose(file);
    }
    else {
        FILE *file=fopen(_file,"a");
        if(file==NULL){system("cls");printf("開啟檔案時發生錯誤，請檢查是否已經開啟檔案\n如果以開啟檔案，請關閉後再嘗試");Sleep(2000);return 1;}
        fclose(file);
    }
    return 0;
}
/*  
    28-40新增記錄至檔案
    date為日期格式,type字元陣列,傳入指標
    reason為事由,type字元陣列,傳入指標
    price為金額,type整數,傳入指標
*/
void writeFile(char *date,char *reason,int *price){
    char buffer[10];
    itoa(*price,buffer,10);
    if(checkFile())return;
    FILE *file=fopen(_file,"a");
    fprintf(file,date);
    fprintf(file,",");
    fprintf(file,reason);
    fprintf(file,",");
    fprintf(file,buffer);
    fprintf(file,"\n");
    fclose(file);
}
/*
    45-61讀取檔案
    result為資料暫存陣列,type二為陣列,二重指標傳入
*/
int readFile(char ***result){
    if(checkFile())return -1;
    char *tmp=(char*)malloc(1024*sizeof(char));
    int row=1;
    FILE *file=fopen(_file,"r");
    fread(tmp, 1, 3, file);
    if (tmp[0] == '\xEF' && tmp[1] == '\xBB' && tmp[2] == '\xBF') {fseek(file, 3, SEEK_SET);}
    else {fseek(file, 0, SEEK_SET);}
    while (fgets(tmp, 1024, file)!=NULL){
        if(tmp[strlen(tmp)-1]=='\n'){tmp[strlen(tmp)-1]='\0';}
        if(row==1)*result=(char**)malloc(sizeof(char*));
        else *result=(char**)realloc(*result,row*sizeof(char*));
        (*result)[row-1]=(char*)malloc(sizeof(char)*strlen(tmp));
        strcpy((*result)[row-1],tmp);
        row++;
    }
    free(tmp);
    fclose(file);
    return row-=2;
}
/*
    67-75覆蓋檔案
    result為資料暫存陣列,type二為陣列,二重指標傳入
    max為最大寫入行數,type整數,值傳入
*/
void coverFile(char ***result,int max){
    FILE *file=fopen(_file,"w");
    fprintf(file,"\xEF\xBB\xBF");
    for(int i=0;i<max;i++){
        if((*result)[i]==NULL){continue;}
        fprintf(file,"%s\n",(*result)[i]);
    }
    fclose(file);
}