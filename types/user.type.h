
typedef char NameType[50];
typedef char CpfType[11];

typedef struct
{
  NameType name;
  CpfType cpf;

  void *next;
} UserType;