


//#include <cstring>
using namespace std;

#include <iostream>
#include "rlutil.h"
#include "Menu retro.h"
#include "Juego.h"
#include "Funciones.h"
///showtItem muestra lo que tengo seleccionado



void Menuretro::menuPrincipal (){
int opcion=1 ;
int y=0 ;
Juego juegonuevo;
do{
        ///COLOR DE LAS LETRAS
rlutil::setColor(rlutil::COLOR::GREY);

rlutil::hidecursor();///borra el cursor




rlutil::locate(50,1);///localiza el texto donde quiere
rlutil::setBackgroundColor(rlutil::COLOR::MAGENTA);
cout << "  -BEAR INVASION- " <<endl ;
cout << endl ;
///FUNCION PARA QUE QUEDE SELECCIONADO CAMBIANDO DE FONDO
 showItem(" INICIAR NUEVO JUEGO", 50 , 3, y==0);
 showItem(" MULTIPLAYER", 50 , 4, y==1);
 showItem(" OPCION ", 50 , 5, y==2);
 showItem("  SALIR  " , 50 ,6, y==3);

///el cursor que voy a utilizar es el 175
rlutil::locate(49,3+y);
cout <<(char)175<<endl ;

int key=rlutil::getkey(); ///captura la tecla que apreto y devuelve su nro ascii
///cuando ya tengo mis ascii de las teclas down_(15) y up(14)
///dejo guardando en key la tecla que estoy tocando para que analice el  switch;
//cout <<rlutil::getkey();

switch(key){
    case 15:///down
        rlutil::locate(49,3+y);///este locate es para que se borre el cursor cuando sume o reste y
        cout << " "<< endl ;
        y++;
        if (y>3){///estos ifs son para que no se salgan de las opciones que tenemos
            y=3 ;
        }
        break;
    case 14 :///up
        rlutil::locate(49,3+y);
        cout << " "<< endl ;
        y--;
        if (y<0){
            y=0;
        }
        break ;
    case 1:///enter

        switch(y){
    case 3:
        opcion=0 ;
        break ;
        case 0:
     juegonuevo.JuegoPrincipal();
        break;


        }

}








}while(opcion!=0);



return ;
}











