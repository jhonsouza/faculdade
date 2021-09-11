#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int vum[10], vdois[10], vtres[10];

void GetVetor(){

    srand(time(0));
    for (int i = 0; i < 10; i++){
        vum[i]=(rand()%20);
        vdois[i]=(rand()%20);
        vtres[i]=(rand()%20);
    }
}

void ordena(){
    int aux;

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if(vum[i]<vum[j]){
                aux=vum[j];
                vum[j]=vum[i];
                vum[i]=aux;
            }
        }  
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if(vdois[i]<vdois[j]){
                aux=vdois[j];
                vdois[j]=vdois[i];
                vdois[i]=aux;
            }
        }  
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if(vtres[i]<vtres[j]){
                aux=vtres[j];
                vtres[j]=vtres[i];
                vtres[i]=aux;
            }
        }  
    }
    
}
void printvetor(){
    for (int i = 0; i < 10; i++){
        printf("%d %d %d \n",vum[i],vdois[i],vtres[i]);
    }   
}

int main(){
    GetVetor();
    ordena();
    printvetor();
}