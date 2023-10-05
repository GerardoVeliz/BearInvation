#include <iostream>
#include <windows.h>
//#include <cstring>
using namespace std;
#include "Bala.h"


  void gotoxy(int x, int y)
    {
        HANDLE hCon;
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;

        SetConsoleCursorPosition(hCon, dwPos);
    }

void Bala::mover()
{

    gotoxy (x,y);
    printf(" ");
    y--;
    gotoxy(x,y);
    printf ("*");


}
bool Bala::fuera(){
if (y==4){
    return true;


}
else {
    return false;
}
}
