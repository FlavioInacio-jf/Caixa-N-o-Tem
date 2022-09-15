#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char NameType[50];
typedef char CpfType[11];

typedef struct
{
  NameType name;
  CpfType cpf;

  void *next;
} UserType;

void deleteUserService(UserType **start, UserType **end);
void addUserService(UserType **start, UserType **end);
void getPositionUserService(UserType **start, UserType **end);
void getQueueSizeService(UserType **start, UserType **end);
void leaveQueueService(UserType **start, UserType **end);

int main(void)
{
  UserType *start = NULL, *end = NULL;
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
      addUserService(&start, &end);
      break;
    case 2:
      deleteUserService(&start, &end);
      break;
    case 3:
      leaveQueueService(&start, &end);
      break;
    case 4:
      getPositionUserService(&start, &end);
      break;
    case 5:
      getQueueSizeService(&start, &end);
      break;
    }

  } while (choice != 6);
  return 0;
}

void addUserService(UserType **start, UserType **end)
{
  UserType *aux = NULL;

  NameType name;
  CpfType cpf;

  system("cls");
  printf("*** Chegada de usuario ***\n\n");
  printf("Nome do usuario: ");
  scanf(" %s", name);

  printf("CPF do usuario: ");
  scanf(" %s", cpf);

  aux = (UserType *)malloc(sizeof(UserType));
  aux->next = NULL;

  strcpy(aux->name, name);
  strcpy(aux->cpf, cpf);

  if (*start == NULL)
  {
    *start = aux;
    *end = aux;
  }
  else
  {
    (*start)->next = aux;
    *end = aux;
  }

  system("pause");
  system("cls");
  return;
}

void deleteUserService(UserType **start, UserType **end)
{
  return;
}

void getPositionUserService(UserType **start, UserType **end)
{

  return;
}

void getQueueSizeService(UserType **start, UserType **end)
{
  return;
}

void leaveQueueService(UserType **start, UserType **end)
{
  return;
}