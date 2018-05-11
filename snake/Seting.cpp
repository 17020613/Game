#include <iostream>
#include "Seting.h"
#include "console.h"
#include <windows.h>
#include <time.h>
#include <cstring>
#include <conio.h>

#define width1 30
#define width2 60
#define height1 20

using namespace std;

void KhoiTao(Snake &S, HoaQua &HQ){
    S.diem = 0;
    S.level = 1;
    S.dodai = 2;
    S.Dot[0].x = 45;
    S.Dot[0].y = 14;
    S.Dot[1].x = 44;
    S.Dot[1].y = 14;

    S.tt = UP;

    HQ.td.x = rand() % (width2 -1  -width1 - 1 + 1) + (width1 + 1);
    HQ.td.y = rand() % (height1 - 1 - 1 + 1) + 1;
}
void HienThi(Snake S, HoaQua HQ){
    TextColor(10);
    for(int i = 1; i < height1; i++){
        gotoXY(width1,i);
        cout << '|' << endl;
    }
    for(int i = 1; i < height1; i++){
        gotoXY(width2,i);
        cout << '|' << endl;
    }
    for(int i = width1+1; i < width2; i++){
        gotoXY(i,0);
        cout << '_';
    }
    for(int i = width1+1; i < width2; i++){
        gotoXY(i,height1);
        cout << char(295);
    }
    TextColor(5);
    gotoXY(HQ.td.x,HQ.td.y);
    cout << '$';

    TextColor(3);
    gotoXY(S.Dot[0].x,S.Dot[0].y);
    cout << char(233);

    TextColor(4);
    for(int i = 1; i < S.dodai; i++){
        gotoXY(S.Dot[i].x, S.Dot[i].y);
        cout << '*';
    }

    TextColor(6);
    for(int i = width2+5; i < width2+16; i++){
        gotoXY(i,2);
        cout << "-";
    }
    for(int i = width2+5; i < width2+16; i++){
        gotoXY(i,8);
        cout << "-";
    }
    for(int i = 3; i < 8; i++){
        gotoXY(width2+4,i);
        cout << "|";
    }
    for(int i = 3; i < 8; i++){
        gotoXY(width2+16,i);
        cout << "|";
    }
    gotoXY(width2+6,4);
    cout << "Level : " << S.level;
    gotoXY(width2+6,6);
    cout << "Diem : " << S.diem;
}

void DieuKhien (Snake &S){
    for(int i = S.dodai - 1; i > 0; i--){
        S.Dot[i].x = S.Dot[i-1].x;
        S.Dot[i].y = S.Dot[i-1].y;
    }
    if(GetAsyncKeyState(VK_LEFT)){
        S.tt = LEFT;
    }
    else if(GetAsyncKeyState(VK_RIGHT)){
        S.tt = RIGHT;
    }
    else if(GetAsyncKeyState(VK_UP)){
        S.tt = UP;
    }
    else if(GetAsyncKeyState(VK_DOWN)){
        S.tt = DOWN;
    }

    if(S.tt == LEFT)
        S.Dot[0].x --;
    if(S.tt == RIGHT)
        S.Dot[0].x ++;
    if(S.tt == UP)
        S.Dot[0].y --;
    if(S.tt == DOWN)
        S.Dot[0].y ++;
}

int XuLy(Snake &S, HoaQua &HQ, int thoigianSleep){
    if(S.Dot[0].x <= width1 || S.Dot[0].x >= width2
       ||S.Dot[0].y == 0 || S.Dot[0].y == height1)
        return -1;
    for(int i = 1;i < S.dodai; i++){
        if(S.Dot[0].x==S.Dot[i].x&&
           S.Dot[0].y==S.Dot[i].y)
           return -1;
    }
    if(S.Dot[0].x == HQ.td.x && S.Dot[0].y == HQ.td.y){
        S.diem ++;
        S.dodai ++;
        for(int i = S.dodai ; i > 0; i--){
            S.Dot[i] = S.Dot[i-1];
        }

        HQ.td.x = rand() % (width2 -1  -width1 - 1 + 1) + (width1 + 1);
        HQ.td.y = rand() % (height1 - 1 - 1 + 1) + 1;

        if(thoigianSleep >= 50)
            thoigianSleep -= 5;
        if(S.diem % 10 == 0)
            S.level ++;
    }
}
