#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto
{
	int codIdent;
	char nomeProd[51];
	int quantDispEstoque;
	float precoVenda;
};

int main()
{
	int n, i;

	do
    {
		printf("Digite um numero: ");
		scanf("%d", &n);
	}while(n <= 1);

	struct produto *produto = (struct produto*) malloc(n*sizeof(struct produto));

	float maiorPrecoV = 0;
	int maiorQuantE = 0;
	char nome [51];
	char nome2[51];

	for(i=0; i<n; i++)
	{
		printf("\nProduto %d:\n", i);
		printf("Codigo Identificador: ");
		scanf("%d", &produto[i].codIdent);
		fflush(stdin);
		printf("Nome do produto: ");
		fgets(produto[i].nomeProd,51,stdin);
		fflush(stdin);
		do
        {
           printf("Quantidade disponivel no estoque: ");
           scanf("%d", &produto[i].quantDispEstoque);
        }while(produto[i].quantDispEstoque < 1);
		do
        {
            printf("Preco de venda: ");
            scanf("%f", &produto[i].precoVenda);

        }while(produto[i].precoVenda <= 0);

	}

	for(i=0; i<n; i++)
	{
		if(produto[i].precoVenda > maiorPrecoV)
        {
			maiorPrecoV = produto[i].precoVenda;
			strcpy(nome,produto[i].nomeProd);
		}
	}

	for(i=0; i<n; i++)
    {
		if(produto[i].quantDispEstoque > maiorQuantE)
		{
			maiorQuantE = produto[i].quantDispEstoque;
            strcpy(nome2,produto[i].nomeProd);

		}
	}

	printf("\n\n\n\n");
	printf("Maior preco de venda = %d|%s.2f",maiorPrecoV , nome);
	printf("Maior quantidade existente no estoque = %d|%s",maiorQuantE ,nome2);

	free(produto);
	return 0;
}

