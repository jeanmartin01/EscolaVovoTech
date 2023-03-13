#include "main.h"

typedef struct{
    char usuario[50];
    int senha;
    int nivelacesso;
}Cadastro;
void ExcluiUsuario(){

        FILE *arquivo,*temporario;
    arquivo = fopen("cadastros.dat", "rb");
    temporario = fopen("temp.dat", "wb");
    Cadastro c;
     char usuario[50];
    if (arquivo == NULL)
    {
    printf("\nErro na abertura do arquivo.\n");
    }
    else
    {



    printf("\nDigite a matricula do aluno a ser removido: ");
    gets(usuario);
    getchar();

        while(fread(&c, sizeof(usuario),1, arquivo)==1)
        {
            if (usuario!=c.usuario)
            {
                fwrite(&c, sizeof(usuario),1, temporario);
            }
        }
    }

    if(ferror(temporario))
    {
        printf("\nErro ao remover\n");
    }
    else
    {
    printf("\nAluno removido com sucesso!\n\n");
    }

fclose(arquivo);
fclose(temporario);
remove ("cadastros.dat");
rename ("temp.dat","cadastros.dat");
system ("pause");
}

