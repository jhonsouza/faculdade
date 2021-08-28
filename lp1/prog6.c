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