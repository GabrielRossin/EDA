#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i;
    int num_card[90];
    float peso[90];

    float menor_peso;
    int id_menor;

    float maior_peso;
    int id_maior;

    float soma = 0;
    float media;

    for(i = 0;i < 3; i++)
    {
        printf("Insira o numero do cartao:");
        scanf("%d",&num_card[i]);
        printf("Insira o peso:");
        scanf("%f",&peso[i]);
    }
    menor_peso = peso[0];
    id_menor = 0;

    for(i = 0;i < 3; i++)
    {
        if(menor_peso > peso[i])
        {
            menor_peso = peso[i];
            id_menor = i;
        }
    }

    maior_peso = peso[i];
    id_maior = 0;
    for(i = 0;i < 3; i++)
    {
        if(maior_peso < peso[i])
        {
            maior_peso = peso[i];
            id_maior = i;
        }
    }

        for(i = 0;i < 3; i++)
    {
       soma += peso[i];
    }

    media = soma / 3;
    printf("\n\n");
    printf("---------------------RESULTADOS---------------------");
    printf("\n");


    printf("Numero do boi mais magro:%d",num_card[id_menor]);
    printf("\n");
    printf("Peso do boi mais magro:%.2f",peso[id_menor]);
    printf("\n");

    printf("Numero do boi mais gordo:%d",num_card[id_maior]);
    printf("\n");
    printf("Peso do boi mais gordo:%.2f",peso[id_maior]);
    printf("\n");

    printf("Media do peso dos boi:%2.f",media);


    return 0;


}

