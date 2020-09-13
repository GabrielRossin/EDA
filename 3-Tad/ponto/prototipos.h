
typedef struct ponto Ponto;
//Cria um novo ponto e devolve um ponteiro para o
Ponto* criapto (float x, float y);
// L ibera um novo ponto
void liberapto (Ponto* p);
//Acessa valores de x e y
void acessaPto (Ponto* p, float* x, float* y);
//Atribui valores de x e y ao ponto p
void atribuipto (Ponto* p, float x, float y);
//CaLcuIa distância entre dois pontos
float distanciapto (Ponto* PI, Ponto* p2);

