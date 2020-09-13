#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

void criarLista(Lista **l)
{

	*l = NULL; //lista vazia é inicializada.Seu ponteiro externo aponta para NULL.
}

void inserirInicio(Lista **L, int valor)
{

    Lista *temp;
    Desc *temp1;

    temp =(Lista *) malloc ( sizeof(Lista) ); //aloca um novo nó,para armazenar o valor inteiro adicional
    temp1 = (Lista *) malloc((sizeof(Lista)));
    if(temp == NULL || temp1 == NULL) //confere a memória
    {
        printf("\nFALHA AO INSERIR");
    }
    else //memoria ok
    {
        temp->info = valor; //inserir o valor
        temp->prox = *L; // faz apontar para o nó que estava no inicio
        *L = temp; // A lista recebe o ponteiro do novo elemento inserido
        temp1->inicio = *L;

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
	Desc *temp1;

    if(*L == NULL) //verifica se a lista está vazia
    {
         printf("\nLISTA VAZIA");
    }

    else //memória ok
    {
        temp = malloc ( sizeof(Lista) ); //aloca um novo nó,para armazenar o valor inteiro adicional
        temp1 = malloc(sizeof(Desc));

        if(temp == NULL || temp1 == NULL) //verifica a memória
        {
            printf("\nFALHA AO INSERIR");
        }

        else
        {

             aux = *L;
             temp->info = valor;
             temp->prox = temp1->inicio;




	        while(aux != NULL)
	         {

	             aux = aux->prox;
	         }

	         aux->prox = temp;
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
	Lista *anterior = NULL; // ponteiro para o elemento anterior
	Lista *p = *L; // ponteiro para percorrer a lista
    Desc *temp;


	while( (p != NULL) && (valor > p->info) )
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

		if (anterior == NULL)
		{
			novo->prox = *L;
			*L = novo;
			temp->inicio = *L;
			printf("\nVALOR INSERIDO COM SUCESSO");
		}
		else
		{
			if (p == NULL)
			{
				novo->prox = temp->inicio;
				anterior->prox = novo;
				printf("\nVALOR INSERIDO COM SUCESSO");
			}
			else
			{
				novo->prox = anterior->prox;
				anterior->prox = novo;
				printf("\nVALOR INSERIDO COM SUCESSO");
			}

		}
	}

    fflush(stdin);
	printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();

}

void escrever(Lista *L)
{
     Lista *aux = L; // variavel auxiliar para percorrer a lista

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

     			printf("Info = %d\n" , aux->info);
     			aux = aux->prox;

     		} while (aux == L);

     }

     fflush(stdin);
     printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
     getchar();
}

void buscar(Lista *L , int valor)
{
	Lista *aux; // variavel auxiliar para percorrer a lista
	int permit = 1;//(bloquea/acessar) o 2º if caso o valor seja (encontrado/n encontrado)

	do
	{
		aux = L;

		if (aux->info == valor)
		{
			printf("\n O VALOR %d FOI ENCONTRADO NA LISTA" ,valor);
			permit = 0;
		}

		aux = aux->prox;

	}while(aux != L);

	if (permit == 1)
	{
		printf("\n O VALOR %d NAO FOI ENCONTRADO NA LISTA" ,valor);
	}

    fflush(stdin);
	printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();
}

Lista* retirar(Lista **L , int valor)
{
	Lista *ant = NULL; //ponteiro para o elemento anterior
	Lista *i = *L; //ponteiro para percorrer a lista
	Lista *temp = *L;

	int cont = 0;

	if(i->info != valor)
	{
		i = i->prox;

		while(i != L && i->info != valor) //procura o elemento na lista,guardando o elemento interior
		{
			ant = i;
			i = i->prox;
			if (i->info == valor)
			{
				cont++;
			}
		}
	}


	if (cont == 0 ) //verifica se achou o elemento
	{
		printf("\nO VALOR %d NAO FOI ENCONTRADO" , valor);
        fflush(stdin);
        printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
        getchar();
		return (L); // retorna a lista original
	}

	if (ant == NULL) //retira o elemento no inicio
	{
		*L = i->prox;
		temp->inicio = *L;
	}
	else
	{
		if (i->prox == temp->inicio)
		{
			ant->prox = temp->inicio;
		}
		else
		{
			ant->prox = i->prox;
		}

	}

	free(i);
    printf("\n\nELEMENTO REMOVIDO");
    fflush(stdin);
	printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();

	return L; // retorna a nova lista

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
        printf("LISTA LIBERADO COM SUCESSO");
        recriar = 1;
     }
     return (recriar);
}
















