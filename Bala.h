#ifndef BALA_H
#define BALA_H

class Bala
{
private:
    int x, y;
public:
    Bala(int _x,int _y): x(_x),y(_y){}
    int X(){return x;}
    int Y(){return y;}
    void mover();
    bool fuera();
};
#endif // BALA_H
