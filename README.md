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
# revisar o programa 6
## Programa 6

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>



int main(){
    setlocale(LC_ALL, "Portuguse");
    int n,*od,*gl,i;
    int totalq=0,totall=0;
    float qpl=0,ppq=0,*p,precototal=0;

    printf("Informe a quantidade de paradas para reabastecer\n");
    scanf("%d", &n);
    system("clear");
    od = (int *)malloc(n * sizeof(int));
    gl = (int *)malloc(n * sizeof(int));
    p = (float *)malloc(n * sizeof(float));

    
    for(i=1;i <= n;i++){
        printf("informe a quilometragem rodada\n");
        scanf("%d",&od[i]);
        printf("informe a quantidade de litros abastecidos\n");
        scanf("%d",&gl[i]);
        printf("infome o valor pago\n");
        scanf("%f",&p[i]);
        system("clear");
    }
    for(i=1;i <= n;i++){
        totall += gl[i];
        totalq += od[i];
        precototal+=p[i];
        if(i%2==0){
            printf("Quantidade quilometros andados por litro a cada duas paradas é %d\n",totalq/totall);
        }
    }
    qpl = totalq/totall;
    ppq = precototal/totalq;
    printf("Quilometros %d, Litros %d, Preço %.2f \n",totalq,totall,precototal);
    printf("Quilometros por litros: %.2f, Custo do combustível por quilometro: %.2f\n",qpl,ppq);
    
}
```

## Programa 7 
```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 

float average;
typedef struct studants{
    char name[40];
    double grades;
}datastudants;

datastudants studants[50];
datastudants top5[5];

void GetData(){
    int i;
    for(i=0;i<10;i++){
        printf("write the studant name: ");
        scanf("%s", studants[i].name);
        printf("write the studant grades: ");
        scanf("%lf", &(studants[i].grades));
    }
    
}
void GetAverage(){
    float sum=0;
    for (int i = 0; i < 10; i++){
        sum += studants[i].grades;
    }
    average = sum/10;
}
void SelectStudants(){
    double auxgrades;
    char auxname[40];
    for (int i = 0; i < 10; i++){
        if(studants[i].grades>average){
            for (int k = 0; k < 5; k++){
                if (top5[k].grades == 0){
                    auxgrades = top5[k].grades;
                    strcpy(auxname,top5[k].name);
                    top5[k].grades = studants[i].grades;
                    strcpy(top5[k].name,studants[i].name);
                    studants[i].grades = auxgrades;
                    strcpy(studants[i].name,auxname);
                }
                else if (studants[i].grades > top5[k].grades){
                    auxgrades = top5[k].grades;
                    strcpy(auxname,top5[k].name);
                    top5[k].grades = studants[i].grades;
                    strcpy(top5[k].name,studants[i].name);
                    studants[i].grades = auxgrades;
                    strcpy(studants[i].name,auxname);
                }
                
            }
            

        }
    }

}
void PrintStudants(){
    printf("The best studants above average: %2.2f", average);
    printf("\n-----------------------------\n");
    for (int i = 0; i < 5; i++){

        printf("name: %s, grade: %lf \n", top5[i].name, top5[i].grades);
        
    }
    
}
int main(){
    
    GetData();
    GetAverage();
    SelectStudants();
    PrintStudants();
}
```