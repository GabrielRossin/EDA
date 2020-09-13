#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int main(int argc, char const *argv[])
{
    int opcao = 0;
    int valor;
    int recriar = 0;

    Lista *L;
    criarLista (&L);

    do
    {
        system("cls");
        printf("\n---------MENU----------\n");
        printf("\n1. INSERIR NO INICIO.");
        printf("\n2. INSERIR NO FIM");
        printf("\n3. INSERIR ORDENADO");
        printf("\n4. MOSTRAR VALORES DA LISTA.");
        printf("\n5. BUSCAR UM ELEMENTO DA LISTA");
        printf("\n6. RETIRAR UM ELEMENTO DA LISTA");
        printf("\n7. CONTAR ELEMENTOS DA LISTA");
        printf("\n8. LIBERAR A LISTA");
        printf("\n9  RECRIAR A LISTA");
        printf("\n10. SAIR.");
        printf("\nSua escolha:");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
            {

                system("cls");
                printf("\nPROCESSO DE INSERIR NO INICIO FOI SELECIONADO\n\n\n");
                if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A LISTA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {
                    printf("\nINFORME O VALOR: ");
                    scanf("%d", &valor);

                    inserirInicio(&L, valor);

                }

                 break;
            }

            case 2:
            {
                system("cls");
                printf("\nPROCESSO DE INSERIR NO FIM FOI SELECIONADO\n\n\n");

                if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A LISTA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {
                    printf("\nINFORME O VALOR: ");
                    scanf("%d", &valor);

                     inserirFim(&L , valor);
                }

                break;

            }

            case 3:
            {
               system("cls");
               printf("\nPROCESSO DE INSERIR ORDENADO FOI SELECIONADO\n\n\n");

               if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A LISTA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {
                     printf("\nINFORME O VALOR: ");
                     scanf("%d", &valor);

                    inserirMeio(&L , valor);
                }

               break;

            }

            case 4:
            {
                if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A LISTA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();

                }

                else
                {
                    escrever(L);
                }

                break;

            }

            case 5:
            {
                system("cls");
                printf("\nPROCESSO DE BUSCAR ELEMENTOS NA LISTA FOI SELECIONADO\n\n\n");

                if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A LISTA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {
                    printf("\nINFORME O VALOR: ");
                    scanf("%d", &valor);

                    buscar(L , valor);
                }

                break;

            }

            case 6:
            {
                system("cls");
                printf("\nPROCESSO DE RETIRAR ELEMENTOS DA LISTA FOI SELECIONADO\n\n\n");

                if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A LISTA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {
                    printf("\nINFORME O VALOR: ");
                    scanf("%d", &valor);

                   retirar(&L , valor);
                }

                break;
            }

            case 7:
            {

                if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A LISTA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {
                    contar(L);
                }

                break;
            }

            case 8:
            {
                if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A LISTA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {
                    recriar = liberar(L);
                }

                break;
            }
            case 9:
            {
                system("cls");

                if(recriar == 0)
                {
                    printf("\n\nA LISTA NAO PODE SER RECRIADA POIS NAO FOI LIBERADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }

                else
                {
                    criarLista (&L);
                    printf("LISTA RECRIADA COM SUCESSO");
                    recriar = 0;
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                    getchar();
                }

                break;

            }
            case 10:
            {
                 printf("\nSAINDO....");

                 fflush(stdin);
                 printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                 getchar();
                 break;

            }
            default:
                {
                    printf("\nEscolha invalida.");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                    break;
                }
        }

    }while(opcao != 10);



    return 0;
}

