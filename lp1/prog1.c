#include <stdio.h>

int main()
{
    int n[10], aux, i, j;

    for (i = 0; i < 10; i++)
    {
        printf("#====== numero %d ======#\n", i);
        scanf("%d", &n[i]);
    }
    for (i = 0; i < 9; i++)
    {
        for (j = 1; j < 10; j++)
        {
            if (n[j] < n[i])
            {
                aux = n[i];
                n[i] = n[j];
                n[j] = aux;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("#====== numero %d = %d ======#\n", i, n[i]);
    }
    return 0;
}