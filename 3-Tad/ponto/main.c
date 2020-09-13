#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"
int main()
{
    float dist;
    Ponto *p, *q;
    p=criaPto();
    atribuiPto(&p , 20 ,22);
    q=criaPto(7,25);
    dist = distanciapto(p,q);
    printf( "Distancia entre pontos:%.2f\n " , dist);
    liberaPto(p);
    liberaPto(q);
    system( " PAUSE " ) ;


    return 0;
}
