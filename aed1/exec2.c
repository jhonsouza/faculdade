#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main()
{

  char nome[50];

  printf("informe seu nome:\t");
  scanf("%s", nome);
  int len = strlen(nome);
  char *result = calloc(len + 1, sizeof(char));
  for (size_t i = 0; i < len; i++)
  {
    result[i] = tolower(nome[i]);
  }
  if (strcmp(result, "joao") == 0 || strcmp(result, "ana") == 0)
  {
    printf("Ola %s, como você está?\n", nome);
  }
  else
  {
    printf("ola %s\n", nome);
  }
  return 0;
}