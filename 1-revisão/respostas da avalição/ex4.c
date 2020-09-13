#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int ra;
    char nome[40];
    int ano_ingresso;
    char curso [80];
    int num_matricula;
    int status;

}Alunos;

void cadastro(Alunos *alu,int total,int num_desejado);
void alterar(Alunos *alu, int total);


int main()
{
    Alunos alunos [5];
    int escolha_menu;
    int total;
    int num_desejado;




    do
    {
            do
        {
            system("cls");
            printf("1-NOVAS MATRICULAS");
            printf("\n");
            printf("2-ALTERAR MATRICULAS");
            printf("\n");
            printf("3-SAIR");
            printf("\n\n");
            printf("ESCOLHA: ");
            scanf("%d",&escolha_menu);


        }while(escolha_menu < 1 || escolha_menu > 3);

        total = 0;

        if(escolha_menu == 1)
        {
             printf("Insira quantos deseja cadastar: ");
             scanf("%d",&num_desejado);

            if(total > 5 )
            {
                printf("CADASTRO CHEIO");
                system("pause");
            }
            if(total + num_desejado > 5)
            {
                printf("O CADASTRO IRA ULTRAPASSAR O LIMITE");
                total = num_desejado;
                system("pause");
            }
            if(total <= 5)
            {

                cadastro(&alunos,total,num_desejado);
                total = total + num_desejado;

            }
        }
        if(escolha_menu == 2)
        {
            alterar(&alunos,total);
        }

    }while(escolha_menu != 3);

    return 0;
}
void cadastro(Alunos *alu,int total,int num_desejado)
{
    int i = total;
    int cont = 0;



        system("cls");

        printf("-------------CADASTRO--------------");
        printf("\n\n");

        do
        {

            printf("INSIRA O RA DO ALUNO: ");
            scanf("%d",&alu[i].ra);
            printf("INSIRA O ANO DE INGRESSAO:");
            scanf("%d",&alu[i].ano_ingresso);
            do
            {
                printf("INSIRA O STATUS DO ALUNO [1-CURSANDO|2-FORMADO]");
                scanf("%d",&alu[i].status);
                if(alu[i].status < 1 || alu[i].status > 2)
                {
                    printf("OPCAO INVALIDA");
                }
            }while(alu[i].status < 1 || alu[i].status > 2);
            alu[i].num_matricula = i;
            fflush(stdin);
            printf("INSIRA O NOME DO CURSO: ");
            fgets(alu[i].curso,80,stdin);
            fflush(stdin);
            printf("INSIRA O NOME DO ALUNO: ");
            fgets(alu[i].nome,40,stdin);
            fflush(stdin);


            i++;
            cont++;
            printf("%d",cont);
            printf("%d",num_desejado);
            system("pause");
        }while(cont!= num_desejado);


}

void alterar(Alunos *alu, int total)
{
    int cod;
    int i;
    int ra = 0;

    printf("INSIRA O RA DO ALUNO");
    scanf("%d",&cod);

    for(i = 0; i < total;i++)
    {
        if(alu[i].ra == cod)
        {
            ra = 1;
            i = total;
        }
    }

    if(ra == 1)
    {
           fflush(stdin);
            printf("INSIRA O RA DO ALUNO: ");
            scanf("%d",&alu[i].ra);
            printf("INSIRA O ANO DE INGRESSAO:");
            scanf("%d",&alu[i].ano_ingresso);
            do
            {
                printf("INSIRA O STATUS DO ALUNO [1-CURSANDO|2-FORMADO]");
                scanf("%d",&alu[i].status);
                if(alu[i].status < 1 || alu[i].status > 2)
                {
                    printf("OPCAO INVALIDA");
                }
            }while(alu[i].status < 1 || alu[i].status > 2);
            alu[i].num_matricula = i;
            fflush(stdin);
            printf("INSIRA O NOME DO CURSO: ");
            fgets(alu[i].curso,80,stdin);
            fflush(stdin);
            printf("INSIRA O NOME DO ALUNO: ");
            fgets(alu[i].nome,40,stdin);
    }
    if(ra == 0)
    {
        printf("ESTE RA NAO EXISTE");
    }








}
