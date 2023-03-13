#include "main.h"


  typedef struct Registro
  {
  int id;
  int mes;
  int valor;
  char nome[50];
  char curso[50];
  char status[50];
  }registro;

void menu();
void financeiro();
void listar();
int alterar();
void excluir ();
void relatorio();
void login();





void ModuloFinanceiro(){
 system ("cls");
    int op;
    do
     {
        system ("cls");
        printf("  ESCOLA VOVOTECH");
        printf("\nBem vindo, ao Financeiro !");
        printf("\n---------------------------------------\n");
        printf("1-Cadastro financeiro ");
        printf("\n2-Listar registros financeiros");
        printf("\n3-Modificar  em arquivo ");
        printf("\n4-Excluir");
        printf("\n5-Log-Off ");
        printf("\n6-Fechar Programa");
        printf("\n---------------------------------------\n");
        printf("Escolha a opcao desejada: ");
        scanf("%d", &op);
        getchar();
        switch(op)

          {
            case 1:
            financeiro();
                break;
            case 2:
                listar();
                break;
            case 3:
                 alterar();
                break;
            case 4:
                excluir();
                break;

            case 5:
                login();
                break;
            case 6:
                printf("OBRIGADO POR UTILIZAR NOSSO SISTEMA :)\n");
                system("pause");
                exit(0);
                break;
            default:
                printf("OPCAO INVALIDA - TENTE NOVAMENTE\n");
                system("pause");
                fflush(stdin);
                ModuloFinanceiro();
        }
        getchar();
    }
while(op!=0);
}

void financeiro (){
  system("cls");
    registro r;
    FILE *file;
    file = fopen("registros.dat", "ab");

    if(file){
        printf("Cadastre o ID do aluno: ");
        scanf("%d", &r.id);
        getchar();
        fflush(stdin);
        printf("Digite o nome: ");
        scanf("%49[^\n]", r.nome);
        getchar();
        printf("Digite o curso: ");
        scanf("%49[^\n]", r.curso);
        getchar();
        printf("Digite o status: ");
        scanf("%49[^\n]", r.status);
        getchar();
        printf("Digite o mes: ");
        scanf("%d",&r.mes);
        getchar();
        printf("Digite o valor: ");
        scanf("%d",&r.valor);
        getchar();
        fwrite(&r, sizeof(registro), 1, file);
        fclose(file);
        printf("USUARIO CADASTRADO COM SUCESSO\n");
        system("pause");
    }
    else
        printf("\nErro ao abrir arquivo!\n");




}

void listar () {
    system("cls");
    registro r;
    int i = 0;
    FILE *file;
    file = fopen("registros.dat", "rb");

    if(file){
        while(!feof(file)){
            if(fread(&r, sizeof(registro), 1, file))
            {

                printf("\nID: %d\nNome: %s\nCurso: %s\nStatus: %s\nMes: %d\nValor: %d\n------------------------------------",r.id, r.nome, r.curso, r.status, r.mes, r.valor);
            }
                i++;

        }
        printf("\nTotal de registros: %d\n", i - 1);
        printf("------------------------------------");
        fclose(file);
    }
    else{
        printf("\nErro ao abrir arquivo!\n");}
        printf("\n");



}

int alterar(){

     system("cls");
    FILE *file;
    file = fopen("registros.dat", "rb+");
    registro r;
    int id, i = 1;

    if(file){
        printf("Lista de Registros:\n");
        printf("----------------------------\n");
        while(fread(&r, sizeof(registro), 1, file)){
             printf("[%d]\nNome: %s\nCurso: %s\nStatus: %s\nMes: %d\nValor: %d\n------------------------------------\n",i, r.nome, r.curso, r.status, r.mes, r.valor);
            i++;

        }
        printf("\n");
        printf("\nDigite o indice do registro que deseja alterar:\n");
        scanf("%d", &id);
        getchar();
        id--;

        if(id >= 0 && id < i - 1){
            printf("\nNovo nome: ");
            scanf("%49[^\n]", r.nome);
             getchar();
            printf("Novo curso: ");
            scanf("%49[^\n]", r.curso);
             getchar();
            printf("Novo status: ");
            scanf("%49[^\n]", r.status);
             getchar();
            printf("Novo mes: ");
            scanf("%d", &r.mes);
             getchar();
            printf("Novo valor: ");
            scanf("%d", &r.valor);
             getchar();
            fseek(file,id *sizeof(registro),SEEK_SET);
            fwrite(&r, sizeof(registro), 1, file);
            printf("Registro atualizado com sucesso\n");
        }
        fclose(file);
    }
    else{
        printf("\nErro ao abrir arquivo!\n");}

        system("pause");

    return 0;
}

void excluir() {
registro r;

FILE *file;
FILE *temp;
    file = fopen("registros.dat", "rb");
    temp = fopen("temp.dat", "wb");
    if (file == NULL){printf("\nErro na abertura do arquivo.\n");}
    else{

    struct registro;
    int IDaluno;
    listar();
    printf("\nDigite o ID do aluno a ser removido: ");
    scanf("%d", &IDaluno);


        while(fread(&r, sizeof(registro),1, file)==1)
            {
            if (IDaluno!=r.id)
            {fwrite(&r, sizeof(registro),1, temp);
            }}}

            if(ferror(temp)){printf("\nErro ao remover\n");}
            else{printf("\nAluno removido com sucesso!\n\n");}

fclose(file);
fclose(temp);
remove ("registros.dat");
rename ("temp.dat","registros.dat");
system ("pause");
ModuloFinanceiro();

}

