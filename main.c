#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "services/add-user.service.h"
#include "services/delete-user.service.h"
#include "services/get-position-user.service.h"
#include "services/get-queue-size.service.h"
#include "services/leave-queue.service.h"

#include "types/user.type.h"

int main()
{
  int choice;

  do
  {
    system("cls");
    printf("\n\n-------------------------");
    printf("\n> > > CAIXA NÂO TEM < < <\n");
    printf("-------------------------\n\n");

    printf("1 - Chegada de cliente \n");
    printf("2 - Chamada de Cliente \n");
    printf("3 - Saida da fila \n");
    printf("4 - Consulta posição\n");
    printf("5 - Tamanho da fila \n");
    printf("6 - Sair \n\n");
    scanf(" %d", &choice);

    switch (choice)
    {
    case 1:
      addUserService();
      break;
    case 2:
      deleteUserService();
      break;
    case 3:
      leaveQueueService();
      break;
    case 4:
      getPositionUserService();
      break;
    case 5:
      getQueueSizeService();
      break;
    }

  } while (choice != 6);

  return 0;
}