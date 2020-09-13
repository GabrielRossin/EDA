#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "prototipos.h"

struct ponto
{
    float x;
    float y;
};
Ponto* criaPto (float x, float y)
{
    Ponto* p;
    p = (Ponto*) malloc(sizeof (Ponto));
    if(p != NULL)
    {

        p->x = x ;
        p->y = y;
    }

    return p;

}

void liberaPto (Ponto* p)
{
    free(p);
}

void acessaPto (Ponto* p, float* x, float* y)
{
    *x = p->x;
    *y = p->y;
}
//atribui valor ao ponto
void atribuiPto (Ponto* p,float x,float y)
{
    p->x = x;
    p->y = y;
}

// cálculo da distânci entre 2 pontos
float distanciapto (Ponto* p1, Ponto* p2)
{
    float distX = p1->x - p2->x;
    float distY = p1->y - p2->y;
    return sqrt((distX*distX) + (distY*distY));
}
