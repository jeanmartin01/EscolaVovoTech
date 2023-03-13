#include "main.h"
void MenuDiretor();
//Cadastrar usuario
typedef struct{
    char login[50];
    int senha;
    int nivelacesso;
}Cadastro;

int CadastroUsuario(){
    char teste[30] = "teste";
    system("cls");
    Cadastro c;
    FILE *file;
    file = fopen("cadastros.dat", "ab");

    if(file){
            gets(teste);
        printf("Digite o usuario a ser cadastrado: ");
        scanf("%49[^\n]", c.login);
        printf("Digite a senha: ");
        scanf("%d",&c.senha);
        printf("[1-DIRETOR] [2-ADMINISTRATIVO] [3-FINANCEIRO] [4-PROFESSOR]\n");
        printf("Digite o nivel de acesso: ");
        scanf("%d",&c.nivelacesso);
        getchar();
        fwrite(&c, sizeof(Cadastro), 1, file);
        fclose(file);
        printf("USUARIO CADASTRADO COM SUCESSO\n");
        system("pause");
        MenuDiretor();
    }
    else
        printf("\nErro ao abrir arquivo!\n");

return 0;



}

