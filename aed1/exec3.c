#include <stdio.h>
#include <stdlib.h>

int main()
{
  int matriz[12][12], i, j;

  for (i = 1; i <= 12; i++)
  {
    for (j = 1; j <= 12; j++)
    {
      matriz[i][j] = i * j;
    }
  }
  for (i = 1; i <= 12; i++)
  {
    for (j = 1; j <= 12; j++)
    {
      printf("%d\t", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}
