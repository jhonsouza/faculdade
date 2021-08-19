### Programa 1 

```
#include <stdio.h>
#include <locale.h>



int main(){
    setlocale(LC_ALL, "Portuguese");
    int n,i;
   
    n=0;
    i=1;
    while (n==0){
       if (i%3 == 2 && i%5 == 3 && i%7 == 4){
        n = i;
       }
       else{
        i++;
       }
      
    }
    printf("o resto de %d dividido por 3 é %d\n",n, n%3);
    printf("o resto de %d dividido por 5 é %d\n",n, n%5);
    printf("o resto de %d dividido por 7 é %d\n",n, n%7);
    printf("o menor número positivo é %d\n", n);


}
```

## Programa 2
```
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
```

## Programa 3

```
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
```

## Programa 4

```
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
```

## Programa 5 

```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <unistd.h> 



int main(){
    setlocale(LC_ALL, "Portuguese");
    double d;
    int r1=0,c50=0,c25=0,c10=0,c5=0,c1=0,parteint,b;
    
    printf("informe o valor do dinheiro:");
    scanf("%lf",&d);
    if (d > 1.0 || d < 0.01){
        printf("o valor informado é inválido \n");
        sleep(20);
        system("clear");
        return main();
    }
    
    parteint = d * 100;
    do{
        if (parteint>=100){
            r1 = parteint/100;
            parteint -= r1*100;
            printf("Quantidade de moedas de R$1 usadas é %d\n", r1);
        }   
        else if(parteint >= 50){
            c50 = parteint/50;
            parteint -= c50*50;
            printf("Quantidade de moedas de R$0,50 usadas é %d\n", c50);
        }
       else if(parteint >= 25){
           c25 = parteint/25;
           //d = fmod(d,25);
           parteint -= c25*25;
           printf("Quantidade de moedas de R$0,25 usadas é %d\n",c25);
       }
       else if(parteint >= 10){
           c10 = parteint/10;
           parteint -= c10*10;
           printf("Quantidade de moedas de R$0,10 usadas é %d\n",c10);
       }
       else if (parteint >= 5 ){
           c5 = parteint/5;
           parteint -= c5*5;
           printf("Quantidade de moedas de R$0,05 usadas é %d\n",c5);
       }
       else if(parteint >= 1){
           c1 = parteint/1;
           parteint-= c1*1;
           printf("Quantidade de moedas de R$0,01 usadas é %d\n",c1);
       }
    }while (parteint > 0);
}
```