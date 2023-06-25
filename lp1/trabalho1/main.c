#include <stdio.h>
#include "dados.h"
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int no = 0,sd = 0, nd = 0,ceo = 0, sl = 0;
#define n 100
INFO inf;
struct dados norte[n];
struct dados nordeste[n];
struct dados co[n];
struct dados sudeste[n];
struct dados sul[n];
void lista(struct dados p[], int *x, char regiao[]){
    printf("#========= Lista dos Eventos na região %s =========#\n", regiao);
    for (int i =0; i< *x; i++){
        printf("#==== evento %d ====#\n", i);
        printf("tipo: %s\n",p[i].tipo);
        printf("qualidade: %s\n",p[i].qualidade);
        printf("local: %s\n",p[i].local);
        printf("resumo: %s\n",p[i].resumo);
    }
}
void listaEventos(struct dados p[], int *x, char regiao[]){
    system("clear||cls");
    printf("#========= Lista dos Eventos na região %s =========#\n", regiao);
    for (int i =0; i< *x; i++){
        printf("#==== evento %d ====#\n", i);
        printf("tipo: %s\n",p[i].tipo);
        printf("qualidade: %s\n",p[i].qualidade);
        printf("local: %s\n",p[i].local);
        printf("resumo: %s\n",p[i].resumo);
    }
    int escolha;
    printf("1- criar um novo evento\n2- remover um evento\n3- editar um evento\n4- retornar ao menu de regiões: ");
    scanf("%d", &escolha);
    if (escolha == 1){
        criaEventos(p ,x, regiao);
    }
    else if(escolha == 2){
        removeEventos(p, x, regiao);
    }
    else if(escolha == 3){
        editaEventos(p, x, regiao);
    }  
    else if(escolha == 4){
        regioes();
    }  
    else {
        printf("escolha inválida, retornando ao menu de regiões\n");
        regioes();
    }
}
void criaEventos(struct dados *p, int *x, char regiao[]){
    char t;
    int soma = no+ceo+sd+nd+sl;
    if (soma == 100){
        printf("capacidade máxima de eventos atingida\n retornando ao menu de região!\n");
        regioes();
    }
    else{
        system("clear||cls");
        printf("%d\n", soma);
        printf("#========= Criando um evento na região %s =========#\n", regiao);
        printf("qual o tipo do evento?\n");
        scanf("%s", p[*x].tipo);
        printf("qual a qualidade do evento?\n");
        scanf("%s", p[*x].qualidade);
        printf("Qual o local do evento?\n");
        t = getchar();
        gets(p[*x].local);
        printf("faça um breve resumo do evento:\n");
        gets(p[*x].resumo);   
        system("clear||cls");
        *x+=1;
        int escolha;
        printf("1- criar um novo evento\n2- retonar ao menu\n3- retornar ao menu de regiões: ");
        scanf("%d", &escolha);
        if (escolha == 1){
            criaEventos(p ,x, regiao);
        }
        else if(escolha == 2){

            menu(p, x, regiao);
        }
        else if(escolha == 3){
            regioes();
        }  
        else {
            printf("escolha inválida, retornando ao menu de regiões\n");
            regioes();
        }
    }
}
void removeEventos(struct dados *p, int *x, char regiao[]){
    int y;
    printf("#========= Removendo um evento na região %s =========#\n", regiao);
    lista(p, x, regiao);
    printf("Qual evento deseja editar?\n");
    scanf("%d", &y);
    for (int i = y; i < *x; i++)
    {
        strcpy(p[i].local,p[i+1].local);
        strcpy(p[i].qualidade,p[i+1].qualidade);
        strcpy(p[i].resumo,p[i+1].resumo);
        strcpy(p[i].tipo,p[i+1].tipo);
    }
    *x-=1;
    lista(p, x, regiao);
    int escolha;
    printf("1- remover outro evento\n2- retonar ao menu\n3- retornar ao menu de regiões: ");
    scanf("%d", &escolha);
    if (escolha == 1){
        removeEventos(p ,x, regiao);
    }
    else if(escolha == 2){

        menu(p, x, regiao);
    }
    else if(escolha == 3){
        regioes();
    }  
    else {
        printf("escolha inválida, retornando ao menu de regiões\n");
        regioes();
    }

}
void editaEventos(struct dados *p, int *x, char regiao[]){
    int evento,alteracao;
    printf("#========= Editando um evento na região %s =========#\n", regiao);
    lista(p, x, regiao);
    printf("Qual evento deseja editar?\n");
    scanf("%d", &evento);

    printf("Qual informação deseja alterar?\n");
    printf("1- tipo\n2- qualidade\n3- local\n4- resumo\n5- todas\n");
    scanf("%d", &alteracao);
    char t;
    t = getchar();
    if (alteracao == 1){
        printf("qual o tipo do evento?\n");
        scanf("%s", p[evento].tipo);
        lista(p, x, regiao);
    }
    else if (alteracao == 2){
        printf("qual a qualidade do evento?\n");
        scanf("%s", p[evento].qualidade);
        lista(p, x, regiao);
    }
    else if (alteracao == 3){
        printf("Qual o local do evento?\n");
        gets(p[evento].local);
        lista(p, x, regiao);
    }
    else if (alteracao == 4){
        printf("faça um breve resumo do evento:\n");
        gets(p[evento].resumo); 
        lista(p, x, regiao);
    }
    else if (alteracao == 5){
        printf("qual o tipo do evento?\n");
        scanf("%s", p[evento].tipo);
        printf("qual a qualidade do evento?\n");
        scanf("%s", p[evento].qualidade);
        printf("Qual o local do evento?\n");
        t = getchar();
        gets(p[evento].local);
        printf("faça um breve resumo do evento:\n");
        gets(p[evento].resumo);   
        lista(p, x, regiao);
    }
    
    
}
void regioes(){
    int escolha;
    system("clear||cls");
    printf("#========= Menu de Regiões =========#\n");
    printf("1- Norte\n2- Nordeste\n3- Centro-oeste\n4- Sudeste\n5- Sul\n");
    scanf("%d", &escolha);
    if (escolha == 1){
        menu(&norte, &no, "norte");
    }
    else if (escolha == 2){
        menu(&nordeste, &nd, "nordeste");
    }
    else if (escolha == 3)
    {
        menu(&co, &ceo, "centro-oeste");
    }
    else if (escolha == 4)
    {
        menu(&sudeste, &sd, "sudeste");
    }
    else if (escolha == 5)
    {
        menu(&sul, &sl, "sul");
    }
    else{
        printf("Região inválida\n");
        sleep(3);
        system("clear||cls");
        return regioes(norte);
    }
}

void menu(struct dados *p, int *x, char regiao[]){
    int escolha;
    system("clear||cls");
    printf("#======== menu de eventos da regiao %s========#\n", regiao);
    printf("1- criar um novo evento\n");
    printf("2- listar todos os eventos\n");
    printf("3- remover um evento\n");
    printf("4- editar um evento\n");
    printf("5- escolher uma nova região\n");
    scanf("%d", &escolha);

    if (escolha == 1)
    {
        criaEventos(p, x, regiao);
    }
    else if (escolha == 2)
    {
        listaEventos(p, x, regiao);
    }
    else if (escolha == 3)
    {
        removeEventos(p, x, regiao);
    }
    else if (escolha == 4)
    {
        editaEventos(p, x, regiao);
    }
    else if (escolha == 5){
        return regioes();
    }
    else
    {
        printf("opção inválida!!\n");
        return menu(p, x, regiao);
    }
}

int main(){
    
    setlocale(LC_ALL, "Portuguese");    
    regioes();
    /*menu(&p[0]);*/
}