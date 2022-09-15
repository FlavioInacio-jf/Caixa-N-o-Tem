#include <stdio.h>
#include <stdlib.h>

#include "../types/user.type.h"

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
  aux -> next = NULL;

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