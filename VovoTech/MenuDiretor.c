#include "main.h"
//Menu de diretor

void CadastroUsuario();
void CadastroFuncionario();
void ListarUsuarios();
void ModificaCadastro();
void RelatorioFinanceiro();
void RelatorioFuncionario();
void login();


void MenuDiretor(){
    int op;

 system("cls");
printf("  ESCOLA VOVOTECH");
printf("  \nBem vindo, Diretor(a)!\n");
printf("--------------------------\n");
printf("1-Cadastrar novo usuario\n");
printf("2-Administrar Funcionarios\n");
printf("3-Listar usuarios\n");
printf("4-Modificar Cadastros\n");
printf("5-Relatorio Funcionario\n");
printf("6-Relatorio Financeiro\n");
printf("7-Log-Off\n");
printf("8-Fechar Programa\n");
printf("\n\nDigite um opcao: ");
scanf("%d", &op);

 switch (op)
  {
    case 1 :
    CadastroUsuario();
    break;
    case 2 :
    CadastroFuncionario();
    break;
    case 3:
    ListarUsuarios();
    break;
    case 4:
    ModificaCadastro();
    break;
    case 5:
    RelatorioFuncionario();
    break;

    case 6:
    RelatorioFinanceiro();
    break;

    case 7:
        login();
        break;

    case 8:
        printf("OBRIGADO POR UTILIZAR NOSSO SISTEMA :)\n");
        system("pause");
        exit(0);
    break;

    default:
     printf("Opcao invalida - tente novamente\n");

     system("pause");
     fflush(stdin);
     MenuDiretor();




}

}




