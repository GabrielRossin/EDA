
struct lista //tipo nó da fila
{
    int valor;
    struct lista *prox;
};

typedef struct lista Lista;

struct fila // nó descritor
{
    Lista *inicio;
    Lista *fim;
    int qtd;
};

typedef struct fila Fila;

//------------------------funções-----------------------------------


  Fila* criaFila();
  void insereFila(Fila *fila , int valor_inserido);
  void remocao(Fila *fila);
  void imprimeFila(Fila *fila);
  void tamnanhoFila(Fila *fila);
  void fila_vazia(Fila *fila);
  int libera(Fila *fila);
  void buscar(Fila *fila , int valor);

