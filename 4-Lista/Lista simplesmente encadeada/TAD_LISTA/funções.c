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
    temp = malloc ( sizeof(Lista) ); //aloca um novo nó,para armazenar o valor inteiro adicional

    if(temp == NULL) //confere a memória
    {
        printf("\nFALHA AO INSERIR");
    }
    else //memoria ok
    {
        temp->info = valor; //inserir o valor
        temp->prox = *L; // faz apontar para o nó que estava no inicio
        *L = temp; // A lista recebe o ponteiro do novo elemento inserido
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


    if(*L == NULL) //verifica se a lista está vazia
    {
        printf("\nLISTA VAZIA");
    }

    else //memória ok
    {
        temp = malloc ( sizeof(Lista) ); //aloca um novo nó,para armazenar o valor inteiro adicional

        if(temp == NULL) //verifica a memória
        {
            printf("\nFALHA AO INSERIR");
        }

        else
        {
        	temp->info = valor;
            temp->prox = NULL;

        	aux = *L;

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

void buscar(Lista *L , int valor)
{
	Lista *aux; // variavel auxiliar para percorrer a lista
	int permit = 1;//(bloquea/acessar) o 2º if caso o valor seja (encontrado/n encontrado)

	for (aux = L; aux != NULL; aux = aux->prox)
	{
		if (aux->info == valor)
		{
			printf("\n O VALOR %d FOI ENCONTRADO NA LISTA" ,valor);
			permit = 0;
		}
	}

	if (permit == 1)
	{
		printf("\n O VALOR %d NAO FOI ENCONTRADO NA LISTA" ,valor);
	}

    fflush(stdin);
	printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();
}

Lista* retirar(Lista *L , int valor)
{
	Lista *ant = NULL; //ponteiro para o elemento anterior
	Lista *i = L; //ponteiro para percorrer a lista

	while(i != NULL && i->info != valor) //procura o elemento na lista,guardando o elemento interior
	{
		ant = i;
		i = i->prox;
	}

	if (i == NULL) //verifica se achou o elemento
	{
		printf("\nO VALOR %d NAO FOI ENCONTRADO" , valor);
        fflush(stdin);
        printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
        getchar();
		return (L); // retorna a lista original
	}

	if (ant == NULL) //retira o elemento no inicio
	{
		L = i->prox;
	}
	else
	{
		ant->prox = i->prox;
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
    int get;
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

/*int lst_igua(Lista *l1 , Lista *l2) // comparar duas listas
{
    lISTA *P1
    LISTA *P2

    for(p1 = l1,p2=l2;p1!=NULL&&p2!=NULL;p1=p1->prox,p2=p2->prox)
    {
        if(p1->info != p2->info)
        {
            return 0;
        }
    }
        return p1 == p2;
}*/
















