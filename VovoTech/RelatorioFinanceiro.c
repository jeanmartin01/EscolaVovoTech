#include "main.h"
int MenuDiretor();
typedef struct Registro
  {
  int id;
  int mes;
  int valor;
  char nome[50];
  char curso[50];
  char status[50];
  }Registro;


void RelatorioFinanceiro(){

int i ;
FILE *f;
int x, valortotal, totalanual;
valortotal = 0;
Registro r;
x = 0;
f = fopen("registros.dat", "r+b");
if (f == NULL){
    printf("\nErro na abertura do arquivo.\n");
}
else {
        system("cls");
    printf("\n*** RELATORIO FINANCEIRO ***\n");
    while (!feof(f)){
     i =   fread(&r, sizeof(Registro), 1, f);
        if (ferror(f)){
            printf("Erro na leitura do arquivo");}
        else{

if (i != 0)

            {

            x++;
            valortotal = valortotal + r.valor;


      }
     }
    }
     totalanual = valortotal * 12;
     printf("Total Registros: %d\n", x);
     printf("Total de receita mensal: R$%d\n", valortotal);
     printf("Total de receita anual: R$%d\n", totalanual);


    system ("pause");
    MenuDiretor();

}
}

