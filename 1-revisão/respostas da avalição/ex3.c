#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[4][4];
    int i;
    int j;
    int soma;

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("Insira o numero: ");
            scanf("%d",&matriz[i][j]);
        }
    }
    for(i = 0; i < 4;i++)
    {
        for(j = 3; j < -1 ; j--)
        {
            soma = matriz[i][j];
        }
    }
    printf("soma %d",soma);

    return 0;
}
