#include <stdio.h>

int main()
{
  int n, soma;

  printf("informe um numero:\n");
  scanf("%d", &n);
  soma = 0;
  for (int i = 0; i <= n; i++)
  {
    soma += i;
  }
  printf("%d\n", soma);
  return 0;
}
