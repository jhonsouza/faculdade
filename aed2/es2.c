#include <stdio.h>

int T[14][14];

int Torneio(int n){
    int p =0;
    if(n == 1){
        T[1][1]=1;
    }
    else{
        p = n/2;
        Torneio(p);
    }
    for(int i = 1; i<=p; i++){
        for(int j=1; j<=p; j++){
            T[i+p][j]=T[i][j]+p;
            T[i][j+p]=n-(j-i+n)%p;
            T[n-(j-i+n)%p][j+p]=i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d\t", T[i][j]);
        }
        printf("\n");
    }

}

int main(){
    int n = 14;
    for(int i = 1; i<=n; i++){
        for(int j=1; j<=n; j++){
            T[i][j]=0;
        }
    }
    Torneio(n);

}