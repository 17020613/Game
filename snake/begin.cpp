#include <iostream>
#include "begin.h"
#include "console.h"
#include <conio.h>
using namespace std;

bool Help(){
    cout << "\t\t\t\t Nguyen tac choi Game" << endl;
    cout << "(1) An hoa qua de tang do dai va tang diem" << endl;
    cout << "(2) Dung cac phim mui ten de dieu khien ran" << endl;
    cout << "(3) Neu ran dam vao tuong hoac tu can vao than cua minh thi Game ket thuc" << endl;
    cout << "(4) Diem cang cao toc do di chuyen cua ran se cang nhanh" << endl;

    cout << "\n Ban co muon quay lai Main Menu ? Y/N?" << endl;

    char key = _getch();
    if(key == 'n' || key == 'N'){
        return false;
    }
    return true;
}

void Start(){
    TextColor(2);
    cout << endl;
    cout << "\t\t\t sss    n    n       a       k  k    e eee" << endl;
    cout << "\t\t\ts   ||  nn   n      a a      k k     e"     << endl;
    cout << "\t\t\t  s     n n  n     a   a     kk      e eee" << endl;
    cout << "\t\t\t   s    n  n n    a aaa a    k k     e"     << endl;
    cout << "\t\t\t||  s   n   nn   a       a   k  k    e"     << endl;
    cout << "\t\t\t sss    n    n   a       a   k   k   e eee" << endl;

    TextColor(1);
    cout << "\n\n\t\t\t**************** MAIN MENU ****************" << endl;
    TextColor(4);
    cout << "\n\t\t\t\t (1) - New Game" << endl;
    cout << "\n\t\t\t\t (2) - Help" << endl;
    cout << "\n\t\t\t\t (3) - Quit" << endl;
}
