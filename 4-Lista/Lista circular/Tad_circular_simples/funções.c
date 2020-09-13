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

    Lista *temp;

    temp = (Lista*) malloc( sizeof(Lista) ); //aloca um novo nó,para armazenar o valor inteiro adicional

    if(temp == NULL) //confere a memória
    {
        printf("\nFALHA AO INSERIR");
    }

    else //memoria ok
    {
        temp->info = valor;
        if(*L == NULL)
        {
            temp->prox = temp;
        }
        else
        {
            temp->prox = (*L)->prox;
            (*L)->prox = temp;
        }
        *L = temp;

        printf("\nVALOR INSERIDO COM SUCESSO");
    }

    fflush(stdin);
    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();

}

void inserirFim(Lista **L , int valor)
{
	Lista *temp;
	Lista *aux;

    temp = malloc ( sizeof(Lista) ); //aloca um novo nó,para armazenar o valor inteiro adicional

        if(temp == NULL) //verifica a memória
        {
            printf("\nFALHA AO INSERIR");
        }
        else
        {
        	temp->info = valor;
        	if(*L == NULL) //verifica se a lista está vazia
            {
                temp->prox = temp;
                *L = temp;
            }
            else
            {
                aux = *L;
                while(aux->prox != *L)
                {
                    aux = aux->prox;
                }

                temp->prox = aux->prox;
                aux->prox = temp;

            }

	         printf("\nVALOR INSERIDO COM SUCESSO");
        }

    fflush(stdin);
    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();

}

void inserirMeio(Lista **L , int valor)
{
	Lista *novo;
	Lista *anterior = NULL; // ponteiro para o elemento anterior
	Lista *p = *L; // ponteiro para percorrer a lista

    while(p->prox != *L && valor > p->info)
    {
        anterior = p;
		p = p->prox;
    }

	novo = (Lista *) malloc(sizeof(Lista));

	if (novo == NULL)
	{
		printf("\nFALHA AO INSERIR");
	}
	else
	{
		novo->info = valor;

		if (anterior == NULL) // se for inserido no inicio
		{
			novo->prox = *L;
			*L = novo;
			printf("\nVALOR INSERIDO COM SUCESSO");
		}
		else
		{

            novo->prox = anterior->prox;
            anterior->prox = novo;

			printf("\nVALOR INSERIDO COM SUCESSO");
		}
	}

    fflush(stdin);
	printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();

}

void escrever(Lista *L)
{
     Lista *aux = L; // variavel auxiliar para percorrer a lista
     int cont = 0 ;

     system("cls");
	 printf("\nPROCESSO DE IMPRIMIR A LISTA FOI SELECIONADO\n\n\n");

     if (L == NULL)
     {
     	printf("\n\nA lista esta vazia !");
     }

     else
     {
        do
        {
            cont++;
            printf("\ninfo %d:%d",cont,aux->info);
            aux = aux->prox;

        }while(aux!= L);

     }

     fflush(stdin);
     printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
     getchar();
}

void buscar(Lista *L , int valor)
{
	Lista *aux = L; // variavel auxiliar para percorrer a lista
	int permit = 1;//(bloquea/acessar) o 2º if caso o valor seja (encontrado/n encontrado)

	do
    {
     	if (aux->info == valor)
		{
			printf("\n O VALOR %d FOI ENCONTRADO NA LISTA" ,valor);
			permit = 0;
		}

     	aux = aux->prox;
    } while (aux != L);

	if (permit == 1)
	{
		printf("\n O VALOR %d NAO FOI ENCONTRADO NA LISTA" ,valor);
	}

    fflush(stdin);
	printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();
}


void retirar(Lista **L , int valor)
{
	Lista *ant = NULL; //ponteiro para o elemento anterior
	Lista *i = *L; //ponteiro para percorrer a lista
	Lista *aux = *L;

	if(i->info == valor)
    {
        while(aux->prox != *L)
        {
            aux = aux->prox;
        }
        aux->prox = i->prox; //ultimo elemento aponta para o novo inicio
        *L = i->prox;

        free(i);
        printf("\n\nELEMENTO REMOVIDO");
    }
    else
    {
        while(i->prox != *L && i->info != valor) //procura o elemento na lista,guardando o elemento interior
        {
            ant = i;
            i = i->prox;
        }

        if (i == *L) //verifica se achou o elemento
        {
            printf("\nO VALOR %d NAO FOI ENCONTRADO" , valor);

        }
        else
        {
            if (ant == NULL) //retira o elemento no inicio
            {
                while(aux->prox != *L)
                {
                    aux = aux->prox;
                }
                aux->prox = i->prox; //ultimo elemento aponta para o novo inicio
                *L = i->prox;

            }

            else
            {
                ant->prox = i->prox;
            }
            free(i);
            printf("\n\nELEMENTO REMOVIDO");

        }

    }


    fflush(stdin);
	printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();

}

void contar(Lista *L)
{

	Lista *p = L;
	int cont = 0;

	system("cls");
	printf("\nPROCESSO DE CONTAR ELEMENTOS DA LISTA FOI SELECIONADO\n\n\n");

    if(p!= NULL)
    {
        do
         {

         	cont++;
            p = p->prox;

         }while(p != L);

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
    int recriar;

	system("cls");
	printf("\nPROCESSO DE LIBERAR A LISTA FOI SELECIONADO\n\n\n");

     if (p == NULL)
     {
     	printf("\n\nA lista esta vazia !");
     }
     else
     {
     	do
		{
			t = p->prox; //guarda a referência para o próximo nó
			free(p); // libera a lista
			p = t; //faz p apontar para o próximo nó
		}while(p != L);
        printf("LISTA LIBERADA COM SUCESSO");
        recriar = 1;
     }
     fflush(stdin);
     printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
     getchar();
     return (recriar);

}
