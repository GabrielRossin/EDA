struct no
{
    int dado;
    struct no *sae; //ponteiro para sub-árvore esquerda
    struct no *sad; //ponteiro para sub-árvore direita
};

typedef struct no *arvore_Binaria;


arvore_Binaria* criarArvBin();
void liberaArvBin(arvore_Binaria *raiz);
void libera_No(struct no *pontoNO);
int alturaArvBin(arvore_Binaria *raiz);
void pre_orderm(arvore_Binaria *raiz);
void em_orderm(arvore_Binaria *raiz);
void pos_orderm(arvore_Binaria *raiz);
int inserirOrdenadoArvBin(arvore_Binaria *raiz , int valor);
int buscaArvBin(arvore_Binaria *raiz , int valor);
arvore_Binaria* busca_recursiva(arvore_Binaria *raiz , int valor);
void insere_recursiva(arvore_Binaria *raiz, int valor);


