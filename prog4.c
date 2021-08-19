#include <stdio.h>
#include <locale.h>

int fatorial( int n){
    int resultado;

    if(n==0){
        resultado=1;
        return (resultado);
    }
    resultado = n*fatorial(n-1);
    return (resultado);

}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int n;
    printf("informe o um número \n");
    scanf("%d", &n);
    if (n<0){
        printf("só é permitido números inteiros e positivos\n");
        return main();
    }

    printf("o fatorial de %d é %d\n", n, fatorial(n));

}