#ifndef NAVE_H
#define NAVE_H


class NAVE
{
private:
    int x,y;
    int corazones;
    int vidas;
public:
    NAVE(int _x,int _y,int _corazones, int _vidas): x(_x),y(_y),corazones(_corazones), vidas(_vidas) {};
    int X()
    {
        return x;
    }
    int Y()
    {
        return y;
    }
    int vid(){return vidas;}
    void Pintar();
    void Borrar();
    void Mover();
    void pintar_corazones();
    void morir();
    void Cor()
    {
        corazones--;
    }
};


#endif // NAVE_H
