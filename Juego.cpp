#include <iostream>
//#include <cstring>
using namespace std;
#include "Juego.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <list>
#include "Funciones.h"
#include "Nave.h"
#include "AST.h"
#include "rlutil.h"
#include "Bala.h"
void Juego::OcultarCursor()
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hCon, &cci);

}


void Juego::pintar_limites()
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



void Juego::JuegoPrincipal ()
{

    OcultarCursor();
    NAVE N(37,30,3,3);
    N.Pintar();
    pintar_limites();
    N.pintar_corazones();

    list <AST*>A;
    list <AST*>::iterator itA;
    for (int i=0; i <5;i++){
        A.push_back(new AST(rand()%75 + 3, rand()%5 + 4 ));
    }


    list<Bala*> B;
    list<Bala*>::iterator it;

    int puntos =0;

    bool gameover=false;

    while (!gameover)
    {
        gotoxy(4,2);printf ("Puntos %d",puntos);

        if (kbhit())
        {
            char tecla=getch();
            if (tecla == 'a'){
                B.push_back(new Bala(N.X()+2 , N.Y()-1));
            }
            for(it = B.begin(); it != B.end() ; it++ )
            {
                (*it)->mover();
                if ((*it)->fuera()){
                    gotoxy((*it)->X(),(*it)->Y()); printf(" ");
                    delete (*it);
                    it = B.erase(it);
                }
            }

        }

       for (itA = A.begin() ; itA!= A.end();itA++){
            (*itA)->mover();
            (*itA)->choque(N);


       }
        for (itA = A.begin() ; itA!= A.end();itA++){
          for  (it=B.begin(); it!= B.end();it++){
            if ((*itA)->X() == (*it)->X() && ( (*itA)->Y() +1 == (*it)->Y() || (*itA)->Y()== (*it)->Y() ))
            {

                gotoxy((*it)->X(),(*it)->Y()); printf(" ");
                delete (*it);
                it = B.erase(it);

                A.push_back(new AST(rand()%75 + 3, 4));

                gotoxy((*itA)->X(),(*itA)->Y()); printf(" ");
                delete (*itA);
                itA = A.erase(itA);

                puntos+=5;


            }
          }

       }
        if (N.vid()== 0 )gameover=true;
       N.morir();
        N.Mover();
        Sleep(30);

    }
    cout << "GAME OVER "<< endl;

    return;
}








