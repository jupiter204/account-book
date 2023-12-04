#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "windows.h"
#include "time.h"
#include "showInfo.h"
#include "module.h"

void addRecord(void){
    char date[10]={"    /  /  "};
    int i=0;
    showDate(date);
    while(1){
        int key1=0;
        key1=getch();
        if(key1>=48&&key1<=57){
            if(i==4||i==7)i++;
            date[i++]=key1;
            showDate(date);
        }
        if(i>9){break;}
        if(key1==13){
            if(date[0]==' '){
                time_t rawtime;
                struct tm *info;
                rawtime=time(NULL);
                info = localtime( &rawtime );
                int year=info->tm_year+1900;int month=info->tm_mon+1;int day=info->tm_mday;
                date[0]=((year/1000)%10)+48;date[1]=((year/100)%10)+48;date[2]=((year/10)%10)+48;date[3]=((year/1)%10)+48;
                date[5]=((month/10)%10)+48;date[6]=((month/1)%10)+48;date[8]=((day/10)%10)+48;date[9]=((day/1)%10)+48;
            }
            showDate(date);
            break;
        }
    }
}