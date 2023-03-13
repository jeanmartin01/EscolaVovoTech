#include "main.h"

//Listar Cadastros
typedef struct{
    char usuario[50];
    int senha;
    int nivelacesso;
}cadastro;

void ListarUsuarios(){
    system("cls");
    cadastro c;
    int i = 0;
    FILE *file;
    file = fopen("cadastros.dat", "rb");

    if(file){
        while(!feof(file)){
            if(fread(&c, sizeof(cadastro), 1, file))
                printf("\nUsuario: %s\nSenha: %d\nNivel de acesso: %d\n------------------------------------", c.usuario, c.senha, c.nivelacesso);
                i++;

        }
        printf("\nTotal de Usuarios: %d\n", i - 1);
        printf("------------------------------------");
        fclose(file);
    }
    else{
        printf("\nErro ao abrir arquivo!\n");}
        printf("\n");
        system ("pause");
        MenuDiretor();

}

