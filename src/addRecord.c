#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "time.h"

#include "../include/showInfo.h"
#include "../include/module.h"
#include "../include/fileControl.h"

void addRecord(void){
    char date[11]="    /  /  "; //日期格式
    char reason[1024]="\0";     //事由
    int i=0,price=0,key=0;
    showDate(date);
    while(1){
        key=getch();    //擷取按鍵
        if(key>=48&&key<=57){   //判斷是否輸入數字
            if(i==4||i==7)i++;  //判斷是否為第4、7位,避開斜線
            date[i++]=key;      //將數字寫入到對應的位置
            showDate(date);
        }
        if(key==8){     //判斷是否輸入backspace
            i--;                //將位數回調一位
            if(i==4||i==7)i--;  //判斷是否為第4、7位,避開斜線
            date[i]=' ';        //將此位置歸為空格
            showDate(date);
        }
        if(i>9){break;}     //判斷日期輸入完成自動往下一階段
        if(key==13){        //當使用者沒有輸入完整日期，則自動填入當日日期
            if(date[9]==' '){   
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
    scanf("%[^\n]", reason);
    fflush(stdin);
    showPrice();
    scanf("%d",&price);
    fflush(stdin);
    showAll(date,reason,&price);
    key=0;
    while(key==0){  //使用者確認資料，選擇重新輸入或確認寫入
        key=getch();
        if(key=='n'){addRecord();}
        else{writeFile(date,reason,&price);}
    }
}