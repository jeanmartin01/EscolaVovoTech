#include "main.h"
#define MAX_ALUNOS 50

void menu();
void cadastrarA();
void listarA();
void alterarA();
void relatorioA();
void removerA();
void excluirA();
void excluirC();
void login();
void pesquisarA();
void CadastroCurso();
void ListarParaExcluir();
typedef struct
{
    char  nome[40];
    char  email[40];
    char  celular[20];
    int   idade;
    int   IDaluno;
    int   aluno_A;
} ACAD;


ACAD AC [MAX_ALUNOS];


void CadastroAlunos(){
   int op;

        system ("cls");
        printf("\n ESCOLA VOVOTECH");
        printf("\n------------------------");
        printf("\n*** SECRETARIA ***");
        printf("\n------------------------");
        printf("\n1- Cadastrar ALUNOS");
        printf("\n2- Listar ALUNOS");
        printf("\n3- Alterar ALUNOS");
        printf("\n4- Remover ALUNOS");
        printf("\n5- Pesquisar ALUNO");
        printf("\n6- Administrar Cursos");
        printf("\n7- Log-Off");
        printf("\n8- Fechar Programa\n");
        printf("Escolha a opcao desejada: ");
        scanf("%d", &op);
        getchar();
        switch(op)
        {
        case 1:
            cadastrarA();
            break;
        case 2:
            listarA();
            break;
        case 3:
            alterarA();
            break;
        case 4:
            excluirA();
            break;
        case 5:
            pesquisarA();
            break;
        case 6:
            CadastroCurso();
            break;
        case 7:
            login();
            break;
        case 8:
            printf("OBRIGADO POR UTILIZAR NOSSO SISTEMA :)\n");
            system("pause");
            exit(0);
        default:
            printf("OPCAO INVALIDA - TENTE NOVAMENTE\n");
            system("pause");
            fflush(stdin);
            CadastroAlunos();

getchar();
    }
}

void cadastrarA(){
    system("cls");
    int op;
    struct AC;
    FILE *a;
    a = fopen("alunoinfo.dat", "ab");
    if (a == NULL){printf("\nErro na abertura do arquivo");}
    else
    {
        printf("\t--------------------------\n");
        printf("\t CADASTRO DE ALUNOS \n");
        printf("\t--------------------------\n\n");


        printf("Nome: ");
        fgets(AC->nome,40,stdin);
        printf("Idade: ");
        scanf("%d",&AC->idade);
        fflush(stdin);
        printf("Celular: ");
        fgets(AC->celular,20,stdin);
        printf("Email: ");
        fgets(AC->email,40,stdin);
        printf("ID-Aluno: ");
        scanf("%d",&AC->IDaluno);
        fflush(stdin);
        AC->aluno_A=1;
        fwrite(&AC, sizeof(ACAD), 1, a);
        fclose(a);
        printf("\n\n ALUNO CADASTRADO COM SUCESSO !!!\n");

        printf("\n\n1- Novo cadastro");
        printf("\n0- Voltar ao menu\n");
        printf("Escolha a opcao desejada: ");
        scanf("%d", &op);
        getchar();

        if (ferror(a)){printf("\nErro na gravacao\n ");}
        else{printf("\nErro ao abrir o arquivo");}
        switch(op){
            case 1:
            cadastrarA();
            break;
            case 0:
            CadastroAlunos();
            break;}}}

void listarA (){

int i;
FILE *a;
a = fopen("alunoinfo.dat", "a+b");
    if (a == NULL)
    {printf("\nErro na abertura do arquivo.\n");}
    else
    {
        system("cls");
        printf("\nLISTA DE ALUNOS\n");
        while (!feof(a))
            {i=fread(&AC, sizeof(ACAD), 1, a);
            if (ferror(a)){printf("Erro na leitura do arquivo");}
            else{
                if (i != 0){
                        printf("-----------------\n");
                        printf("Nome: %s",AC->nome);
                        printf("Idade: %d\n",AC->idade);
                        printf("Celular: %s",AC->celular);
                        printf("Email: %s",AC->email);
                        printf("ID-Aluno: %d",AC->IDaluno);
                        printf("\n-----------------\n");
                        }}}fclose(a);

                    printf("\nFIM DA LISTA \n");}
                    system("pause");
                    CadastroAlunos();

                    }

void alterarA(){
    struct AC;
    system("cls");
    FILE *a;
    a = fopen("alunoinfo.dat", "rb+");
    int id, i = 1;
    if(a)
        {printf("Lista de Cadastros:\n");
        while(fread(&AC, sizeof(ACAD), 1, a)){

            printf("-----------------------\n");
            printf("[%d]\n",i);
            printf("Nome: %s",AC->nome);
            printf("Idade: %d\n",AC->idade);
            printf("Celular: %s",AC->celular);
            printf("Email: %s",AC->email);
            printf("ID-Aluno: %d\n",AC->IDaluno);
            printf("-----------------------\n");
            i++;
        }
        printf("\n");
        printf("\nDigite o indice do cadastro que deseja alterar:\n");
        scanf("%d", &id);
        getchar();
        id--;

        if(id >= 0 && id < i - 1)
        {
            printf("\nNovo nome: ");
            fgets(AC->nome, 40 , stdin);
            printf("Alterar Idade: ");
            scanf("%d", &AC->idade);
            fflush(stdin);
            printf("Novo celular: ");
            fgets(AC->celular,20,stdin);
            printf("Novo email: ");
            fgets(AC->email, 40,stdin);
            printf("Novo ID Aluno: ");
            scanf("%d", &AC->IDaluno);
            fflush(stdin);
            fseek(a, id * sizeof(ACAD), SEEK_SET);
            fwrite(&AC, sizeof(ACAD), 1, a);
            printf("Usuario atualizado com sucesso\n");

        }fclose(a);}
    else
        {printf("\nErro ao abrir arquivo!\n");}
        system("pause");
        CadastroAlunos();

}

void excluirA (){
FILE *a;
FILE *temp;
    a = fopen("alunoinfo.dat", "rb");
    temp = fopen("temp.dat", "wb");
    if (a == NULL){printf("\nErro na abertura do arquivo.\n");}
    else{

    struct AC;
    int IDaluno;
    ListarParaExcluir();
    printf("\nDigite o ID do aluno a ser removido: ");
    scanf("%d", &IDaluno);
    getchar();

        while(fread(&AC, sizeof(ACAD),1, a)==1)
            {

            if (IDaluno!=AC->IDaluno)
            {fwrite(&AC, sizeof(ACAD),1, temp);
            }}}

            if(ferror(temp)){printf("\nErro ao remover\n");}
            else{printf("\nAluno removido com sucesso!\n\n");}

fclose(a);
fclose(temp);
remove ("alunoinfo.dat");
rename ("temp.dat","alunoinfo.dat");
system ("pause");
CadastroAlunos();
}

void pesquisarA(){
 FILE *a;
    a = fopen("alunoinfo.dat", "rb+");
    if (a == NULL)
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
            ACAD AC;
while(1)
{
        size_t result = fread(&AC, sizeof(ACAD),1, a);
        if(result==0)
        break;
        char noomeaux[MAX_ALUNOS];
        strcpy (noomeaux,AC.nome);

        if(strstr(noomeaux,noome)!=NULL)
        {
                printf("\n-----------------\n");
                printf("Nome: %s",AC.nome);
                printf("Idade: %d\n",AC.idade);
                printf("Celular: %s",AC.celular);
                printf("Email: %s",AC.email);
                printf("ID-Aluno: %d\n",AC.IDaluno);
                printf("\n-----------------\n\n");

        }

}
fclose(a);


	fseek(stdin, 0, SEEK_END);


        printf("\n\n1- Nova pesquisa");
        printf("\n0- Voltar ao menu\n");
        printf("\nEscolha a opcao desejada: ");
        scanf("%d", &op);
        getchar();
                switch(op)
        {
            case 1:
                pesquisarA();
            break;
            case 0:
              CadastroAlunos();
            break;
            default:
            fflush(stdin);
            CadastroAlunos();

        }}}

void menu();
void cadastrarC();
void listarC();
void alterarC();
void excluirC();

typedef struct
{
    char  nomec[40];
    int   valor;
    int   IDcurso;
    int   curso_A;
} CURSO;
CURSO CC;

void CadastroCurso(){
   int op;
    do{
        system ("cls");
        printf("\n ESCOLA VOVOTECH");
        printf("\n------------------------");
        printf("\n*** SECRETARIA ***");
        printf("\n------------------------");
        printf("\n1- Cadastrar CURSO");
        printf("\n2- Listar CURSO");
        printf("\n3- Alterar CURSO");
        printf("\n4- Remover CURSO");
        printf("\n5- Menu Anterior\n");
        printf("Escolha a opcao desejada:  ");
        scanf("%d", &op);
        getchar();
        switch(op)
        {
        case 1:
            cadastrarC();
            break;
        case 2:
            listarC();
            break;
        case 3:
            alterarC();
            break;
        case 4:
            excluirC();
            break;
        case 5:
            CadastroAlunos();
            break;
        default:
            printf("OPCAO INVALIDA - TENTE NOVAMENTE\n");
            system("pause");
            fflush(stdin);
            CadastroCurso();
       }
getchar();
    }
    while(op!=0);
}

void cadastrarC(){
    system("cls");
    struct CC;
    FILE *c;
    c = fopen("cadcurso.dat", "ab");
    if (c == NULL){printf("\nErro na abertura do arquivo");}
    else
    {
        printf("\t--------------------------\n");
        printf("\t CADASTRO DE CURSO \n");
        printf("\t--------------------------\n\n");


        printf("Nome do curso: ");
        fgets(CC.nomec,40,stdin);
        printf("Valor do curso: ");
        scanf("%d",&CC.valor);
        fflush(stdin);
        printf("ID-Curso: ");
        scanf("%d",&CC.IDcurso);
        fflush(stdin);
        CC.curso_A=1;
        fwrite(&CC, sizeof(CURSO), 1, c);
        fclose(c);
        printf("\n\n CURSO CADASTRADO COM SUCESSO !!!\n");

return CadastroCurso();
    }}

void listarC (){
int i;
FILE *c;
c = fopen("cadcurso.dat", "a+b");
    if (c == NULL)
    {printf("\nErro na abertura do arquivo.\n");}
    else
    {
        system("cls");
        printf("\nLISTA DE CURSOS\n");
        while (!feof(c))
            {i=fread(&CC, sizeof(CURSO), 1, c);
            if (ferror(c)){printf("Erro na leitura do arquivo");}
            else{
                if (i != 0){
                        printf("-----------------\n");
                        printf("Nome: %s",CC.nomec);
                        printf("Valor: %d\n",CC.valor);
                        printf("ID-Curso: %d",CC.IDcurso);
                        printf("\n-----------------\n");
                        }}}fclose(c);

                    printf("\nFIM DA LISTA \n");}}

void alterarC(){
    struct CC;
    system("cls");
    FILE *c;
    c = fopen("cadcurso.dat", "rb+");
    int id, i = 1;
    if(c)
        {printf("Lista de Cadastros:\n");
        while(fread(&CC, sizeof(CURSO), 1, c)){

            printf("-----------------------\n");
            printf("[%d]\n",i);
            printf("Nome: %s",CC.nomec);
            printf("Valor: %d\n",CC.valor);
            printf("ID-Curso: %d\n",CC.IDcurso);
            printf("-----------------------\n");
            i++;
        }
        printf("\n");
        printf("\nDigite o indice do cadastro que deseja alterar:\n");
        scanf("%d", &id);
        getchar();
        id--;

        if(id >= 0 && id < i - 1)
        {
            printf("Novo nome: ");
            fgets(CC.nomec, 40 , stdin);
            printf("Alterar Valor: ");
            scanf("%d", &CC.valor);
            printf("Novo ID Curso: ");
            scanf("%d", &CC.IDcurso);
            fseek(c, id * sizeof(CURSO), SEEK_SET);
            fwrite(&CC, sizeof(CURSO), 1, c);
            printf("Curso atualizado com sucesso\n");

        }fclose(c);}
    else
        {printf("\nErro ao abrir arquivo!\n");}
        system("pause");

return CadastroCurso();}

void excluirC (){
FILE *c;
FILE *temp;
    c = fopen("cadcurso.dat", "rb");
    temp = fopen("temp.dat", "wb");
    if (c == NULL){printf("\nErro na abertura do arquivo.\n");}
    else{

    struct CC;
    int IDaluno;
    listarC();
    printf("\nDigite o ID do curso a ser removido: ");
    scanf("%d", &IDaluno);
    getchar();

        while(fread(&CC, sizeof(CURSO),1, c)==1)
            {
            if (IDaluno!=CC.IDcurso)
            {fwrite(&CC, sizeof(CURSO),1, temp);
            }}}

            if(ferror(temp)){printf("\nErro ao remover\n");}
            else{printf("\nAluno removido com sucesso!\n\n");}

fclose(c);
fclose(temp);
remove ("cadcurso.dat");
rename ("temp.dat","cadcurso.dat");
system ("pause");}

void ListarParaExcluir (){
int i;
FILE *a;
a = fopen("alunoinfo.dat", "a+b");
    if (a == NULL)
    {printf("\nErro na abertura do arquivo.\n");}
    else
    {
        system("cls");
        printf("\nLISTA DE ALUNOS\n");
        while (!feof(a))
            {i=fread(&AC, sizeof(ACAD), 1, a);
            if (ferror(a)){printf("Erro na leitura do arquivo");}
            else{
                if (i != 0){
                        printf("-----------------\n");
                        printf("Nome: %s",AC->nome);
                        printf("Idade: %d\n",AC->idade);
                        printf("Celular: %s",AC->celular);
                        printf("Email: %s",AC->email);
                        printf("ID-Aluno: %d",AC->IDaluno);
                        printf("\n-----------------\n");
                        }}}fclose(a);

                    printf("\nFIM DA LISTA \n");}
                    fflush(stdin);


                    }
