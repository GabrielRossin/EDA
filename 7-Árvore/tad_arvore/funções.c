#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

arvore_Binaria* criarArvBin()
{
    arvore_Binaria *raiz = (arvore_Binaria *) malloc(sizeof(arvore_Binaria));
    if (raiz != NULL)
    {
        printf("\nRAIZ ALOCADA");
        *raiz = NULL;
    }
    else
    {
        printf("\nRAIZ NAO ALOCADA");
    }
    return raiz;
}

int inserirOrdenadoArvBin(arvore_Binaria *raiz , int valor)
{
    if (raiz == NULL)
    {
        printf("\nRAIZ NAO ALOCADA");
        return 0;
    }
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    if (novoNo == NULL)
    {
        printf("\nERRO NA ALOCACAO");
        return 0;
    }

    novoNo->dado = valor;
    novoNo->sad = NULL;
    novoNo->sae = NULL;

    if (*raiz == NULL) //novo elemento será o primeiro
    {
        *raiz = novoNo;
        printf("\nELEMENTO ADICIONADO COM SUCESSO");
        printf(" |%d",valor);
        return 1;

    }
    else
    {
        struct no *atual = *raiz;
        struct no *anterior = NULL;

        while (atual != NULL)
        {
            anterior = atual;

            if (valor == atual->dado) //elemento já existe
            {
                printf("\nVALOR JA EXISTE");
                free(novoNo);
                return 0;
            }

            if (valor > atual->dado)
            {
                atual = atual->sad;
            }
            else
            {
              atual = atual->sae;
            }
        }
        if (valor > anterior->dado)
        {
            anterior->sad = novoNo;
        }
        else
        {
            anterior->sae = novoNo;
        }
        printf("\nELEMENTO ADICIONADO COM SUCESSO");
        printf(" |%d",valor);
        return 1;
    }

}

int busca_recursiva(arvore_Binaria *raiz , int valor)
{
	if (raiz == NULL)
	{
		printf("\nRAIZ NAO ALOCADA");
		return NULL;
	}

	if (*raiz == NULL)
	{
		printf("\nVALOR NAO EXISTE");
		return NULL;
	}

	if(valor == (*raiz)->dado)
	{
		printf("\nVALOR ENCONTRADO");
		return raiz;
	}

	if (valor < (*raiz)->dado)
	{
		return busca_recursiva(&((*raiz)->sae) , valor);
	}

	else
	{
		return busca_recursiva(&((*raiz)->sad) , valor);
	}

}
void insere_recursiva(arvore_Binaria *raiz, int valor)
{

    if (raiz == NULL)
    {
        printf("\nRAIZ NAO ALOCADA");
        return ;
    }



    if (*raiz == NULL) //novo elemento será o primeiro
    {
       struct no *novoNo = (struct no *) malloc(sizeof(struct no));

        if (novoNo == NULL)
        {
            printf("\nERRO NA ALOCACAO");
            return;
        }

        novoNo->dado = valor;
        novoNo->sad = NULL;
        novoNo->sae = NULL;

        *raiz = novoNo;
        printf("\nELEMENTO ADICIONADO COM SUCESSO");
        printf(" |%d",valor);


    }
    else
    {
        if (valor < (*raiz)->dado)
        {
            return insere_recursiva(&((*raiz)->sae) , valor);
        }
        if (valor > (*raiz)->dado)
        {
            return insere_recursiva(&((*raiz)->sad) , valor);
        }

    }


}



