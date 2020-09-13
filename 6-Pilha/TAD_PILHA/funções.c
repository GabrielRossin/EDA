#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

Pilha* pilha_cria(void)
{
	Pilha *p = (Pilha *)malloc(sizeof(Pilha));
	if (p == NULL)
	{
		printf("\nDESCRITOR NAO ALOCADO");
		return p;
	}
	else
	{
		p->topo = NULL;
		p->qtd = 0;
		return p;
	}
}

void pilha_push(Pilha *p , int valor)
{
	if (p == NULL)
	{
		printf("\nDESCRITOR NAO ALOCADO");
	}
	else
	{
		Lista *novo = (Lista *) malloc(sizeof(Lista));
		if (novo == NULL)
		{
			printf("\nFALHA EM ALOCAR");
		}
		else
		{
			novo->info = valor;
			novo->prox = p->topo;
			p->topo = novo;
			p->qtd++;
			printf("\nVALOR INSERIDO COM SUCESSO");
		}
	}

	fflush(stdin);
    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();
}

void pilha_pop(Pilha *p)
{
	Lista *aux;
	int valor;
	 system("cls");
	 printf("\nPROCESSO DE IMPRIMIR A PILHA FOI SELECIONADO\n\n\n");

	if (p == NULL)
	{
		printf("\nDESCRITOR NAO ALOCADO");
	}
	else
	{
		if (p->topo == NULL)
		{
			printf("\nPILHA VAZIA");
		}
		else
		{

			aux  = p->topo;
			valor = aux->info;
			p->topo = aux->prox;
			free(aux);
			printf("\nVALOR %d REMOVIDO COM SUCESSO" , valor);
		}
	}

	fflush(stdin);
    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();
}

void imprime(Pilha *p)
{

	if (p == NULL)
	{
		printf("\nDESCRITOR NAO ALOCADO");
	}
	else
	{
		if (p->topo == NULL)
		{
			printf("\nPILHA VAZIA");
		}
		else
		{
			Lista *q;

			for (q=p->topo; q != NULL;  q = q->prox)
			{
				printf("%d\n",q->info);
			}

		}
	}


	fflush(stdin);
    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();
}

void tamanho(Pilha *p)
{
	if (p == NULL)
	{
		printf("\nDESCRITOR NAO ALOCADO");
	}
	else
	{
		if (p->topo == NULL)
		{
			printf("\nPILHA VAZIA");
		}
		else
		{
			Lista *q;
			int cont = 0;

			for (q=p->topo; q != NULL;  q = q->prox)
			{
				cont++;
			}

			printf("\nO TAMANHO DA PILHA:%d",cont);
		}
	}

	fflush(stdin);
    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();
}

void buscar(Pilha *p , int valor)
{
	if (p == NULL)
	{
		printf("\nDESCRITOR NAO ALOCADO");
	}
	else
	{
		if (p->topo == NULL)
		{
			printf("\nPILHA VAZIA");
		}
		else
		{
			int permit = 1;
			Lista *q;

			for (q=p->topo; q != NULL;  q = q->prox)
			{
				if (q->info == valor)
				{
					printf("\n O VALOR %d FOI ENCONTRADO NA LISTA" ,valor);
					permit = 0;
				}
			}

			if (permit == 1)
			{
				printf("\n O VALOR %d NAO FOI ENCONTRADO NA LISTA" ,valor);
			}
		}
	}

	fflush(stdin);
    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();
}

void pilha_vazia(Pilha *p)
{
	if (p == NULL)
	{
		printf("\nDESCRITOR NAO ALOCADO");
	}
	else
	{
		if (p->topo == NULL)
		{
			printf("\nPILHA VAZIA");
		}
		else
		{
			printf("\nA PILHA NAO ESTA VAZIA");
		}
	}
	fflush(stdin);
    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();
}

int libera(Pilha *p)
{
	int recriar = 0;

	system("cls");
	printf("\nPROCESSO DE LIBERAR A PILHA FOI SELECIONADO\n\n\n");

	if (p == NULL)
	{
		printf("\nDESCRITOR NAO ALOCADO");
	}
	else
	{
		if (p->topo == NULL)
		{
			printf("\nPILHA VAZIA");
		}
		else
		{


			Lista *q = p->topo;

			while(q != NULL)
			{
				Lista *t = q->prox;
				free(q);
				q = t;
			}

			recriar = 1;
		}
	}
	fflush(stdin);
    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();
    return (recriar);

}
