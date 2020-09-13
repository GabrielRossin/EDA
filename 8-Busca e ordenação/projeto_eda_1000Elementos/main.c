#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "prototipos.h"

int main()
{
    int vet_desor[1000];
    int vet_ordC[1000];
    int vet_ordD[1000];
    int vet_res[1000];
    int n = 1000;

    int resp;
    int resp_interno;

    LARGE_INTEGER frequence;
    LARGE_INTEGER ini;
    LARGE_INTEGER last;
    double tempo;

    int inicio;
    int fim;
    int i;

    preenche_aleatorio(vet_desor, n);
    inicio = 0;
    fim = n-1;

    do
    {
        system("cls");
        printf("---------MENU-----------");
        printf("\n1.INSERT SORT");
        printf("\n2.SELECTION SORT");
        printf("\n3.BUBBLE SORT");
        printf("\n4.MERGE SORT");
        printf("\n5.QUICK SORT");
        printf("\n6.SAIR");
        printf("\nSUA ESCOLHA: ");
        scanf("%d" , &resp);

        switch (resp)
        {
            case 1:
            {
                printf("\n------------------------------\n");
                printf("\n1.VETOR DESORDENADO");
                printf("\n2.VETOR ORDENADO CRESCENTE");
                printf("\n3.VETOR ORDENADO DECRESCENTE");
                printf("\nSUA ESCOLHA: ");
                scanf("%d" , &resp_interno);

                switch (resp_interno)
                {
                    case 1:
                        {
                                QueryPerformanceFrequency(&frequence);
                                QueryPerformanceCounter(&ini);

                                insertSort(vet_desor, n);

                                QueryPerformanceCounter(&last);
                                tempo = (float) (last.QuadPart - ini.QuadPart) / frequence.QuadPart;

                                printf("\nTempo gasto: %f ms.", tempo);
                                fflush(stdin);
                                getchar();

                                break;

                        }
                    case 2:
                        {
                                preenche_crescente(vet_ordC , n);

                                QueryPerformanceFrequency(&frequence);
                                QueryPerformanceCounter(&ini);

                                insertSort(vet_ordC, n);

                                QueryPerformanceCounter(&last);

                                tempo = (float) (last.QuadPart - ini.QuadPart) / frequence.QuadPart;


                                printf("\nTempo gasto: %f ms.", tempo);
                                fflush(stdin);
                                getchar();

                                break;
                        }
                    case 3:
                        {
                                preenche_decrescente(vet_ordD , n);

                                QueryPerformanceFrequency(&frequence);
                                QueryPerformanceCounter(&ini);


                                insertSort(vet_ordD , n);

                                QueryPerformanceCounter(&last);
                                tempo = (float) (last.QuadPart - ini.QuadPart) / frequence.QuadPart;

                                printf("\nTempo gasto: %f ms.", tempo);
                                fflush(stdin);
                                getchar();

                                break;

                        }
                    default:
                        {

                            printf("ESCOLHA INVALIDA");
                            fflush(stdin);
                            getchar();
                            break;

                        }

                }
                break;
            }
            case 2:
            {
                printf("\n------------------------------\n");
                printf("\n1.VETOR DESORDENADO");
                printf("\n2.VETOR ORDENADO CRESCENTE");
                printf("\n3.VETOR ORDENADO DECRESCENTE");
                printf("\nSUA ESCOLHA: ");
                scanf("%d" , &resp_interno);

                switch (resp_interno)
                {
                    case 1:
                        {

                                QueryPerformanceFrequency(&frequence);
                                QueryPerformanceCounter(&ini);

                                selectionSort(vet_desor, n);

                                QueryPerformanceCounter(&last);
                                tempo = (float) (last.QuadPart - ini.QuadPart) / frequence.QuadPart;

                                printf("\nTempo gasto: %f ms.", tempo);
                                fflush(stdin);
                                getchar();

                                break;

                        }
                    case 2:
                        {
                                preenche_crescente(vet_ordC , n);

                                QueryPerformanceFrequency(&frequence);
                                QueryPerformanceCounter(&ini);

                                selectionSort(vet_ordC, n);

                                QueryPerformanceCounter(&last);
                                tempo = (float) (last.QuadPart - ini.QuadPart) / frequence.QuadPart;

                                printf("\nTempo gasto: %f ms.", tempo);
                                fflush(stdin);
                                getchar();

                                break;
                        }
                    case 3:
                        {
                                preenche_decrescente(vet_ordD , n);

                                QueryPerformanceFrequency(&frequence);
                                QueryPerformanceCounter(&ini);


                                selectionSort(vet_ordD , n);

                                QueryPerformanceCounter(&last);
                                tempo = (float) (last.QuadPart - ini.QuadPart) / frequence.QuadPart;

                                printf("\nTempo gasto: %f ms.", tempo);
                                fflush(stdin);
                                getchar();

                                break;

                        }
                    default:
                        {
                            printf("ESCOLHA INVALIDA");
                            fflush(stdin);
                            getchar();
                            break;
                        }

                }

                break;
            }

            case 3:
            {

                printf("\n------------------------------\n");
                printf("\n1.VETOR DESORDENADO");
                printf("\n2.VETOR ORDENADO CRESCENTE");
                printf("\n3.VETOR ORDENADO DECRESCENTE");
                printf("\nSUA ESCOLHA: ");
                scanf("%d" , &resp_interno);

                    switch (resp_interno)
                {
                    case 1:
                        {

                                QueryPerformanceFrequency(&frequence);
                                QueryPerformanceCounter(&ini);

                                bubbleSort(vet_desor, n);

                                QueryPerformanceCounter(&last);
                                tempo = (float) (last.QuadPart - ini.QuadPart) / frequence.QuadPart;


                                printf("\nTempo gasto: %f ms.", tempo);
                                fflush(stdin);
                                getchar();

                                break;

                        }
                    case 2:
                        {
                                preenche_crescente(vet_ordC , n);

                                QueryPerformanceFrequency(&frequence);
                                QueryPerformanceCounter(&ini);

                                bubbleSort(vet_ordC, n);

                                QueryPerformanceCounter(&last);
                                tempo = (float) (last.QuadPart - ini.QuadPart) / frequence.QuadPart;

                                printf("\nTempo gasto: %f ms.", tempo);
                                fflush(stdin);
                                getchar();

                                break;
                        }
                    case 3:
                        {
                                preenche_decrescente(vet_ordD , n);

                                QueryPerformanceFrequency(&frequence);
                                QueryPerformanceCounter(&ini);

                                bubbleSort(vet_ordD , n);

                                QueryPerformanceCounter(&last);
                                tempo = (float) (last.QuadPart - ini.QuadPart) / frequence.QuadPart;

                                printf("\nTempo gasto: %f ms.", tempo);
                                fflush(stdin);
                                getchar();

                                break;

                        }
                    default:
                        {
                            printf("ESCOLHA INVALIDA");
                            fflush(stdin);
                            getchar();
                            break;
                        }

                }
                break;
            }
            case 4:
            {
                    printf("\n------------------------------\n");
                    printf("\n1.VETOR DESORDENADO");
                    printf("\n2.VETOR ORDENADO CRESCENTE");
                    printf("\n3.VETOR ORDENADO DECRESCENTE");
                    printf("\nSUA ESCOLHA: ");
                    scanf("%d" , &resp_interno);

                    switch (resp_interno)
                    {
                    case 1:
                        {

                                for(i = 0; i < n; i++)
                                {
                                    vet_res[i] = vet_desor[i];
                                }


                                QueryPerformanceFrequency(&frequence);
                                QueryPerformanceCounter(&ini);

                                mergeSort(vet_res,inicio,fim);

                                QueryPerformanceCounter(&last);
                                tempo = (float) (last.QuadPart - ini.QuadPart) / frequence.QuadPart;

                                printf("\nTempo gasto: %f ms.", tempo);
                                  /*for(i = 0; i < 100; i++)
                                {
                                    printf("\n%d" , vet_res[i]);
                                }*/
                                fflush(stdin);
                                getchar();

                                break;

                        }
                    case 2:
                        {
                                preenche_crescente(vet_ordC , n);

                                for(i = 0; i < n; i++)
                                {
                                    vet_res[i] = vet_ordC[i];
                                }

                                QueryPerformanceFrequency(&frequence);
                                QueryPerformanceCounter(&ini);

                                mergeSort(vet_res,inicio,fim);

                                QueryPerformanceCounter(&last);
                                tempo = (float) (last.QuadPart - ini.QuadPart) / frequence.QuadPart;

                                printf("\nTempo gasto: %f ms.", tempo);
                                  /*for(i = 0; i < n; i++)
                                    {
                                        printf("\n%d" , vet_res[i]);
                                    }*/
                                fflush(stdin);
                                getchar();

                                break;
                        }
                    case 3:
                        {
                                preenche_decrescente(vet_ordD , n);

                                for(i = 0; i < n; i++)
                                {
                                    vet_res[i] = vet_ordC[i];
                                }

                                QueryPerformanceFrequency(&frequence);
                                QueryPerformanceCounter(&ini);

                                mergeSort(vet_res ,inicio,fim);

                                QueryPerformanceCounter(&last);
                                tempo = (float) (last.QuadPart - ini.QuadPart) / frequence.QuadPart;

                                printf("\nTempo gasto: %f ms.", tempo);
                                  /*for(i = 0; i < n ; i++)
                                {
                                    printf("\n%d" , vet_res[i]);
                                }*/
                                fflush(stdin);
                                getchar();

                                break;

                        }
                    default:
                        {
                            printf("ESCOLHA INVALIDA");
                            fflush(stdin);
                            getchar();
                            break;
                        }

                }
                break;
            }
            case 5:
            {
                    printf("\n------------------------------\n");
                    printf("\n1.VETOR DESORDENADO");
                    printf("\n2.VETOR ORDENADO CRESCENTE");
                    printf("\n3.VETOR ORDENADO DECRESCENTE");
                    printf("\nSUA ESCOLHA: ");
                    scanf("%d" , &resp_interno);

                    switch (resp_interno)
                    {
                        case 1:
                        {

                                for(i = 0; i < n; i++)
                                {
                                    vet_res[i] = vet_desor[i];
                                }

                                QueryPerformanceFrequency(&frequence);
                                QueryPerformanceCounter(&ini);

                                quickSort(vet_res,inicio,fim);

                                QueryPerformanceCounter(&last);
                                tempo = (float) (last.QuadPart - ini.QuadPart) / frequence.QuadPart;

                                printf("\nTempo gasto: %f ms.", tempo);
                                fflush(stdin);
                                getchar();

                                break;

                        }
                    case 2:
                        {
                                preenche_crescente(vet_ordC , n);

                                for(i = 0; i < n; i++)
                                {
                                    vet_res[i] = vet_ordC[i];
                                }

                                QueryPerformanceFrequency(&frequence);
                                QueryPerformanceCounter(&ini);

                                quickSort(vet_res,inicio,fim);

                                QueryPerformanceCounter(&last);
                                tempo = (float) (last.QuadPart - ini.QuadPart) / frequence.QuadPart;

                                printf("\nTempo gasto: %f ms.", tempo);
                                fflush(stdin);
                                getchar();

                                break;
                        }
                    case 3:
                        {
                                preenche_decrescente(vet_ordD , n);

                                for(i = 0; i < n; i++)
                                {
                                    vet_res[i] = vet_ordD[i];
                                }

                                QueryPerformanceFrequency(&frequence);
                                QueryPerformanceCounter(&ini);

                                quickSort(vet_res ,inicio,fim);

                                QueryPerformanceCounter(&last);
                                tempo = (float) (last.QuadPart - ini.QuadPart) / frequence.QuadPart;


                                printf("\nTempo gasto: %f ms.", tempo);
                                fflush(stdin);
                                getchar();

                                break;

                        }
                    default:
                        {
                            printf("ESCOLHA INVALIDA");
                            fflush(stdin);
                            getchar();
                            break;
                        }


                    }
                break;
            }
            case 6:
                {
                    printf("SAINDO....");
                    fflush(stdin);
                    getchar();
                    break;
                }

            default:
            {
                    printf("ESCOLHA INVALIDA");
                    fflush(stdin);
                    getchar();
                    break;

            }



        }

    }while(resp != 6);

    return 0;
}
