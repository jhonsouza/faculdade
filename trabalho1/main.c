#include <stdio.h>
#include "dados.h"
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int no = 0,sd = 0, nd = 0,ceo = 0, sL = 0;
#define n 2
INFO inf;
struct dados * prox, *ant;

void lista(struct dados *p, int *x, char regiao[]){
    printf("#========= Lista dos Eventos na região %s =========#\n", regiao);
    for (int i =0; i< *x; i++){
        printf("#==== evento %d ====#\n", i);
        printf("tipo: %s\n",p[*x].tipo);
        printf("qualidade: %s\n",p[*x].qualidade);
        printf("local: %s\n",p[*x].local);
        printf("resumo: %s\n",p[*x].resumo);
    }
}
void listaEventos(struct dados *p, int *x, char regiao[]){
    system("clear");
    printf("#========= Lista dos Eventos na região %s =========#\n", regiao);
    for (int i =0; i< *x; i++){
        printf("#==== evento %d ====#\n", i);
        printf("tipo: %s\n",p[*x].tipo);
        printf("qualidade: %s\n",p[*x].qualidade);
        printf("local: %s\n",p[*x].local);
        printf("resumo: %s\n",p[*x].resumo);
    }
    int escolha;
    printf("1- criar um novo evento\n2- remover um evento\n3- editar um evento\n4- retonar ao menu\n5- retornar ao menu de regiões: ");
    scanf("%d", &escolha);
    if (escolha == 1){
        (*x)++;
        criaEventos(p ,x, regiao);
    }
    else if(escolha == 2){
        removeEventos(p, x, regiao);
    }
    else if(escolha == 3){
        editaEventos(p, x, regiao);
    }  
    else if(escolha == 24){
        menu(p, x, regiao);
    }
    else if(escolha == 5){
        regioes();
    }  
    else {
        printf("escolha inválida, retornando ao menu de regiões\n");
        regioes();
    }
}
void criaEventos(struct dados *p, int *x, char regiao[]){
    char t;

    system("clear");
    printf("%d", *x);
    printf("#========= Criando um evento na região %s =========#\n", regiao);
    printf("qual o tipo do evento?\n");
    scanf("%s", p[*x].tipo);
    printf("%s", p[*x].tipo);
    printf("qual a qualidade do evento?\n");
    scanf("%s", p[*x].qualidade);
    printf("Qual o local do evento?\n");
    t = getchar();
    gets(p[*x].local);
    printf("faça um breve resumo do evento:\n");
    gets(p[*x].resumo);   
    system("clear");
    *x+=1;
    int escolha;
    printf("1- criar um novo evento\n2- retonar ao menu\n3- retornar ao menu de regiões:");
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
void removeEventos(struct dados *p, int *x, char regiao[]){
    printf("chegou aqui");
}
void editaEventos(struct dados *p, int *x, char regiao[]){
    lista(p, x, regiao);
    int evento,alteracao;
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
    prox = ant = NULL; //aterramento
    struct dados *norte = (struct dados *)malloc(n * sizeof(struct dados));
    struct dados *nordeste = (struct dados *)malloc(n * sizeof(struct dados));
    struct dados *co = (struct dados *)malloc(n * sizeof(struct dados));
    struct dados *sudeste = (struct dados *)malloc(n * sizeof(struct dados));
    struct dados *sul = (struct dados *)malloc(n * sizeof(struct dados));
    printf("%d\n", no);
    printf("1- Norte\n2- Nordeste\n3- Centro-oeste\n4- Sudeste\n5- Sul\n");
    scanf("%d", &escolha);
    if (escolha == 1){
        norte = (struct dados *)malloc(sizeof(struct dados));
        norte -> anterior = norte->proximo = NULL;
        menu(&norte[no], &no, "norte");
    }
    else if (escolha == 2){
        menu(&nordeste[0], &nd, "nordeste");
    }
    else if (escolha == 3)
    {
        menu(&co[0], &ceo, "centro-oeste");
    }
    else if (escolha == 4)
    {
        menu(&sudeste[0], &sd, "sudeste");
    }
    else if (escolha == 5)
    {
        menu(&sul[0], &sL, "sul");
    }
    else{
        printf("Região inválida\n");
        sleep(3);
        system("clear");
        return regioes();
    }
}

void menu(struct dados *p, int *x, char regiao[]){
    int escolha;
    system("clear");
    printf("#======== menu de eventos ========#\n");
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