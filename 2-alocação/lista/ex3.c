#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sortear(int numeroSortedo[]);
void lerBilhete(int bilhete[]);
int compara(int numeroSortedo [] ,  int bilhete []);
void alocar(int numeroSortedo[] , int bilhete[] , int cont , int *vetorFinal[]);
void  exibir(int numeroSortedo[] , int vetorFinal[] , int cont);


int main(int argc, char const *argv[])
{
  int numeroSortedo[6];
  int bilhete[6];
  int *vetorFinal;
  int cont = 0;
  int i;

  sortear(numeroSortedo);
  lerBilhete(bilhete);
  cont = compara(numeroSortedo , bilhete );
  alocar(numeroSortedo , bilhete , cont , &vetorFinal);
  free(vetorFinal);

  return 0;
}
void sortear(int numeroSortedo[])
{
  int i;
  srand(time(NULL));

  for (i = 0; i < 6; i++)
  {
    numeroSortedo[i] = rand() % 10;
  }
   for (i = 0; i < 6; i++)
  {
    printf("\n%d",numeroSortedo[i]);
  }
    printf("\n-----------------------\n");
}
void lerBilhete(int bilhete[])
{
  int i;

  for ( i = 0; i < 6; i++)
  {
    printf("INSIRA O %d DO SEU BILHETE:" , i+1);
    scanf("%d",&bilhete[i]);
  }

}
int compara(int numeroSortedo [] ,  int bilhete [])
{
    int i;
    int cont = 0;

    for (i = 0; i < 6; i++)
    {
      if(numeroSortedo[i] == bilhete [i])
      {
        cont++;
      }
    }

    return(cont);

}
void alocar(int numeroSortedo[] , int bilhete[] , int cont , int *vetorFinal[])
{

  int i;

  vetorFinal = (int *)calloc(cont , sizeof(int));
  for (i = 0; i < 6; i++)
  {
    //printf("\n%d | %d",numeroSortedo[i],bilhete[i]);
    if(numeroSortedo[i] == bilhete [i])
    {
      vetorFinal[i] = bilhete[i];
    }
  }

  exibir(numeroSortedo , vetorFinal ,cont);


}

void  exibir(int numeroSortedo[] , int vetorFinal[] , int cont)
{
  int i;
  printf("\n\n\n-----NUMEROS SORTEADOS-------");
  for (i = 0; i < 6; i++)
  {
    printf("\n%d",numeroSortedo[i]);
  }
  printf("\n\n");
  printf("-----NUMEROS ACEERTADOS-------");
  if(cont > 0)
  {
      for (i = 0; i < cont; i++)
      {
        printf("\n%d",(int*)vetorFinal[i]);
      }
  }
  else
  {
      printf("\nNAO HOUVE ACERTOS");
  }


}



