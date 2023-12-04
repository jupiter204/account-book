#include "showInfo.h"
#include "stdio.h"
#include "windows.h"
void showIndex(char *lock,char **text){
    system("cls");
    printf("歡迎使用本系統\n");
    printf("請使用方向鍵選擇功能，按下迴車建確認選擇\n");
    for(int i=0;i<sizeof(lock)/2;i++){
        printf("(%c) %s\n",lock[i],text[i]);
    }
}
void showDate(char *date){
    system("cls");
    printf("輸入日期按下迴車鍵確認(不輸入則為今日):\n");
    for(int i=0;i<10;i++){
        printf("%c",date[i]);
    }
    putchar('\n');
}
