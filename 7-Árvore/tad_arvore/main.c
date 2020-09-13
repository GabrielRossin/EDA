#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main()
{
    arvore_Binaria *raiz = criarArvBin();
    int dados[8] = {70 , 100 , 32 , 27 , 43 , 46 , 34 , 36};
    int i;
   int r;
    for(i = 0; i < 8; i++)
    {
         insere_recursiva(raiz , dados[i]);
    }
    //for(i = 0; i < 8; i++) // ordenado
   // {
      //  r = inserirOrdenadoArvBin(raiz , dados[i]);
  //  }
    r = busca_recursiva(raiz , 70);
    r = busca_recursiva(raiz , 100);
    r = busca_recursiva(raiz , 50);
    return 0;
}
