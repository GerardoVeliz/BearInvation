#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <list>
#include <iostream>
#include "Funciones.h"
#include "AST.h"
#include "rlutil.h"

using namespace std;

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

void AST::pintar()
{
    gotoxy(x,y);
    printf("%c",184);


}
void AST::mover()
{

    gotoxy(x,y);
    printf (" ");
    y++;

    if (y > 32)
    {
        x = rand()%71 + 4;
        y = 4;
    }
    pintar();

}

void AST::choque(class NAVE &N)
{

    if (x>= N.X() && x <N.X()+6 &&y >=N.Y()&& y <= N.Y()+2)
    {
        N.Cor();
        N.Borrar();
        N.Pintar();
        N.pintar_corazones();
        x = rand()%71 + 4;
        y = 4;

    }
}

