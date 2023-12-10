#include "showInfo.h"
#include "stdio.h"
#include "windows.h"
void showDate(char *date){
    system("cls");
    printf("輸入日期，按下迴車鍵確認(不輸入則為今日):\n");
    for(int i=0;i<10;i++){
        printf("%c",date[i]);
    }
    putchar('\n');
}
void showReason(void){
    system("cls");
    printf("輸入事由，按下迴車鍵確認:\n");
}
void showPrice(void){
    system("cls");
    printf("輸入金額，按下迴車鍵確認:\n");
}
void showAll(char *date,char *reason,int *price){
    system("cls");
    printf("日期:%s 事由:%s 金額:%d\n",date,reason,*price);
    printf("是否將此紀錄新增至檔案?(Y/n)");
}
