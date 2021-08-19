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