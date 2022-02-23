#include <stdio.h>

int main()
{
  int n, soma;

  printf("informe um numero:\n");
  scanf("%d", &n);
  soma = 0;
  for (int i = 0; i <= n; i++)
  {
    if (i % 3 == 0 && i % 5 == 0)
    {
      printf("%d\t", i);
      soma += i;
    }
  }
  printf("\n%d\n", soma);
  return 0;
}