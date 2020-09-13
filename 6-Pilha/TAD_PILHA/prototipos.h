struct lista
{
	int info;
	struct lista *prox;
};

typedef struct lista Lista;

struct pilha
{
	Lista *topo;
	int qtd;
};
typedef struct pilha Pilha;

Pilha* pilha_cria(void);
void pilha_push(Pilha *p , int valor);
void pilha_pop(Pilha *p);
void imprime(Pilha *p);
void tamanho(Pilha *p);
void buscar(Pilha *p , int valor);
void pilha_vazia(Pilha *p);
int libera(Pilha *p);




