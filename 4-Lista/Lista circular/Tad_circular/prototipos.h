struct Lista_Circular
{
	int info;
	struct Lista_Circular *prox;
	struct Lista_Circular *ant;

};

typedef struct Lista_Circular Lista;

struct descritor
{
    struct Lista_Circular *inicio;
};

typedef struct descritor Desc;

void criarLista (Lista **l);
void inserirInicio(Lista **L, int valor);
void inserirFim(Lista **L , int valor);
void inserirMeio(Lista **L , int valor);
void escrever(Lista *L);
void buscar(Lista *L , int valor);
Lista* retirar(Lista **L , int valor);
void contar(Lista *L);
int liberar(Lista *L);




