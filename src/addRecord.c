#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "time.h"
#include "showInfo.h"
#include "module.h"

void addRecord(void){
    char date[10]={"    /  /  "};
    char reason[100]="\0";
    int i=0,price=0,key=0;
    showDate(date);
    while(1){
        key=getch();
        if(key>=48&&key<=57){   //擷取按鍵，判斷是否輸入數字
            if(i==4||i==7)i++;
            date[i++]=key;
            showDate(date);
        }
        if(i>9){break;}
        if(key==13){
            if(date[0]==' '){   //如果使用者沒有輸入日期，則自動填入當日日期
                time_t rawtime;
                struct tm *info;
                rawtime=time(NULL);
                info = localtime( &rawtime );
                int year=info->tm_year+1900;int month=info->tm_mon+1;int day=info->tm_mday;
                date[0]=((year/1000)%10)+48;date[1]=((year/100)%10)+48;date[2]=((year/10)%10)+48;date[3]=((year/1)%10)+48;
                date[5]=((month/10)%10)+48;date[6]=((month/1)%10)+48;date[8]=((day/10)%10)+48;date[9]=((day/1)%10)+48;
                showDate(date);
            }
            break;
        }
    }
    showReason();
    scanf("%s",reason);
    showPrice();
    scanf("%d",&price);
    showAll(date,reason,&price);
    key=0;
    while(key==0){  //使用者確認資料，選擇重寫或確認
        key=getch();
        if(key=='n'){addRecord();}
        else{}
    }
}