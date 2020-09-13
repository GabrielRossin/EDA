#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

void criarLista (Lista **l)
{

	*l = NULL; //lista vazia � inicializada.Seu ponteiro externo aponta para NULL.

}
void inserirInicio(Lista **L, int valor)
{

    Lista *novo;
    novo = malloc ( sizeof(Lista) ); //aloca um novo n�,para armazenar o valor inteiro adicional

    if(novo == NULL) //confere a mem�ria
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
        	novo->prox = *L; // faz apontar para o n� que estava no inicio
        	novo->ant = NULL; //anterior do novo n� aponta para NULL
        	(*L)->ant = novo; // o anterior atual do primeiro n� aponta para o novo n�

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



    novo = malloc ( sizeof(Lista) ); //aloca um novo n�,para armazenar o valor inteiro adicional

    if(novo == NULL) //verifica a mem�ria
    {
        printf("\nFALHA AO INSERIR");
    }
    else //mem�ria ok
    {
        novo->info = valor;
        novo->prox = NULL;

        if(*L == NULL) //verifica se a lista est� vazia
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

	if (novo == NULL) //verifica se o novo n� foi alocado
	{
        printf("\nFALHA AO INSERIR");
	}
	else
	{

		while( (atual != NULL) && (valor > atual->info) ) //verifica a posi��o
		{
			anterior = atual;
			atual = atual->prox;
		}

		novo->info = valor;
		if (anterior == NULL) //inserir no inicio
		{
			atual->ant = novo; //anteriro do atual aponto para o novo n�
			novo->prox = atual; //proximo do novo n� aponta para o atual;
			novo->ant = NULL; //anterior do novo n� aponta para null
			*L = novo; //Lista aponta para o novo n�

			printf("\nVALOR INSERIDO COM SUCESSO");
		}
		else
		{
			novo->prox = atual; //proximo do novo n� aponta para o atual;
			novo->ant = anterior;//anterior do novo n� aponta para o n� anterior
			anterior->prox = novo;//n� anterior aponta para o novo n�

			if (atual != NULL) // se for inserido no meio
			{
				atual->ant = novo; //anterior do n� que est� a frete aponta para o novo n�
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
	int permit = 1;//(bloquea/acessar) o 2� if caso o valor seja (encontrado/n encontrado)

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

	if (aux == NULL) //n�o achou e retorna lista inalterada
	{
		return L;
	}

	if (L == aux) //teste se � o primeiro elemento
	{
		L = aux->prox;
	}

	else
	{
		aux->ant->prox = aux->prox;
	}

	if (aux->prox != NULL)//teste para ver se � o �ltimo elemento
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
			t = p->prox; //guarda a refer�ncia para o pr�ximo n�
			free(p); // libera a lista
			p = t; //faz p apontar para o pr�ximo n�
		}
        printf("LISTA LIBERADA COM SUCESSO");
        recriar = 1;
     }
     fflush(stdin);
     printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
     getchar();
     return (recriar);

}


