#include <stdio.h>

void orderVector(int p[], int n){
    for(int i = 0; i < n; i++){
      for(int j = i+1; j < n; j++){
        if(p[i] > p[j]){
          int tmp = p[j];
          p[j] = p[i];
          p[i] = tmp;
        }
      }
    }
    
}

int minorQuantity(int w, int p[], int n){
    int qtde = 0;
    orderVector(p,n);
    int i = n-1;
    if (w == 0){
        return qtde;
    }
    else{
        while (i >= 0){
            if (p[i] <= w){
                w -= p[i];
                qtde++;
                i--;
            }
            else{
                i--;
            }
        }
        if(w > 0){
         printf("sobraram %d comprimidos\n", w); 
         return qtde;
        }
        else{
         return qtde;
        }
    }
}

int main() {
    int w;
    int p[]={10,13,12,23,9,15,16,17,18,19,20};
    int n = 11;

    printf("quantidade de comprimidos: ");
    scanf("%d", &w);
    // w = 100;
    printf("quantidade de frascos usados: %d\n", minorQuantity(w, p, n));
}