#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

  insirir();

  return 0;
}
void insirir()
{
    int *vetor;
    int posicoes;
    int i;

    printf("Insira quantidade de posicoes:" );
    scanf("%d",&posicoes);

    vetor = (int *) calloc(posicoes,sizeof(int));

    for (i = 0; i < posicoes; i++)
    {
        printf("Insira um nummero:\n" );
        scanf("%d",&vetor[i] );
    }

    contarMultiplos(vetor,posicoes);

    free(vetor);
}
void contarMultiplos(int vetor[],int posicoes)
{
    int x;
    int i;
    int resp;
    int cont = 0;
    printf("Insira um numero inteiro:");
    scanf("%d",&x );

    for (i = 0; i < posicoes; i++)
    {
        resp = vetor[i] % x;
        if (resp == 0)
        {
          cont++;
        }
    }
    printf("A quantidade de multiplos de %d no vetor eh de %d",x,cont);

}
