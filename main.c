#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char NameType[50];
typedef char CpfType[11];

typedef struct
{
  NameType name;
  CpfType cpf;

  void *next;
} UserType;

void menu();
void getPositionUser(UserType **start, UserType **end);
void getQueueSize(UserType **start, UserType **end);
void deleteUser(UserType **start, UserType **end);
void leaveQueue(UserType **start, UserType **end);
void addUser(UserType **start, UserType **end);

int main()
{
  menu();

  return 0;
}

void menu()
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
      addUser(&start, &end);
      break;
    case 2:
      deleteUser(&start, &end);
      break;
    case 3:
      leaveQueue(&start, &end);
      break;
    case 4:
      getPositionUser(&start, &end);
      break;
    case 5:
      getQueueSize(&start, &end);
      break;
    }

  } while (choice != 6);
  return;
}

void addUser(UserType **start, UserType **end)
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
    (*end)->next = aux;
    *end = aux;
  }

  system("pause");
  system("cls");
  return;
}

void deleteUser(UserType **start, UserType **end)
{
  UserType *aux;

  system("cls");
  printf("*** Chamada de usuario ***\n\n");

  if (*start != NULL)
  {
    printf("Usuário '%s' chamado", (*start)->name);

    aux = *start;
    *start = (*start)->next;

    free(aux);
    aux = NULL;
  }
  else
    printf("*** Não existem pessoas na fila ***");

  system("pause");
  system("cls");
  return;
}

void getPositionUser(UserType **start, UserType **end)
{
  UserType *aux;
  CpfType cpf;

  unsigned int userPosition = 0;
  bool foundUser = false;

  system("cls");
  printf("*** Posicao do usuário na fila ***\n\n");

  if (*start != NULL)
  {
    printf("CPF do usuario: ");
    scanf(" %s", cpf);

    aux = *start;

    while (aux != NULL && !foundUser)
    {
      if (strcmp(aux->cpf, cpf) == 0)
        foundUser = true;

      aux = aux->next;

      if (aux != NULL)
        userPosition++;
    }

    if (foundUser)
      printf("*** Posicao do usuário informado eh: %d", userPosition);
    else
      printf("*** Usuário não está na fila ***");
  }
  else
  {
    printf("*** Não existem pessoas na fila ***");
  }

  system("pause");
  system("cls");
  return;
}

void getQueueSize(UserType **start, UserType **end)
{

  system("pause");
  system("cls");
  return;
}

void leaveQueue(UserType **start, UserType **end)
{
  UserType *previous, *aux;
  CpfType cpf;

  bool foundUser = false;

  system("cls");
  printf("*** Abandano da fila ***\n\n");
  printf("CPF do usuario: ");
  scanf(" %s", cpf);

  aux = *start;
  previous = NULL;

  while (aux != NULL && !foundUser)
  {
    if (strcmp(aux->cpf, cpf) == 0)
    {
      foundUser = true;

      if (previous == NULL) // Posiciona o ponteiro de início para caso a variável dinâmica a ser removida for a primeira
        *start = aux->next;
      else if (aux->next == NULL) // Posiciona o ponteiro de final para caso a variável dinâmica a ser removida for a última
        *end = previous;
      else
        previous->next = aux->next;

      free(aux);
      aux = NULL;
    }
    else
    {
      previous = aux;
      aux = aux->next;
    }
  }

  if (foundUser)
    printf("*** Usuário removido da fila ***");
  else
    printf("*** Usuário não está na fila ***");

  system("pause");
  system("cls");
  return;
}