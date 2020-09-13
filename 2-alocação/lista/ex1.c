#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  int *vetor;
  int i;
  vetor = (int *)calloc(5,sizeof(int));
  for (i = 0; i < 5; i++)
  {
    printf("Insira um numero:\n");
    scanf("%d",&vetor[i] );
  }
  printf("\n-------VALORES--------\n");
  for (i = 0; i < 5; i++)
  {
    printf("\n %d",vetor[i] );

  }
  free(vetor);

  return 0;
}
