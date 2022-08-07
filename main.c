#include <stdio.h>

int main(){
    int n=5,k=6;
    int W[n][k];
    int j,w;
    int l[] = {3,10,4,6,8};
    // zerando a matriz para remover os lixo
    for(int j = 0; j<=n+1; j++){
        for(int w = 0; w<=k+1;w++){
            W[j][w]=0;
        }
    }

    for(int j = 1; j<=n; j++){
        for(int w = 1; w<=k;w++){
            printf("%d\t",W[j][w]);
        }
        printf("\n");
    }
    // for(int j = 1; j<=n;j++){
    //     for(int w=1;w<=k;w++){
    //         W[j][w]=W[j-1][w-1];
    //     }
    // }
    // printf("\n===========================================================================\n");
    // for(int j = 0; j<=n; j++){
    //     for(int w = 0; w<=k;w++){
    //         printf("%d\t",W[j][w]);
    //     }
    //     printf("\n");
    // }
    // for(int w=k;w>0;w--){
    //     if(W[n][w]==1){
    //         printf("%d\t",l[w]);
    //     }
    // }
    

}