#include <iostream>
#include <windows.h>
#include "Funciones.h"
#include <conio.h>
#include "rlutil.h"
//#include <cstring>
using namespace std;
#include "Nave.h"
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80






void NAVE::Pintar()
{
    gotoxy(x,y);
    printf( "   %c",30);
    gotoxy(x,y+1);
    printf( "  %c%c%c",40,207,41);
    gotoxy(x,y+2);
    printf( " %c%c %c%c",30,190,190,30);


}
void NAVE::Borrar()
{

    gotoxy(x,y);
    printf ("        ");
    gotoxy(x,y+1);
    printf ("        ");
    gotoxy(x,y+2);
    printf ("        ");

}
void NAVE::Mover()
{

   if(kbhit())
    {
        char tecla=getch();

        Borrar();

        if (tecla == IZQUIERDA && x>3)x--;
        if (tecla == DERECHA && x +6 < 77)x++;
        if (tecla == ARRIBA && y>4 ) y--;
        if (tecla == ABAJO && y+3 < 33)y++;

        Pintar();
        pintar_corazones();

    }


}


void NAVE::pintar_corazones()
{

    gotoxy(50,2);
    printf("Vidas %d", vidas);
    gotoxy(64,2);
    printf("Salud");
    gotoxy(70,2);
    printf("     ");
    for (int i =0; i < corazones ; i++)
    {
        gotoxy(70+i,2);
        printf("%c",3);


    }
}
void NAVE::morir()
{

    if (corazones == 0)
    {

        Borrar();
        gotoxy(x,y);
        printf("   **  ");
        gotoxy(x,y+1);
        printf("  **** ");
        gotoxy(x,y+2);
        printf("   **  ");

        Sleep(200);

        Borrar();

        gotoxy(x,y);
        printf(" * ** *  ");
        gotoxy(x,y+1);
        printf ("  ****   ");
        gotoxy(x,y+2);
        printf ("  * ** * ");

        Sleep(200);

        Borrar();
        vidas--;
        corazones = 3;
        pintar_corazones();
        Pintar();


    }

}
