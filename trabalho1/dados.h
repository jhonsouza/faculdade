#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef
    struct dados{
        char local[100];
        char tipo[40];
        char qualidade[20];
        char resumo[1000];
    }INFO;

void menu();
void regioes();
void listEventos();
void editaEventos();
void criaEventos();
void removeEventos();