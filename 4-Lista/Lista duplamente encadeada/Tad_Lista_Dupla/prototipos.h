struct lista
{
	int info; //armazena a informa��o
	struct lista *ant; // armanzena o ponteiro para o anterior
	struct lista *prox; // armanzena o ponteiro para o pr�ximo

};

typedef struct lista Lista;

void criarLista (Lista **l);
void inserirInicio(Lista **L, int valor);
void inserirFim(Lista **L , int valor);
void inserirMeio(Lista **L , int valor);
void escrever(Lista *L);
Lista* buscar(Lista *L , int valor);
Lista* remover(Lista *L , int valor);
void contar(Lista *L);
int liberar(Lista *L);





