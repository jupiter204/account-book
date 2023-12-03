#include "stdlib.h"
#include "stdio.h"
#include "conio.h"

int main(int argc,char argv[]){
    system("chcp 65001");//設定終端機編碼以利各使用者執行
    system("cls");
    printf("歡迎使用簡易記帳簿\n");
    while(1){
        printf("請選擇功能: (1)鍵入紀錄 (2)查看紀錄 (3)刪除紀錄 (4)離開應用");
        switch (getch()){
        case '1':
            /* code */
            break;
        case '2':
            /* code */
            break;
        case '3':
            /* code */
            break;
        case '4':
            /* code */
            break;
        default:
            system("cls");
            printf("本系統無此功能，請選擇正確的功能\n");
            break;
        }
    }
    system("pause");
    return 0;
}