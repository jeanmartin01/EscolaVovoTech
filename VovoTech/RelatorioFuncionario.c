#include "main.h"
#define MAX_FUNC 200
void MenuDiretor();
typedef struct
{
    char  nome[40];
    char  celular[40];
    char  email[540];
    char  setor[20];
    int  salario;
    int IDfunc;

}CadFuncionario;



void RelatorioFuncionario(){
int i;
CadFuncionario cf;
FILE *f;
int x, totalsalario, totalanual;
totalsalario = 0;
x = 0;
f = fopen("cadfunc.dat", "a+b");
if (f == NULL){
    printf("\nErro na abertura do arquivo.\n");
}
else {
        system("cls");
    printf("\n*** RELATORIO DE FUNCIONARIOS ***\n");
    while (!feof(f)){
     i =   fread(&cf, sizeof(CadFuncionario), 1, f);
        if (ferror(f)){
            printf("Erro na leitura do arquivo");}
        else{

if (i != 0)

            {

            x++;
            totalsalario = totalsalario + cf.salario;


      }
     }
    }
     totalanual = totalsalario * 12;
     printf("Total Funcionarios: %d\n", x);
     printf("Total Salario mensal: R$%d\n", totalsalario);
     printf("Total Salario anual: R$%d\n\n", totalanual);


    system ("pause");
    MenuDiretor();
}
}
