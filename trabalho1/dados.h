#include <stdlib.h>
#include <stdio.h>
typedef
    struct dados{
        char local[100];
        char tipo[40];
        char qualidade[20];
        char resumo[1000];
        struct dados *proximo, *anterior;
    }INFO;

void menu();
void regioes();
void listEventos();
void editaEventos();
void criaEventos();
void removeEventos();