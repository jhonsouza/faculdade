#include <stdio.h>
#include "biblioteca15.h"
#include <stdlib.h>
#include <string.h>

int count=0;
data dados;
void getdata(){
    char c;
    FILE *arq;
    int contador=0;
    int nc=0,sexo=0,proc=0;
    int num=0;
    int num1=0;
    int num2=0;
    int num3=0;
    if((arq = fopen("dados.txt", "r")) == NULL){
        printf("Falha ao abrir o arquivo");
    }

    while (c != EOF){
        c = getc(arq);
        if(c == '\0' || c == EOF){
            break;
        }
        if(contador==0){
            num = c -'0';

        }
        if(contador==1){
            num1 = c -'0';
        }
        if(contador==2){
            num2 = c -'0';
        }
        if(contador==3){
            num3 = c -'0';
            dados.DN[nc]= (num*1000)+(num1*100)+(num2*10)+(num3*1);
            dados.idade[nc]=(2021-dados.DN[nc]);
            nc++;
        }
        if(contador==5){
            dados.sexo[sexo]=c;
            sexo++;
        }
        if(contador==7){
            dados.procedencia[proc]=c;
            proc++;
            contador=-2;
            count++;
        }
        contador++;
        
    }
    fclose(arq);
    
}
void menor21(){
    int soma=0;
    for (int i = 0; i < count; i++){
        if(dados.idade[i]<21){
            soma++;
        }
    }
    dados.p21= (soma * 100) / count;
}
void mulheres_capital(){
    int soma=0;

    for (int i = 0; i < count; i++){
        if(dados.sexo[i]=='F' && dados.procedencia[i]=='0'){
            soma++;
        }
    }
    dados.mc=soma;
}
void interior60(){
    int soma=0;
    for (int i = 0; i < count; i++){
        if(dados.idade[i]>60 && dados.procedencia[i]=='1'){
            soma++;
        }
    }
    dados.i60=soma;
}
void maior60(){
    for (int i = 0; i < count; i++){
        if(dados.sexo[i]=='F' && dados.idade[i]>60){
            strcpy(dados.m60,"sim");
            break;
        }
        else
        {
            strcpy(dados.m60,"não");
        }
        
    }
}
void printresultado(){
    printf("porcentagem de motoristas com menos de 21: %.2f", dados.p21);
    printf("\nQuantidade de mulher na capital: %d", dados.mc);
    printf("\nQuantidade de motoristas com mais de 60 anos e do interior: %d", dados.i60);
    printf("\nFoi encontrado alguma mulher com mais de 60 anos: %s",dados.m60);
}
int main(){
    getdata();
    menor21();
    mulheres_capital();
    interior60();
    maior60();
    printresultado();
}
