#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

void criarLista (Lista **l)
{

	*l = NULL; //lista vazia é inicializada.Seu ponteiro externo aponta para NULL.

}
void inserirInicio(Lista **L, int valor)
{

    Lista *novo;
    novo = malloc ( sizeof(Lista) ); //aloca um novo nó,para armazenar o valor inteiro adicional

    if(novo == NULL) //confere a memória
    {
        printf("\nFALHA AO INSERIR");
    }

    else //memoria ok
    {

        novo->info = valor; //inserir o valor

        if (*L == NULL) // se a lista estiver vazia
        {
        	novo->prox = NULL;
        	novo->ant = NULL;
        }

        else
        {
        	novo->prox = *L; // faz apontar para o nó que estava no inicio
        	novo->ant = NULL; //anterior do novo nó aponta para NULL
        	(*L)->ant = novo; // o anterior atual do primeiro nó aponta para o novo nó

        }

        *L = novo; // A lista recebe o ponteiro do novo elemento inserido

        printf("\nVALOR INSERIDO COM SUCESSO");
    }

    fflush(stdin);
    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();

}
void inserirFim(Lista **L , int valor)
{
	Lista *novo;
	Lista *aux;



    novo = malloc ( sizeof(Lista) ); //aloca um novo nó,para armazenar o valor inteiro adicional

    if(novo == NULL) //verifica a memória
    {
        printf("\nFALHA AO INSERIR");
    }
    else //memória ok
    {
        novo->info = valor;
        novo->prox = NULL;

        if(*L == NULL) //verifica se a lista está vazia
        {
        	printf("\nLISTA VAZIA");
        }
        else
        {
        	aux = *L;

	        while(aux != NULL)
	         {

	             aux = aux->prox;
	         }
	         novo->ant = aux;
	         aux->prox = novo;
	         printf("\nVALOR INSERIDO COM SUCESSO");
        }



    }

    fflush(stdin);
    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();

}

void inserirMeio(Lista **L , int valor)
{
	Lista *novo;
	Lista *anterior = NULL;
	Lista *atual = *L;

	novo = (Lista *) malloc(sizeof(Lista));

	if (novo == NULL) //verifica se o novo nó foi alocado
	{
        printf("\nFALHA AO INSERIR");
	}
	else
	{

		while( (atual != NULL) && (valor > atual->info) ) //verifica a posição
		{
			anterior = atual;
			atual = atual->prox;
		}

		novo->info = valor;
		if (anterior == NULL) //inserir no inicio
		{
			atual->ant = novo; //anteriro do atual aponto para o novo nó
			novo->prox = atual; //proximo do novo nó aponta para o atual;
			novo->ant = NULL; //anterior do novo nó aponta para null
			*L = novo; //Lista aponta para o novo nó

			printf("\nVALOR INSERIDO COM SUCESSO");
		}
		else
		{
			novo->prox = atual; //proximo do novo nó aponta para o atual;
			novo->ant = anterior;//anterior do novo nó aponta para o nó anterior
			anterior->prox = novo;//nó anterior aponta para o novo nó

			if (atual != NULL) // se for inserido no meio
			{
				atual->ant = novo; //anterior do nó que está a frete aponta para o novo nó
			}

			printf("\nVALOR INSERIDO COM SUCESSO");

		}




	}

}

void escrever(Lista *L)
{
     Lista *aux; // variavel auxiliar para percorrer a lista

     system("cls");
	 printf("\nPROCESSO DE IMPRIMIR A LISTA FOI SELECIONADO\n\n\n");

     if (L == NULL)
     {
     	printf("\n\nA lista esta vazia !");
     }

     else
     {

     	for (aux = L; aux != NULL; aux = aux->prox)
     	{
     		printf("Info = %d\n" , aux->info);
     	}
     }

     fflush(stdin);
     printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
     getchar();
}

Lista* buscar(Lista *L , int valor)
{
	Lista *aux; // variavel auxiliar para percorrer a lista
	int permit = 1;//(bloquea/acessar) o 2º if caso o valor seja (encontrado/n encontrado)

	for (aux = L; aux != NULL; aux = aux->prox)
	{
		if (aux->info == valor)
		{
			printf("\n O VALOR %d FOI ENCONTRADO NA LISTA" ,valor);
			permit = 0;
			fflush(stdin);
			printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    		getchar();
    		return aux;
		}
	}
	if(permit == 1)
    {
        printf("\n O VALOR %d NAO FOI ENCONTRADO NA LISTA" ,valor);
    }

	fflush(stdin);
	printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();
	return (NULL);

}

Lista* remover(Lista *L , int valor)
{
	Lista *aux = buscar(L , valor);

	if (aux == NULL) //não achou e retorna lista inalterada
	{
		return L;
	}

	if (L == aux) //teste se é o primeiro elemento
	{
		L = aux->prox;
	}

	else
	{
		aux->ant->prox = aux->prox;
	}

	if (aux->prox != NULL)//teste para ver se é o último elemento
	{
		aux->prox->ant = aux->ant;
	}

	free(aux);

	printf("\n\nELEMENTO REMOVIDO");
    fflush(stdin);
	printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();

	return (L);

}

void contar(Lista *L)
{

	Lista *p = L;
	int cont = 0;

	system("cls");
	printf("\nPROCESSO DE CONTAR ELEMENTOS DA LISTA FOI SELECIONADO\n\n\n");

    if(p!= NULL)
    {
        while(p != NULL)
         {

         	cont++;
            p = p->prox;


         }
        printf("A QUANTIDADE DE ELEMENTOS NA LISTA: %d ELEMENTO(S)" , cont);
    }
    else
    {
        printf("LISTA VAZIA");
    }


    fflush(stdin);
    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();

}

int liberar(Lista *L)
{
	Lista *p = L;
	Lista *t;
    //int get;
    int recriar;

	system("cls");
	printf("\nPROCESSO DE LIBERAR A LISTA FOI SELECIONADO\n\n\n");

     if (p == NULL)
     {
     	printf("\n\nA lista esta vazia !");
     }
     else
     {
     	while(p != NULL)
		{
			t = p->prox; //guarda a referência para o próximo nó
			free(p); // libera a lista
			p = t; //faz p apontar para o próximo nó
		}
        printf("LISTA LIBERADA COM SUCESSO");
        recriar = 1;
     }
     fflush(stdin);
     printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
     getchar();
     return (recriar);

}


