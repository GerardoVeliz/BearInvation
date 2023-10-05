#include <iostream>
#include "Funciones.h"
#include <windows.h>
#include "rlutil.h"
using namespace std;


//void gotoxy(int x, int y)
//{
//    HANDLE hCon;
//    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
//    COORD dwPos;
//    dwPos.X= x;
//    dwPos.Y = y;
//
//    SetConsoleCursorPosition(hCon,dwPos);
//}
void OcultarCursor()
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hCon, &cci);

}

void pintar_limites()
{

    for(int i=2; i<78; i++)
    {

        gotoxy(i,3);
        printf("%c",205);
        gotoxy(i,33);
        printf("%c",205);

    }
    for (int i=4; i<33; i++)
    {

        gotoxy(2,i);
        printf("%c",186);
        gotoxy(77,i);
        printf("%c",186);

    }

    gotoxy(2,3);
    printf("%c",201);
    gotoxy(2,33);
    printf("%c",200);
    gotoxy(77,3);
    printf("%c",187);
    gotoxy(77,33);
    printf("%c",188);


}



void showItem(const char* text , int x , int y , bool selected){
if (selected){
    rlutil::setBackgroundColor(rlutil::COLOR::MAGENTA);}
    else {

     rlutil::setBackgroundColor(rlutil::COLOR::BLACK);//negro porque el fondo es negro y quedaria igual
    }



rlutil::locate(x,y);
cout << text <<endl ;
rlutil::setBackgroundColor(rlutil::COLOR::BLACK);///lo ponemos devuelta black para que no quede nada pintado
}
