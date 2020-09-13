struct lista
{
	int info; //armazena a informação
	struct lista *ant; // armanzena o ponteiro para o anterior
	struct lista *prox; // armanzena o ponteiro para o próximo

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





