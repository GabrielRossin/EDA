struct lista
{
	int info;
	struct lista *prox;
};

typedef struct lista Lista;

void criarLista (Lista **l);
void inserirInicio(Lista **L, int valor);
void inserirFim(Lista **L , int valor);
void inserirMeio(Lista **L , int valor);
void escrever(Lista *L);
void buscar(Lista *L , int valor);
Lista* retirar(Lista *L , int valor);
void contar(Lista *L);
int liberar(Lista *L);

