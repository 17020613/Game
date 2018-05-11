#include <iostream>
#include "console.h"
#include "begin.h"
#include "Seting.h"
#include "Run.h"
#include <time.h>
#include <conio.h>

using namespace std;

void run(){

    srand(time(NULL));
    Snake S;
    HoaQua HQ;
    KhoiTao(S,HQ);
    int ma = 0;
    int thoigianSleep = 300;
    do{
        HienThi(S,HQ);
        DieuKhien(S);
        ma = XuLy(S,HQ,thoigianSleep);
        if(ma == -1){
            clrscr();
            gotoXY(40,10);
            TextColor(11);
            cout << "GAME OVER !" << endl;
            gotoXY(40,12);
            TextColor(12);
            cout << "Diem cua ban: " ;
            TextColor(13);
            cout << S.diem << endl;
            gotoXY(40,14);
            TextColor(7);
            cout << "An phim Enter de quay lai menu." << endl;
            while(_getch() != 13);
                break;
        }
        Sleep(thoigianSleep);
        clrscr();
    }while(1);
}
