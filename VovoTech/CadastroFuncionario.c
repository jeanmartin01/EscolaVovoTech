#include "main.h"

void MenuDiretor();
void excluirF();
typedef struct
{
    char  nome[40];
    char  celular[40];
    char  email[540];
    char  setor[20];
    int  salario;
    int  IDfunc;

}CadFuncionario;



void CadastroFuncionario(){

void menu();
void cadastrarF();
void listarF();
void alterarF();
void pesquisarF();
void removerF();




system ("cls");
    int op;
    do
    {
        system ("cls");
        printf("\n1-Cadastrar Funcionario");
        printf("\n2-Listar Funcionario");
        printf("\n3-Alterar Funcionario");
        printf("\n4-Excluir Funcionario");
        printf("\n5-Menu anterior");
        printf("\n6-Fechar Programa\n\n");
        printf("Escolha a opcao desejada: ");
        scanf("%d", &op);
        getchar();
        switch(op)
        {
            case 1:
                cadastrarF();
                break;
            case 2:
                listarF();
                break;
            case 3:
                alterarF();
                break;
            case 4:
                excluirF();
            case 5:
                MenuDiretor();
            break;
            case 6:
               printf("OBRIGADO POR UTILIZAR NOSSO SISTEMA :)");
               exit(0);
            break;
            default:
                printf("OPCAO INVALIDA - TENTE NOVAMENTE\n");
                system("pause");
                fflush(stdin);
                CadastroFuncionario();

        }
        getchar();
}
while(op!=0);
}

void cadastrarF(){
    system ("cls");
CadFuncionario cf;
FILE *f;
f = fopen("cadfunc.dat", "ab");
if (f == NULL){
    printf("\nErro na abertura do arquivo");
    } else {

   printf("--------------------------\n");
   printf(" CADASTRO DO FUNCIONARIO\n");
   printf("--------------------------\n");


    printf("\nNome do funcionario: ");
    scanf("%49[^\n]", cf.nome);
    getchar();
    fflush(stdin);
    printf("\nCelular do funcionario: ");
    scanf("%49[^\n]", cf.celular);
    getchar();
    fflush(stdin);
    printf("\nEmail do funcionario: ");
    scanf("%49[^\n]", cf.email);
    getchar();
    fflush(stdin);
    printf("\nSetor do funcionario: ");
    scanf("%49[^\n]", cf.setor);
    getchar();
    fflush(stdin);
    printf("\nSalario do funcionario: ");
    scanf("%d", &cf.salario);
    getchar();
    fflush(stdin);
    printf("\nID do funcionario: ");
    scanf("%d", &cf.IDfunc);
     getchar();

    fwrite(&cf, sizeof(CadFuncionario), 1, f);
    if (ferror(f)){
        printf("\nErro na gravacao\n ");
        } else {

        printf("\n\n FUNCIONARIO CADASTRADO COM SUCESSO !!!\n");
        getchar();

        }
        fclose(f);
    }
return CadastroFuncionario();
}

void listarF (){
system("cls");
    CadFuncionario cf;
    int i = 0;
    FILE *file;
    file = fopen("cadfunc.dat", "rb");

    if(file){
        while(!feof(file)){
            if(fread(&cf, sizeof(CadFuncionario), 1, file))
printf("\nUsuario: %s\nSenha: %s\nNivel de acesso: %s\nSetor: %s\nSalario: %d\nID: %d\n------------------------------------",cf.nome,cf.celular,cf.email,cf.setor,cf.salario,cf.IDfunc);
                i++;

        }
        printf("\nTotal de Funcionarios: %d\n", i - 1);
        printf("------------------------------------");
        fclose(file);
    }


    else{
        printf("\nErro ao abrir arquivo!\n");}
        printf("\n");
        system ("pause");
}

void alterarF(){
system("cls");
     FILE *file;
    file = fopen("cadfunc.dat", "rb+");
    CadFuncionario cf;
    int id, i = 1;

    if(file){
        printf("Lista de funcionarios:\n");
        printf("----------------------------\n");
        while(fread(&cf, sizeof(CadFuncionario), 1, file)){
            printf("[%d]\nNome: %s\nCelular: %s\nEmail: %s\nSetor: %s\nSalario: %d\nID: %d\n-----------------\n", i, cf.nome, cf.celular, cf.email, cf.setor, cf.salario, cf.IDfunc);
            i++;

        }
        printf("\n");
        printf("\nDigite o indice do funcionario que deseja alterar:\n\n");
        scanf("%d", &id);
        getchar();
        id--;
        if(id >= 0 && id < i - 1){
            printf("Novo nome: ");
            scanf("%49[^\n]", cf.nome);
            fflush(stdin);

             printf("Novo celular: ");
            scanf("%49[^\n]", cf.celular);
             fflush(stdin);

             printf("Novo email: ");
            scanf("%49[^\n]", cf.email);
             fflush(stdin);

             printf("Novo setor: ");
            scanf("%49[^\n]", cf.setor);
             fflush(stdin);

            printf("Novo salario: ");
            scanf("%d", &cf.salario);
             fflush(stdin);

            printf("Novo ID: ");
             scanf("%d", &cf.IDfunc);
              fflush(stdin);

            fseek(file, id * sizeof(CadFuncionario), SEEK_SET);
            fwrite(&cf, sizeof(CadFuncionario), 1, file);
            printf("Funcionario atualizado com sucesso\n");
        }
        fclose(file);
    }
    else{
        printf("\nErro ao abrir arquivo!\n");}

        system("pause");
        CadastroFuncionario();
}

void excluirF(){

CadFuncionario cf;
FILE *file;
FILE *temp;
    file = fopen("cadfunc.dat", "rb");
    temp = fopen("temp.dat", "wb");
    if (file == NULL){printf("\nErro na abertura do arquivo.\n");}
    else{

    int IDfuncionario;
    listarF();
    printf("\nDigite o ID do funcionario a ser removido: ");
    scanf("%d", &IDfuncionario);


        while(fread(&cf, sizeof(CadFuncionario),1, file)==1)
            {
            if (IDfuncionario!=cf.IDfunc)
            {fwrite(&cf, sizeof(CadFuncionario),1, temp);
            }}}

            if(ferror(temp)){printf("\nErro ao remover\n");}
            else{printf("\nFuncionario removido com sucesso!\n\n");}

fclose(file);
fclose(temp);
remove ("cadfunc.dat");
rename ("temp.dat","cadfunc.dat");
system ("pause");
CadastroFuncionario();



}

