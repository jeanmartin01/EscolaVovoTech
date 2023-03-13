#include "main.h"
void gotoxy(int n, int l)
{
  COORD c;
  c.X = n;
  c.Y = l;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Abertura()
{
    system ("color 6");
         printf("\n\t\t**********************************************************************************");
         printf("\n\t\t*          @@@@@@@@  @@@@@@@  @@@@@@@  @@@@@@@@  @@        @@@@@@@@              *");
         printf("\n\t\t*          @@        @@       @@       @@    @@  @@        @@    @@              *");
         printf("\n\t\t*          @@@@@     @@@@@@@  @@       @@    @@  @@        @@    @@              *");
         printf("\n\t\t*          @@             @@  @@       @@    @@  @@        @@@@@@@@              *");
         printf("\n\t\t*          @@@@@@@@  @@@@@@@  @@@@@@@  @@@@@@@@  @@@@@@@@  @@    @@              *");
         printf("\n\t\t*                                                                                *");
         printf("\n\t\t*  @@      @@  @@@@@  @@      @@  @@@@@     @@@@@@@@ @@@@@@@ @@@@@@@ @@   @@     *");
         printf("\n\t\t*   @@    @@  @@   @@  @@    @@  @@   @@       @@    @@      @@      @@   @@     *");
         printf("\n\t\t*    @@  @@   @@   @@   @@  @@   @@   @@       @@    @@@@@   @@      @@@@@@@     *");
         printf("\n\t\t*     @@@@    @@   @@    @@@@    @@   @@       @@    @@      @@      @@   @@     *");
         printf("\n\t\t*      @@      @@@@@      @@      @@@@@        @@    @@@@@@@ @@@@@@@ @@   @@     *");
         printf("\n\t\t**********************************************************************************");
         printf("\t\n");
      printf("\n\t\t                            SISTEMA DE GESTAO ESCOLAR");
      printf("\n\n\n\n ");
      printf("\n\t\t                        PRESSIONE TECLA ENTER PARA CONTINUAR ...");
      getchar();




      login();

}
