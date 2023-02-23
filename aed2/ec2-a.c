#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// TODO: 
void ordenaVetor(int v[], int n){
    int aux = 0;
    printf("\norderVector\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (v[i] < v[j]){
                aux = v[j];
                v[j] = v[i];
                v[i] = aux;
            }
            
        }   
    }    
}
void subvetor(int v[], int n, int x){
    int m[n+1][x+1],soma, aux;
    for (int j = 0; j <= n; j++){
        for(int i = 0; i <= x; i++){
            m[j][i] = 0;
        }
    }
    for (int j = 0; j <= n; j++){
        m[j][0] = 1;
    }
    for(int i = 0; i <= x; i++){
        m[0][i] = 0;
    }
    // for(int i = 0; i < n; i++){
    //     soma = v[i];
    //     for (int j = i+1; j < n; j++){
    //         if((soma + v[j]) <= x){
    //             soma = soma + v[j];
    //             m[i][j] = j;
    //             aux = j;
    //         }
    //         else if((soma - v[aux] + v[j] ) == x){
    //             soma = soma - v[aux] + v[j];
    //             m[i][aux] = 0;
    //             m[i][j] = j;
    //         }
    //     }
        
    // }
    printf("matrix final\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
   
}
int main(){
    int v[6] = {1,7,8,6,5,2};
    int x=15;
    ordenaVetor(v,6);
    subvetor(v,6,x);

}