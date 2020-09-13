#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

Fila* criaFila()
{
      Fila *fila = (Fila*)malloc(sizeof(Fila));
      if (fila ==  NULL)
      {
        printf("\nFILA NAO CRIADA");
      }
      else //Inicializa os campos do n� construtor.
      {
        fila->inicio = NULL;
        fila->fim = NULL;;
        fila->qtd = 0;
      }
    return fila;
}

void insereFila(Fila *fila , int valor_inserido)
{
    system("cls");
    printf("\n\n\n------PROCESSO DE INSERIR NA FILA SELECIONADO-----\n\n\n");

    if(fila == NULL) //Fila n�o criada
    {
        printf("\nFILA NAO CRIADA");

    }
    else
    {
      Lista *novoNo = (Lista*) malloc(sizeof(Lista)); //Aloca um novo n�

      if(novoNo == NULL) // Erro na aloca��o
      {
          printf("\n ERRO NA ALOCACAO");

      }
      else
      {

        novoNo->valor = valor_inserido; //armazena a informa��o no novo n�
        novoNo->prox = NULL; //novo n� aponta para null pois ele ser� o ultmimo elemento
        if(fila->qtd == 0 || fila->inicio == NULL || fila->fim == NULL)//fila vazia
        {
            fila->inicio = novoNo;// descritor inicio recebe e insere no inicio
            /*
                como a fila est� vazia o n� descristor inicio e fim ir� apontar
                para o mesmo n�
            */
        }
        else
        {
          fila->fim->prox = novoNo; //O prox do ultimo n� aponta para o n� criado
        }
        fila->fim = novoNo; //descritor fim recebe e insere no fim
        fila->qtd++; //incrementa a quantidade de n�s da lista

      }
        printf("VALOR INSERIDO COM SUCESSSO");
    }
    fflush(stdin);
    printf("\nPRESSIONE QUALQUER TECLA PARA CONTINUAR");
    getchar();
    //system("pause >> NULL");


}

void remocao(Fila *fila)
{
    system("cls");
    printf("\n\n\n------PROCESSO DE REMOVER DA FILA SELECIONADO-----\n\n\n");

    if(fila == NULL) //fila nao alocada
    {
      printf("\nFILA NAO ALOCADA");
    }
    else
    {
      if(fila->qtd == 0 && fila->inicio == NULL && fila->fim == NULL)
      {
        printf("\nFILA VAZIA");
      }
      else
      {
        int valor;

        Lista *aux = fila->inicio;

        valor = aux->valor;

        fila->inicio = fila->inicio->prox;

        if(fila->inicio == NULL) //fila ficar� vazia?
        {
          fila->fim == NULL;
        }
        printf("\nVALOR REMOVIDO: %d",valor);
        free(aux); // retira o n�
        fila->qtd--; //descrementa a quantidade de n� da fila
      }
    }
    fflush(stdin);
    printf("\nPRESSIONE QUALQUER TECLA PARA CONTINUAR");
    getchar();
    //system("pause >> NULL");
}

void imprimeFila(Fila *fila)
{
      system("cls");
      printf("\n\n\n------PROCESSO DE IMPRIMR A FILA SELECIONADO-----\n\n\n");

      Lista *aux;
      if (fila == NULL)
      {
        printf("\nFILA NAO ALOCADA");
      }
      else
      {
          if(fila->qtd == 0 && fila->inicio == NULL && fila->fim == NULL)
          {
              printf("\nFILA VAZIA");
          }
          else
          {

              for(aux = fila->inicio; aux != NULL ; aux = aux->prox)
              {
                  printf("%d\n",aux->valor);
              }

          }

      }
      fflush(stdin);
      printf("\nPRESSIONE QUALQUER TECLA PARA CONTINUAR");
      getchar();
      //system("pause >> NULL");

}

void tamnanhoFila(Fila *fila)
{
    system("cls");
    printf("\n\n\n------PROCESSO DE VERIFICAR TAMANHO DA FILA SELECIONADO-----\n\n\n");

    Lista *aux;
    int cont = 0;
    if (fila == NULL)
    {
      printf("\nFILA NAO ALOCADA");
    }
    else
    {
        if(fila->qtd == 0 && fila->inicio == NULL && fila->fim == NULL)
        {
          printf("\nFILA VAZIA");
        }
        else
        {
            for (aux = fila->inicio; aux != NULL; aux = aux->prox)
            {
              cont++;
            }
            printf("\nO TAMANHO DA FILA: %d", cont);
        }

      }
      fflush(stdin);
      printf("\nPRESSIONE QUALQUER TECLA PARA CONTINUAR");
      getchar();
      //system("pause >> NULL");


}

void fila_vazia(Fila *fila)
{
      system("cls");
      printf("\n\n\n------PROCESSO DE VERFICAR FILA VAZIA SELECIONADO-----\n\n\n");

      if (fila == NULL)
      {

        printf("\nFILA NAO ALOCADA");

      }
      else
      {

          if(fila->qtd == 0 && fila->inicio == NULL && fila->fim == NULL)
          {
            printf("\nFILA VAZIA");
          }
          else
          {
            printf("\nFILA NAO VAZIA");
          }

      }
      fflush(stdin);
      printf("\nPRESSIONE QUALQUER TECLA PARA CONTINUAR");
      getchar();
      //system("pause >> NULL");

}

int libera(Fila *fila)
{
      system("cls");
      printf("\n\n\n------PROCESSO DE LIBERAR A FILA SELECIONADO-----\n\n\n");

      int recriar = 0;

      if (fila == NULL)
      {

        printf("\nFILA NAO ALOCADA");
      }
      else
      {
          if(fila->qtd == 0 && fila->inicio == NULL && fila->fim == NULL)
          {
              printf("\nFILA VAZIA");

          }
          else
          {
              Lista *aux = fila->inicio;
              while (aux != NULL)
              {
                  Lista *aux2 = aux->prox;
                  free(aux);
                  aux = aux2;
              }
              recriar = 1;
          }

          printf("\nFILA LIBERADA");
      }
      fflush(stdin);
      printf("\nPRESSIONE QUALQUER TECLA PARA CONTINUAR");
      getchar();
      return recriar;
      //system("pause >> NULL");

}

void buscar(Fila *fila , int valor)
{
    Lista *aux;
    int permit = 1;
    if (fila == NULL)
    {

        printf("\nFILA NAO ALOCADA");
    }
    else
    {
        if(fila->qtd == 0 && fila->inicio == NULL && fila->fim == NULL)
        {
              printf("\nFILA VAZIA");

        }
        else
        {
              for (aux = fila; aux != NULL; aux = aux->prox)
              {
                if (aux->valor == valor)
                {
                  printf("\n O VALOR %d FOI ENCONTRADO NA FILA" ,valor);
                  permit = 0;
                }
              }

              if (permit == 1)
              {
                printf("\n O VALOR %d NAO FOI ENCONTRADO NA FILA" ,valor);
              }
        }

    }
    fflush(stdin);
    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
    getchar();
}
