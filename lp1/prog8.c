#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>



int main(){
    setlocale(LC_ALL, "Portuguese");
    int vetor[50],i,LargeOne=0,LargeTwo=0;

    srand(time(0));
    for (i=0;i<50;i++){
        vetor[i]=(rand()%1000);
        printf("%d \t",vetor[i]);
    }
    i=0;
    while (i < 50){
        if (LargeOne < vetor[i]){
            LargeTwo = LargeOne;
            LargeOne = vetor[i];
        }
        else if(LargeTwo < vetor[i]){
            LargeTwo = vetor[i];
        }
        i++;
    }
    printf("\no primeiro maior número é: %d\n",LargeOne);
    printf("o segundo maior número é: %d\n",LargeTwo);
    
}
