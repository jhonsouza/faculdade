#include <stdio.h>
#include "biblioteca16.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <locale.h>

jogo partida;
void rodada(){
    int d1,d2,d3,d4;
    int i=1;
    srand(time(NULL));
    while (i<=11){
        d1 = (rand()%6)+1;
        d2 = (rand()%6)+1;
        d3 = (rand()%6)+1;
        d4 = (rand()%6)+1;

        if(d1 == d2 && d3 != d4){
            partida.vj1++;
            printf("\nRodada: %d", i);
            printf("\nDados -> jogador 1 (%d - %d) | jogador 2 (%d - %d)", d1, d2, d3, d4);
            printf("\nO jogador 1 venceu a rodada");
        }
        else if(d1 != d2 && d3 == d4){
            partida.vj2++;
            printf("\nRodada: %d", i);
            printf("\nDados -> jogador 1 (%d - %d) | jogador 2 (%d - %d)", d1, d2, d3, d4);
            printf("\nO jogador 2 venceu a rodada");
        }
        else if(d1 == d2 && d3 == d4){
            if(d1>d3){
                partida.vj1++;
                printf("\nRodada: %d", i);
                printf("\nDados -> jogador 1 (%d - %d) | jogador 2 (%d - %d)", d1, d2, d3, d4);
                printf("\nO jogador 1 venceu a rodada");
                
            }
            else if(d1<d3){
                partida.vj2++;
                printf("\nRodada: %d", i);
                printf("\nDados -> jogador 1 (%d - %d) | jogador 2 (%d - %d)", d1, d2, d3, d4);
                printf("\nO jogador 2 venceu a rodada");
                
            }
            else{
                printf("\nRodada: %d", i);
                printf("\nDados -> jogador 1 (%d - %d) | jogador 2 (%d - %d)", d1, d2, d3, d4);
                printf("\nOs jogadores empataram a rodada");
                
            }  
        }
        else if(d1 != d2 && d3 != d4){
            if(d1+d2 > d3+d4){
                partida.vj1++;
                printf("\nRodada: %d", i);
                printf("\nDados -> jogador 1 (%d - %d) | jogador 2 (%d - %d)", d1, d2, d3, d4);
                printf("\nO jogador 1 venceu a rodada");
                
            }
            else if(d1+d2 < d3+d4){
                partida.vj2++;
                printf("\nRodada: %d", i);
                printf("\nDados -> jogador 1 (%d - %d) | jogador 2 (%d - %d)", d1, d2, d3, d4);
                printf("\nO jogador 2 venceu a rodada");
                
            }
            else{
                printf("\nRodada: %d", i);
                printf("\nDados -> jogador 1 (%d - %d) | jogador 2 (%d - %d)", d1, d2, d3, d4);
                printf("\nOs jogadores empataram a rodada");
                
            }
        }
        i++;
    } 
    sleep(10);
    system("clear");
}
void resultado(){
    if(partida.vj1 > partida.vj2){
        printf ("\nO jogador 1 venceu o jogo com %d vitórias. ", partida.vj1);
    }
    else if(partida.vj1 < partida.vj2){
        printf ("\nO jogador 2 venceu o jogo com %d vitórias. ", partida.vj2);
    }
    else
    {
        printf("\nOs jogadores terminaram o jogo empatados com %d vitórias.", partida.vj1);
    }
}


int main(){
    setlocale(LC_ALL, "Portuguese");
    rodada();
    resultado();
}