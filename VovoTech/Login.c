#include "main.h"


//Módulo Login


typedef struct{
    char usuario[50];
    int senha;
    int nivelacesso;
}cadastro;


int login(){
    system("cls");
    cadastro c;
    int logado = 5;
    char user[50];
    int passw;
    FILE *file;
    file = fopen("cadastros.dat", "rb");
    printf("-------------------------\n");
    printf("Entre com usuario e senha\n");
    printf("-------------------------\n");

    printf("Usuario: ");
    scanf("%s", user);
    getchar();
    printf("Senha: ");
    scanf("%d", &passw);
    getchar();
    if(file){
        while(!feof(file)){
            if(fread(&c, sizeof(cadastro), 1, file)){
                if((strcmp(user,c.usuario)==0)&& (passw == c.senha)){

                    printf("---------------------\n");
                    printf("LOGIN BEM SUCEDIDO\n");
                    printf("---------------------\n");
                    printf("SEJA BEM VINDO \n");
                    printf("---------------------\n");

                    logado = c.nivelacesso;

                    switch(logado) {
                case 1:
                    printf("CARREGANDO...\n");
                    printf("---------------------\n");
                    Sleep(2000);
                    MenuDiretor();
                    break;

                case 2:
                    printf("CARREGANDO...\n");
                    printf("---------------------\n");
                    Sleep(2000);
                    CadastroAlunos();

                case 3:
                    printf("CARREGANDO...\n");
                    printf("---------------------\n");
                    Sleep(2000);
                    ModuloFinanceiro();

                case 4:
                    printf("CARREGANDO...\n");
                    printf("---------------------\n");
                    Sleep(2000);
                    ModuloProfessor();
                    }


                     }
                     }else
                     if((strcmp(user,c.usuario)!=0)||(passw != c.senha)){

                        printf("Login incorreto - TENTE NOVAMENTE\n");
                        system("pause");
                        login();

                                                   }
}
        fclose(file);
    }
else{
        printf("\nErro ao abrir arquivo!\n");
    }

return 0;



}


