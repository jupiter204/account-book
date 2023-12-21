#include "fileControl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _file "./account-book.csv"

void checkFile(void){
    FILE *file=fopen(_file,"r");
    if(file==NULL){
        fclose(file);
        FILE *file=fopen(_file,"a");
        fprintf(file,"\xEF\xBB\xBF");
        fprintf(file,"日期,事由,金額\n");
        fclose(file);
    }
    else fclose(file);
}
void writeFile(char *date,char *reason,int *price){
    char buffer[10];
    itoa(*price,buffer,10);
    checkFile();
    FILE *file=fopen(_file,"a");
    fprintf(file,date);
    fprintf(file,",");
    fprintf(file,reason);
    fprintf(file,",");
    fprintf(file,buffer);
    fprintf(file,"\n");
    fclose(file);
}
int readFile(char ***result){
    char *tmp=(char*)malloc(sizeof(char)*100);
    int row=1;
    FILE *file=fopen(_file,"r");
    if(file==NULL){return -1;}
    while (fscanf(file,"%s",tmp)!=EOF){
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
void coverFile(char ***result,int max){
    FILE *file=fopen(_file,"w");
    fprintf(file,"\xEF\xBB\xBF");
    for(int i=0;i<max;i++){
        if((*result)[i]==NULL){continue;}
        fprintf(file,"%s\n",(*result)[i]);
    }
    fclose(file);
}
// void main(void){//test
//     char date[11]="2023/12/10",reason[1024]="這是一行測試字串";
//     int price=275;
//     writeFile(date,reason,&price);
// }