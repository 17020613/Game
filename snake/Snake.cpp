#include "begin.h"
#include "Seting.h"
#include "Run.h"
#include "console.h"
#include <conio.h>
int main(){

    char _luachon;
    Nocursortype();
    do{
        Start();
        _luachon = _getch();
        if(_luachon == '1')
            run();
        if(_luachon == '2'){
            clrscr();
            if(!Help())
                break;
        }
        if(_luachon == '3')
            break;
    clrscr();
    }while(1);
    return 0;
}
