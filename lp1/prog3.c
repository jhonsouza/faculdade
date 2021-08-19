#include <stdio.h>
#include <locale.h>


int main (){
    setlocale(LC_ALL, "Portuguese");
    int n,i,soma=0;
    printf ("informe uma valor \n");
    scanf("%d",&n);
    i=1;
    while (i<n){
        if(n%i == 0){
            soma += i;
            i++;
        }
        else{
            i++;
        }
    }
    if (soma == n){
        printf("o valor %d é um número perfeito \n",n);
    }
    else{
        printf("o valor %d é diferente da soma dos seus divisores %d\n",n, soma);
    }
    
    
}