#include <stdio.h>
#include <locale.h>

int main (){
    setlocale(LC_ALL, "Portuguese");
    int n,i, count=0;
    printf ("informe o valor de n \n");
    scanf("%d",&n);
    i=1;
    while (i<=n){
        if (n%i == 0){
            count += 1;
            i++;
        }
        else{
            i++;
        }
    }
    if (count == 2){
        printf("valor %d informado é um número primo\n", n);
    }
    else{
        printf("o valor %d informado não é um número primo\n", n);
    }
    
}