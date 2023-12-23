#include "stdio.h"
#include "windows.h"

#include "../include/showInfo.h"

void showDate(char *date){  //顯示使用者輸入日期的介面,date為日期格式陣列,type字元陣列,傳入指標
    system("cls");
    printf("輸入日期，按下迴車鍵確認(不輸入則為今日):\n");
    for(int i=0;i<10;i++){
        printf("%c",date[i]);
    }
    putchar('\n');
}
void showReason(void){      //顯示使用者輸入事由的介面,沒有傳入值
    system("cls");
    printf("輸入事由，按下迴車鍵確認:\n");
}
void showPrice(void){       //顯示使用者輸入金額的介面,沒有傳入值
    system("cls");
    printf("輸入金額，按下迴車鍵確認:\n");
}
/*  23-27顯示使用者輸入金額的介面
    date為日期格式,type字元陣列,傳入指標
    reason為事由,type字元陣列,傳入指標
    price為金額,type整數,傳入指標
*/
void showAll(char *date,char *reason,int *price){   
    system("cls");
    printf("日期:%s 事由:%s 金額:%d\n",date,reason,*price);
    printf("是否將此紀錄新增至檔案?(Y/n)");
}
