#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prototipos.h"

void preenche_aleatorio ( int *v, int n )
{
    int i;

	for ( i = 0; i < n; i++ )
    {
		v[i] = rand ();
	}

}
void preenche_crescente ( int *vetC, int n )
{
	int i;

	for ( i = 0; i < n; i++ )
    {
		vetC[i] = i;
	}

}
void preenche_decrescente(int *vetD , int n)
{
    int i;
    int z = n -1;
    for(i = 0; i < n; i++)
    {
        vetD[i] = z - i;

    }
}
void insertSort(int *v,int n)
{
    int i;
    int j;
    int v2[100];
    int atual;

    for(i = 0; i < n; i++)
    {
        v2[i] = v[i];

    }

    for(i = 1; i<n; i++)
    {
        atual = v2[i];
        for(j = i; (j > 0) &&(atual < v2[j - 1]); j--)
        {

            v2[j] = v2[j - 1];
        }

        v2[j] = atual;
    }
    /*for(i = 0; i < n; i++)
    {
        printf("%d|", v[i]);
        printf("%d\n" , v2[i]);
    }*/

}
void selectionSort(int *v, int n)
{
    int i;
    int j;
    int posMenor;
    int troca;
    int v2[100];

    for(i = 0; i < n; i++)
    {
        v2[i] = v[i];
    }

    for(i = 0; i < n-1; i++)
    {
        posMenor = i;

        for(j = i+1; j < n; j++)
        {
            if(v2[j] < v2[posMenor])
            {
                posMenor = j;
            }
        }
        if(i != posMenor)
        {
            troca = v2[i];
            v2[i] = v2[posMenor];
            v2[posMenor] = troca;
        }
    }
    /*for(i = 0; i < n; i++)
    {
        printf("\n%d" , v2[i]);
    }*/

}
void bubbleSort(int *v , int n)
{
    int i;
    int continua;
    int aux;
    int fim = n;
    int v2[100];

    for(i = 0; i < n; i++)
    {
        v2[i] = v[i];
    }

    do
    {
        continua = 0;
        for(i = 0; i < fim - 1; i++)
        {
            if(v2[i] > v2[i+1] )
            {
                aux = v2[i];
                v2[i] = v2[i+1];
                v2[i+1] = aux;
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);
     /*for(i = 0; i < n; i++)
    {
        printf("\n%d" , v2[i]);
    }*/
}
void mergeSort(int *v , int inicio , int fim)
{
    int meio;
    int i;

    if(inicio < fim)
    {
        meio = floor( (inicio + fim) / 2);
        mergeSort(v , inicio , meio);
        mergeSort(v , meio + 1 , fim);
        mergge(v , inicio , meio , fim);
    }
}
void mergge(int *v , int inicio , int meio , int fim)
{
    int *temp;
    int p1;
    int p2;
    int tamanho;
    int i;
    int j;
    int k;
    int fim1 = 0; int fim2 = 0;
    tamanho = fim - inicio+1;
    p1 = inicio;
    p2 = meio+1;


    temp = (int *) malloc(tamanho *sizeof(int));
    if(temp != NULL)
    {
        for(i = 0; i < tamanho; i++)
        {
            if(!fim1 && !fim2)
            {
                if(v[p1] < v[p2])
                {
                    temp[i] = v[p1++];
                }
                else
                {
                    temp[i] = v[p2++];
                }
                if(p1 > meio)
                {
                    fim1 = 1;
                }
                if(p2 > fim)
                {
                    fim2 = 1;
                }
            }
            else
            {
                if(!fim1)
                {
                    temp[i] = v[p1++];
                }
                else
                {
                    temp[i] = v[p2++];
                }
            }
        }
        for(j = 0 , k = inicio; j < tamanho; j++ , k++)
        {
            v[k] = temp[j];
        }
    }
    free(temp);
}
void Swap(int *x, int *y)
{
    int Temp;
    Temp = *x;
    *x = *y;
    *y = Temp;
}
void quickSort(int *v, int first, int last)
{
    int pivot, i, j;
    if(first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while(v[i] <= v[pivot] && i < last)
                i++;
            while(v[j] > v[pivot])
                j--;
            if(i < j)
            {
                Swap(&v[i], &v[j]);
            }
        }
        Swap(&v[pivot], &v[j]);
        quickSort(v, first, j - 1);
        quickSort(v, j + 1, last);
    }
    /*for(i = 0; i < n; i++)
    {
        printf("\n%d" , v[i]);
    }*/
}
