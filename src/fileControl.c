#include "fileControl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkFile(void){
    FILE *file=fopen("./accoint-book.csv","r");
    if(file==NULL){
        fclose(file);
        FILE *file=fopen("./accoint-book.csv","a");
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
    FILE *file=fopen("./accoint-book.csv","a");
    fprintf(file,date);
    fprintf(file,",");
    fprintf(file,reason);
    fprintf(file,",");
    fprintf(file,buffer);
    fprintf(file,"\n");
    fclose(file);
}
// void main(void){//test
//     char date[11]="2023/12/10",reason[1024]="這是一行測試字串";
//     int price=275;
//     writeFile(date,reason,&price);
// }