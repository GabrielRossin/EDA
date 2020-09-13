#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(int argc, char const *argv[])
{
    int escolha_menu;
    int valor;
    int recriar = 0;
    Fila *F = criaFila();

    do
    {
        system("cls");
        printf("\n-----------------MENU------------");
        printf("\n1-INSERIR NA FILA");
        printf("\n2-REMOVER DA FILA");
        printf("\n3-IMPRIMIR A FILA");
        printf("\n4-TAMANHO DA FILA");
        printf("\n5-VERIFICAR FILA VAZIA");
        printf("\n6-LIBERAR FILA");
        printf("\n7-RECRIAR A FILA");
        printf("\n8-BUSCAR");
        printf("\n9-SAIR\n");
        scanf("%d",&escolha_menu);

        switch(escolha_menu)
        {
	        case 1:
	        {

	            system("cls");
                printf("\nPROCESSO DE INSERIR NA FILA FOI SELECIONADO\n\n\n");
                if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A FILA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {
                    printf("\nINFORME O VALOR: ");
                    scanf("%d", &valor);

                    insereFila(F, valor);

                }

	             break;
	        }

	        case 2:
	        {
	            system("cls");
                printf("\nPROCESSO DE REMOVER NA FILA FOI SELECIONADO\n\n\n");

                if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A FILA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {

                    remocao(F);
                }

		    	break;

	        }
	        case 3:
            {
		       system("cls");
               printf("\nPROCESSO DE IMPRIMIR A FILA FOI SELECIONADO\n\n\n");

               if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A FILA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {
                    imprimeFila(F);
                }

		       break;

		    }

		    case 4:
		    {
		    	if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A FILA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();

                }

                else
                {
                    tamnanhoFila(F);
                }

	            break;

		    }

		    case 5:
		    {
		    	system("cls");
                printf("\nPROCESSO DE VERFICAR FILA VAZIA FOI SELECIONADO\n\n\n");

                if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A FILA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {

                    fila_vazia(F);
                }

		        break;

		    }
		    case 6:
		    {
		    	system("cls");
                printf("\nPROCESSO DE LIBERAR A FILA FOI SELECIONADO\n\n\n");

                if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A FILA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {

                   recriar = libera(F);
                }

		    	break;
		    }

		    case 7:
		    {
                system("cls");
                printf("\nPROCESSO DE RECRIAR A FILA FOI SELECIONADO\n\n\n");

		    	if(recriar == 0)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A FILA NAO FOI LIBERADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {
                    F = criaFila();

                    printf("FILA RECRIADA COM SUCESSO");
                    recriar = 0;
                    getchar();
                }

		    	break;
		    }

	        case 8:
            {
                system("cls");
                printf("\nPROCESSO DE BUSCAR ELEMENTOS NA FILA FOI SELECIONADO\n\n\n");

                 if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A FILA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {
                    printf("\nINFORME O VALOR: ");
                    scanf("%d", &valor);

                    buscar(F , valor);
                }

                break;

            }
            case 9:
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

    }while(escolha_menu != 9);

    return 0;
}
