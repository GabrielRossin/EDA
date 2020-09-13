#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int main(int argc, char const *argv[])
{
	int opcao = 0;
    int valor;
    int recriar = 0;

	Pilha *P;
	P = pilha_cria();

    do
    {
        system("cls");
        printf("\n---------MENU----------\n");
        printf("\n1. INSERIR NA PILHA.");
        printf("\n2. RETIRAR DA PILHA.");
        printf("\n3. MOSTRAR ELEMENTOS DA PILHA");
        printf("\n4. CONTAR ELEMENTOS DA PILHA");
        printf("\n5. BUSCAR ELEMENTOS DA PILHA");
        printf("\n6. VERIFICAR SE A PILHA ESTA VAZIA");
        printf("\n7. LIBERAR A LISTA");
        printf("\n8.  RECRIAR A LISTA");
        printf("\n9. SAIR.");
        printf("\nSua escolha:");
        scanf("%d", &opcao);

        switch(opcao)
        {
	        case 1:
	        {

	            system("cls");
                printf("\nPROCESSO DE INSERIR NA PILHA FOI SELECIONADO\n\n\n");
                if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A PILHA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {
                    printf("\nINFORME O VALOR: ");
                    scanf("%d", &valor);

                    pilha_push(P, valor);

                }

	             break;
	        }

	        case 2:
	        {
	            system("cls");
                printf("\nPROCESSO DE REMOVER DA PILHA FOI SELECIONADO\n\n\n");

                if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A PILHA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {
                    pilha_pop(P);
                }

		    	break;

	        }

		    case 3:
		    {
		    	if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A PILHA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();

                }

                else
                {
                    imprime(P);
                }

	            break;

		    }

		    case 4:
		    {
		    	system("cls");
                printf("\nPROCESSO DE CONTAR ELEMENTOS NA PILHA FOI SELECIONADO\n\n\n");

                if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A PILHA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {
                    tamanho(P);
                }

		        break;

		    }
		    case 5:
		    {
		    	system("cls");
                printf("\nPROCESSO DE BUSCAR ELEMENTOS DA PILHA FOI SELECIONADO\n\n\n");

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

                    buscar(P , valor);
                }
		    	break;
		    }

		    case 6:
		    {

		    	system("cls");
                printf("\nPROCESSO DE VERIFICAR PILHA VAZIA FOI SELECIONADO\n\n\n");

                 if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A PILHA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {
                    pilha_vazia(P);
                }

		    	break;
		    }

	        case 7:
            {
                if(recriar == 1)
                {
                    printf("\n\nOPCAO NAO PODE SER SELECIONA POIS A PILHA NAO FOI RECRIADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
                else
                {
                    recriar = libera(P);
                }

	            break;
	        }
	        case 8:
	        {
	        	system("cls");

	        	if(recriar == 0)
                {
                    printf("\n\nA PILHA NAO PODE SER RECRIADA POIS NAO FOI LIBERADA");
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
                }

                else
                {
                    P = pilha_cria();
                    printf("PILHA RECRIADA COM SUCESSO");
                    recriar = 0;
                    fflush(stdin);
                    printf("\n\nPRECISSIONE ENTER PARA CONTINUAR");
                    getchar();
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

    }while(opcao != 8);



	return 0;
}
