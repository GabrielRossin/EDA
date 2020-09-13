
struct lista //tipo n� da fila
{
    int valor;
    struct lista *prox;
};

typedef struct lista Lista;

struct fila // n� descritor
{
    Lista *inicio;
    Lista *fim;
    int qtd;
};

typedef struct fila Fila;

//------------------------fun��es-----------------------------------


  Fila* criaFila();
  void insereFila(Fila *fila , int valor_inserido);
  void remocao(Fila *fila);
  void imprimeFila(Fila *fila);
  void tamnanhoFila(Fila *fila);
  void fila_vazia(Fila *fila);
  int libera(Fila *fila);
  void buscar(Fila *fila , int valor);

