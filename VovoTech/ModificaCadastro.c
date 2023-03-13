#include "main.h"
//Modificar cadastro
typedef struct{
    char usuario[50];
    int senha;
    int nivelacesso;
}Cadastro;
void ModificaCadastro(){
    system("cls");
     FILE *file;
    file = fopen("cadastros.dat", "rb+");
    Cadastro c;
    int id, i = 1;

    if(file){
        printf("Lista de Cadastros:\n");
        printf("----------------------------\n");
        while(fread(&c, sizeof(Cadastro), 1, file)){
            printf("[%d]\nUsuario: %s\nSenha: %d\nNivel de acesso: %d\n-----------------\n", i, c.usuario, c.senha, c.nivelacesso);
            i++;

        }
        printf("\n");
        printf("\n\tDigite o indice do cadastro que deseja alterar:\n\n");
        scanf("%d", &id);
        getchar();
        id--;

        if(id >= 0 && id < i - 1){
            printf("Novo usuario: ");
            scanf("%49[^\n]", c.usuario);
            printf("Nova senha: ");
            scanf("%d", &c.senha);
            printf("Novo nivel de acesso: ");
             scanf("%d", &c.nivelacesso);
            fseek(file, id * sizeof(Cadastro), SEEK_SET);
            fwrite(&c, sizeof(Cadastro), 1, file);
            printf("Usuario atualizado com sucesso\n");
        }
        fclose(file);
    }
    else{
        printf("\nErro ao abrir arquivo!\n");}

        system("pause");
        MenuDiretor();
}

