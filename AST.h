#ifndef AST_H
#define AST_H
#include "Nave.h"


class AST
{
private:
    int x,y;
public:
    AST(int _x,int _y): x(_x),y(_y) {}
    void pintar();
    void mover();
    void choque(class  NAVE  &N);
    int X(){return x;}
    int Y(){return y;}



};

#endif // AST_H
