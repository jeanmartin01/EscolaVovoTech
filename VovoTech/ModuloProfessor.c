#include "main.h"
#define MAX_ALUNOS 50
typedef struct
{
    char nome[MAX_ALUNOS];
    int matricula;
    int faltas;
    float nota1[10];
    float nota2[10];
    float nota3[10];
    float nota4[10];
}Aluno;

Aluno CA [MAX_ALUNOS];
void login();
void menu();
void cadastrar();
void remover();
void aprovados();
void reprovados ();
void pesquisar();
void listaralunos();
void Professor(){}

void ModuloProfessor()
{
    system ("cls");
    int op;
    do
    {
        system ("cls");
        printf("  ESCOLA VOVOTECH");
        printf("  \nBem vindo, Professor(a)!");
        printf("\n------------------------\n");
        printf("\n1- Lancamento de Notas/Faltas");
        printf("\n2- Remover Aluno");
        printf("\n3- Alunos Aprovados");
        printf("\n4- Alunos Reprovados");
        printf("\n5- Pesquisar Alunos");
        printf("\n6- Listar alunos");
        printf("\n7- Log-Off");
        printf("\n8- Fechar Programa\n\n");
        printf("Escolha a opcao desejada: ");
        scanf("%d", &op);
        getchar();
        switch(op)
        {
            case 1:
                cadastrar();
            break;

            case 2:
                remover();
            break;

            case 3:
                aprovados();
            break;

            case 4:
                reprovados();
            break;

            case 5:
                pesquisar();
            break;

            case 6:
                listaralunos();
            break;
            case 7:
                login();
                break;
            case 8:
                printf("OBRIGADO POR UTILIZAR NOSSO SISTEMA :)\n\n");
                system("pause");
                exit(0);
            default:
                printf("OPCAO INVALIDA - TENTE NOVAMENTE\n");
                system("pause");
                fflush(stdin);
                ModuloProfessor();


            break;
        }
        getchar();
    }
while(op!=0);
}
void cadastrar()
{
    system("cls");
    int op;
    struct CA;
    FILE *arquivo;
    arquivo = fopen("cadaluno.dat", "ab");
    if (arquivo!=NULL)
    {

       system("cls");



       printf("\nNome do aluno: ");
       fgets(CA->nome,sizeof(CA->nome),stdin);


       printf("\nDigite a matricula: ");
       scanf("%d", &CA->matricula);
       getchar();

       printf("\nDigite a numero de faltas: ");
       scanf("%d", &CA->faltas);


       printf("\nDigite as notas\n");
       printf("1- Bimestre: ");
       scanf("%f", CA->nota1);
       printf("2- Bimestre: ");
       scanf("%f", CA->nota2);
       printf("3- Bimestre: ");
       scanf("%f", CA->nota3);
       printf("4- Bimestre: ");
       scanf("%f", CA->nota4);
       fwrite(&CA, sizeof(Aluno),1, arquivo);
       fclose(arquivo);

        printf("\nNotas/Faltas lancadas!");
        printf("\n\n1- Novo Lancamento");
        printf("\n0- Voltar ao menu\n");
        printf("Escolha a opcao desejada: ");
        scanf("%d", &op);
        getchar();

    }
    else
    {
        printf("\nErro ao abrir o arquivo");
    }
         switch(op)
        {
            case 1:
                cadastrar();
            break;
            case 0:
                ModuloProfessor();
            break;
        }

}
void remover()
{

    FILE *arquivo, *temporario;
    arquivo = fopen("cadaluno.dat", "rb");
    temporario = fopen("temp.dat", "wb");
    if (arquivo == NULL)
    {
    printf("\nErro na abertura do arquivo.\n");
    }
    else
    {
    struct CA;
    int matricula;
    listaralunos();
    printf("\nDigite a matricula do aluno a ser removido: ");
    scanf("%d", &matricula);
    getchar();

        while(fread(&CA, sizeof(Aluno),1, arquivo)==1)
        {
            if (matricula!=CA->matricula)
            {
                fwrite(&CA, sizeof(Aluno),1, temporario);
            }
        }
    }

    if(ferror(temporario))
    {
        printf("\nErro ao remover\n");
    }
    else
    {
    printf("\nAluno removido com sucesso!\n\n");
    }

fclose(arquivo);
fclose(temporario);
remove ("cadaluno.dat");
rename ("temp.dat","cadaluno.dat");

}
void aprovados()
{


    FILE *arquivo;
    arquivo = fopen("cadaluno.dat", "rb");
    if (arquivo == NULL)
    {
    printf("\nErro na abertura do arquivo.\n");
    }
    else
    {
    system("cls");
    struct CA;
    float media;
    printf("LISTA DE ALUNOS APROVADOS\n");
    while (fread(&CA, sizeof(Aluno),1, arquivo)==1)
    {
        media = 0;
        media = *CA->nota1 + *CA->nota2 + *CA->nota3 + *CA->nota4;
        media = media/4;
                if (media >= 5.0)
        {
                printf("\n-----------------\n");
                printf("\nNome: %s",CA->nome);
                printf("Matricula: %d\n",CA->matricula);
                printf("Faltas %d\n", CA->faltas);
                printf ("Media: %.2f\n", media);

        }

    }

    }

    fclose(arquivo);
}
void reprovados()
{


    FILE *arquivo;
    arquivo = fopen("cadaluno.dat", "rb");
    if (arquivo == NULL)
    {
    printf("\nErro na abertura do arquivo.\n");
    }
    else
    {
    system("cls");
    struct CA;
    float media;
    printf("LISTA DE ALUNOS REPROVADOS\n");
    while (fread(&CA, sizeof(Aluno),1, arquivo)==1)
    {
        media = 0;
        media = *CA->nota1 + *CA->nota2 + *CA->nota3 + *CA->nota4;
        media = media/4;
                if (media < 5.0)


        {
                printf("\n-----------------\n");
                printf("\nNome: %s",CA->nome);
                printf("Matricula: %d\n",CA->matricula);
                printf("Faltas %d\n", CA->faltas);
                printf ("Media: %.2f\n", media);

        }

    }

    }

    fclose(arquivo);
}
void pesquisar()
{

    FILE *arquivo;
    arquivo = fopen("cadaluno.dat", "rb+");
    if (arquivo == NULL)
    {
        printf("\nErro na abertura do arquivo.\n");
    }
    else
        {
            system ("cls");
            char noome[MAX_ALUNOS];
            struct CA;
            int op;

           printf ("\nDigite o nome do aluno para pesquisar: ");
           scanf("%99[^\n]%*c", noome);
           system ("cls");
           printf("\nalunos com o nome \"%s\":\n\n", noome);
            Aluno CA;
while(1)
{
        size_t result = fread(&CA, sizeof(Aluno),1, arquivo);
        if(result==0)
        break;
        char noomeaux[MAX_ALUNOS];
        strcpy (noomeaux,CA.nome);

        if(strstr(noomeaux,noome)!=NULL)
        {
                printf("\n-----------------\n");
                printf("\nNome: %s",CA.nome);
                printf("Matricula: %d\n\n",CA.matricula);
                printf("Faltas: %d\n", CA.faltas);
                printf("1 Bim: %.2f\n",*CA.nota1);
                printf("2 Bim: %.2f\n",*CA.nota2);
                printf("3 Bim: %.2f\n",*CA.nota3);
                printf("4 Bim: %.2f\n",*CA.nota4);
                printf("\n-----------------\n\n");

        }

}
fclose(arquivo);


	fseek(stdin, 0, SEEK_END);


        printf("\n\n1- Nova pesquisa");
        printf("\n0- Voltar ao menu\n");
        printf("Escolha a opcao desejada: ");
        scanf("%d", &op);
        getchar();
                switch(op)
        {
            case 1:
                pesquisar();
            break;
            case 0:
                ModuloProfessor();
            break;
        }


    }

    }
void listaralunos()
{
int i;
FILE *arquivo;
arquivo = fopen("cadaluno.dat", "a+b");
    if (arquivo == NULL)
    {
    printf("\nErro na abertura do arquivo.\n");
    }
    else
    {
        system("cls");
        printf("\nLISTA DE ALUNOS\n");
        while (!feof(arquivo))
            {
                i=fread(&CA, sizeof(Aluno), 1, arquivo);
                if (ferror(arquivo))
                {
                    printf("Erro na leitura do arquivo");
                }
                        else
                    {
                        if (i != 0)
                        {

                        printf("Nome: %s",CA->nome);
                        printf("Matricula: %d\n\n",CA->matricula);
                        printf("Faltas: %d\n", CA->faltas);
                        printf("1 Bim: %.2f\n",*CA->nota1);
                        printf("2 Bim: %.2f\n",*CA->nota2);
                        printf("3 Bim: %.2f\n",*CA->nota3);
                        printf("4 Bim: %.2f\n",*CA->nota4);
                        printf("\n-----------------\n");
                        }
                    }
            }
fclose(arquivo);
printf("\n FIM DA LISTA \n");
    }
}

