#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "trabalho.h"

MESAS m;
PEDIDOS p;
RESTAURANTE r;
OPCOES o;
GARCONS ga;
FILE *f;
FILE *g;

struct mesas *atualM, *aux;
struct pedidos *auxpedidos;
struct opcoes *atualO, *auxopcoes;
struct garcons *atualG, *auxgarcons;


void colocapedidos(){

    int codigo;
    char nome[32];
    int mesa;
    int quantidade;
    bool achei = false;

    printf("\nDigite o numero da mesa: ");
    scanf("%i",&mesa);
    while(atualM -> anterior != NULL){
        atualM = atualM->anterior;
    }
    while(atualM -> proximo != NULL){
        if(atualM->valor == mesa){
            achei = true;
            break;
        }
        atualM = atualM->proximo;
    }
    
    if(achei == true){
        printf("\nEscolha uma das opções abaixo:\n");
        printaopcoes();
        printf("Digite o codigo do pedido:");
        scanf("%i",&codigo);
        printf("Digite a quantidade desse pedido:");
        scanf("%i",&quantidade);
        
        while(atualM->pedido->proximo != NULL){
            atualM->pedido = atualM->pedido->proximo;
        }

        atualM->pedido = atualM->inicio;
        while(atualM->pedido->proximo != NULL){
            atualM->pedido = atualM->pedido->proximo;
        }
        for(int i = 0; i < quantidade; i++){
            while(atualO -> anterior != NULL){
            atualO = atualO->anterior;
            }
            while(atualO -> proximo != NULL){
            if(atualO->codigo == codigo){
                atualM->pedido->codigo = codigo;
                atualM->pedido->preco = atualO->preco;
                strcpy(atualM->pedido->nome,atualO->nome);
                atualM->conta = atualM->conta + atualO->preco;
                break;
            }
            atualO = atualO->proximo;
            }
            atualM->pedido->proximo = (struct pedidos*)malloc(sizeof(struct pedidos));
            atualM->pedido = atualM->pedido->proximo;
            atualM->pedido->proximo = NULL;
            while(atualO -> proximo != NULL){
                atualO = atualO->proximo;
            }
        }
    }
    else{
        printf("ERRO!, Essa mesa não esta ocupada\n");
    }
    while(atualM->proximo != NULL){
        atualM = atualM->proximo;
    }
    printf("\n\n");
}


void criamesas(){

    int i;
    int garcon;
    bool achei_garcon = false;
    bool achei_mesa = false;

    printf("\nDigite o numero da mesa: ");
    scanf("%i",&i);
    while(atualM->anterior != NULL){
        atualM = atualM->anterior;
    }
    while(atualM->proximo != NULL){
        if(atualM->valor == i){
            achei_mesa = true;
        }
        atualM = atualM->proximo;
    }
    if(achei_mesa == false && r.gerei_nota_fiscal == true){
        aux = atualM;
        r.gerei_nota_fiscal = false;
    }
    if(achei_mesa == false){
        printf("Digite o codigo do garçom que atenderá a mesa: ");
        scanf("%i",&garcon);
        while(atualG->anterior != NULL){
            atualG = atualG->anterior;
        }
        while(atualG->proximo != NULL){
            if(atualG->codigo == garcon){

                atualM->valor = i;
                atualM->garcon = garcon;
                atualM = (struct mesas*)malloc(sizeof(struct mesas));
                atualM->pedido = (struct pedidos*)malloc(sizeof(struct pedidos));
                atualM->inicio = atualM->pedido;
                atualM->proximo = NULL;
                atualM->conta = 0;
                atualM->pedido->proximo = NULL;
                strcpy(atualM->pedido->nome," ");
                atualM->anterior = aux;
                aux->proximo = atualM;
                aux = atualM;
                achei_garcon = true;

            }
            atualG = atualG->proximo;
        }
        if(achei_garcon == false){
            printf("\nNão consegui achar o garçom com esse código");
        }
    }
    if(achei_mesa == true){
        printf("\nDesculpe, essa mesa está ocupada no momento");
    }
}


void mudapedido(){

    int numero_mesa;
    int codigo_pedido_novo;
    int codigo_pedido_antigo;
    bool achei_mesa = false;
    bool achei_pedido = false;
    bool achei_pedido_novo = false;

    printf("\nDigite o numero da mesa que deseja alterar o pedido:");
    scanf("%i",&numero_mesa);
    while(atualM->anterior != NULL){
        atualM = atualM->anterior;
    }
    while(atualM->proximo != NULL){
        if(atualM->valor == numero_mesa){
            achei_mesa = true;
            break;
        }
        atualM = atualM->proximo;
    }
    if(achei_mesa == true){
        printf("Digite o codigo do pedido que deseja alterar:");
        scanf("%i",&codigo_pedido_antigo);
        atualM->pedido = atualM->inicio;
        while(atualM->pedido->proximo != NULL){
            if(atualM->pedido->codigo == codigo_pedido_antigo){
                achei_pedido = true;
                break;
            }   
            atualM->pedido = atualM->pedido->proximo;
        }
        if(achei_pedido == true){
            printf("Digite o codigo do novo prato:");
            scanf("%i",&codigo_pedido_novo);
            while(atualO->anterior != NULL){
                atualO = atualO->anterior;
            }
            while(atualO->proximo != NULL){
                if(atualO->codigo == codigo_pedido_novo){
                    achei_pedido_novo = true;
                    break;
                }
                atualO = atualO->proximo;
            }
            if(achei_pedido_novo == true){
                while(atualO->anterior != NULL){
                atualO = atualO->anterior;
                }
                while(atualO->proximo != NULL){
                    if(atualO->codigo == codigo_pedido_antigo){
                        atualM->conta = atualM->conta - atualO->preco;
                    }
                    atualO = atualO->proximo;
                }
                while(atualO->anterior != NULL){
                    atualO = atualO->anterior;
                }
                while(atualO->proximo != NULL){
                    if(atualO->codigo == codigo_pedido_novo){
                        atualM->pedido->codigo = atualO->codigo;
                        atualM->conta = atualM->conta + atualO->preco;
                        strcpy(atualM->pedido->nome,atualO->nome);
                    }
                    atualO = atualO->proximo;
                }
            }
        }
        if(achei_pedido == false){
            printf("\nDesculpe, não encontrei esse pedido nesta mesa");
        }
        if(achei_pedido_novo == false){
            printf("\nDesculpe, não encontrei esse pedido no menu");
        }
    }
    if(achei_mesa == false){
        printf("\nDesculpe, não encontrei essa mesa");
    }
    printf("\n\n");
}


void excluipedido(){

    int numero_mesa;
    int codigo_pedido;
    bool achei_mesa = false;
    bool achei_pedido = false;

    printf("\nDigite o numero da mesa que deseja cancelar o pedido:");
    scanf("%i",&numero_mesa);
    while(atualM->anterior != NULL){
        atualM = atualM->anterior;
    }
    while(atualM->proximo != NULL){
        if(atualM->valor == numero_mesa){
            achei_mesa = true;
            break;
        }
        atualM = atualM->proximo;
    }
    if(achei_mesa == true){
        printf("Digite o codigo do pedido que deseja cancelar:");
        scanf("%i",&codigo_pedido);
        atualM->pedido = atualM->inicio;
        while(atualM->pedido->proximo != NULL){
            if(atualM->pedido->codigo == codigo_pedido){
                achei_pedido = true;
                break;
            }
            atualM->pedido = atualM->pedido->proximo;
        }
        if(achei_pedido == true){
            atualM->conta = atualM->conta - atualM->pedido->preco;
            if(atualM->pedido->codigo == codigo_pedido){
                strcat(atualM->pedido->nome," CANCELADO");
                atualM->pedido->codigo = 0;
                atualM->pedido->preco = 0;
            }
        }
        if(achei_pedido == false){
            printf("\nDesculpe, não achei esse pedido nesta mesa");
        }
    }   
    printf("\n\n");
}


void printamesas(){

    while(atualM -> anterior != NULL){
        atualM = atualM->anterior;
    }
    atualM = atualM->proximo;
    printf("\n");
    while(atualM->proximo != NULL){
        while(atualG->anterior != NULL){
            atualG = atualG->anterior;
        }
        while(atualG->proximo != NULL){
            if(atualG->codigo == atualM->garcon){
                break;
            }
            atualG = atualG->proximo;
        }
        printf("MESA: %i  //  GARÇOM: %s  //  PEDIDOS:",atualM->valor,atualG->nome);
        atualM->pedido = atualM->inicio;
        while(atualM->pedido->proximo != NULL){
            printf(" %s -",atualM->pedido->nome);
            atualM->pedido = atualM->pedido->proximo;
        }
        printf("  //  CONTA ATUAL: %i",atualM->conta);
        atualM = atualM->proximo;
        printf("\n");
    }
    printf("\n\n");
}


void printaopcoes(){

    while(atualO->anterior != NULL){
        atualO = atualO->anterior;
    }

    while(atualO->proximo != NULL){
        printf("\nPrato: %s  --  Codigo: %i  --  Preço: %i",atualO->nome,atualO->codigo,atualO->preco);
        atualO = atualO->proximo;
    }
    printf("\n\n");
}


void printagarcons(){

    while(atualG->anterior != NULL){
        atualG = atualG->anterior;
    }

    while(atualG->proximo != NULL){
        printf("\nGarçom: %s  --  Codigo: %i",atualG->nome,atualG->codigo);
        atualG = atualG->proximo;
    }
    printf("\n\n");
}


void notafiscal(){

    int numero_mesa;
    bool achei_mesa = false;

    printf("\nDigite o numero da mesa que deseja fechar a conta:");
    scanf("%i",&numero_mesa);
    if(numero_mesa > 0){
        while(atualM->anterior != NULL){
            atualM = atualM->anterior;
        }
        while(atualM->proximo != NULL){
            if(atualM->valor == numero_mesa){
                achei_mesa = true;
                break;
            }
            atualM = atualM->proximo;
        }
        if(achei_mesa == true){
            while(atualG->anterior != NULL){
                atualG = atualG->anterior;
            }
            while(atualG->proximo != NULL){
                if(atualG->codigo == atualM->garcon){
                    break;
                }
                atualG = atualG->proximo;
            }
            printf("\n\n");
            printf("\n\t******************************************");
            printf("\n\t*********  N-O-T-A  F-I-S-C-A-L  *********");
            printf("\n\t******************************************\n");
            printf("\n\n\tGarçom que atendeu a mesa %i -> %s",atualM->valor,atualG->nome);
            printf("\n\n\tPEDIDOS:\n");

            atualM->pedido = atualM->inicio;
            while(atualM->pedido->proximo != NULL){
                printf("\n\tPrato: %s  //  Preço: %i",atualM->pedido->nome,atualM->pedido->preco);
                atualM->pedido = atualM->pedido->proximo;
            }
            printf("\n\n\tValor Total: %i",atualM->conta);
            r.gerei_nota_fiscal = true;
            while(atualM->anterior != NULL){
                atualM = atualM->anterior;
            }
            while(atualM->proximo != NULL){
                if(atualM->valor == numero_mesa){
                    aux = atualM;
                    atualM = atualM->anterior;
                    if(atualM->proximo->proximo != NULL){
                        atualM->proximo = atualM->proximo->proximo;
                        atualM = atualM->proximo;
                        atualM->anterior = atualM->anterior->anterior;
                    }
                    else{
                        atualM->proximo = NULL;
                    }
                    free(aux);
                    break;
                }
                atualM = atualM->proximo;
            }
        }
    }
    if(numero_mesa < 1){
        printf("\nDesculpe, você não pode excluir essa mesa");
    }
    if(achei_mesa == false && numero_mesa > 0){
        printf("\nDesculpe, não achei essa mesa");
    }
    printf("\n\n\n\n\n");
}


void ADMPratos(){

    int opcao = 0;
    while(true){

        printf("\n\t*************************************************");
        printf("\n\t********** M-E-N-U  A-D-M  P-R-A-T-O-S  *********");
        printf("\n\t*************************************************\n");
        printf("\nDigite uma das opçẽs abaixo:\n");
        printf("\n(1)Novo prato\n(2)Excluir prato\n(3)Alterar prato\n(4)Consultar pratos\n(5)Voltar para o menu principal\n->:");
        scanf("%i",&opcao);

        switch (opcao)
        {
        case 1:
            novo_prato();
            break;
        case 2:
            excluir_prato();
            break;
        case 3:
            alterar_prato();
            break;
        case 4:
            printaopcoes();
            break;
        case 5:
            programa();
            break;
        }
    }
}


void novo_prato(){

    char nome[32];
    int codigo;
    int preco;

    printf("\nDigite o nome do prato:");
    scanf("%s",nome);
    printf("Digite o codigo do prato:");
    scanf("%i",&codigo);
    printf("Digite o preço do prato:");
    scanf("%i",&preco);
    strcpy(atualO->nome,nome);
    atualO->codigo = codigo;
    atualO->preco = preco;
    atualO = (struct opcoes*)malloc(sizeof(struct opcoes));
    atualO->proximo = NULL;
    atualO->anterior = auxopcoes;
    auxopcoes->proximo = atualO;
    auxopcoes = atualO;
    r.quantidade_de_opcoes++;
    
    
}


int excluir_prato(){

    int codigo;
    bool achei = false;

    printf("\nDigite o codigo do prato a ser excluído: ");
    scanf("%i",&codigo);

    while(atualO->anterior != NULL){
        atualO = atualO->anterior;
    }
    while(atualO->proximo != NULL){
        if(atualO->proximo->codigo == codigo){
            printf("\nExclui o prato: %s",atualO->proximo->nome);
            atualO->proximo = atualO->proximo->proximo;
            r.quantidade_de_opcoes--;
            achei = true;
        }
        atualO = atualO->proximo;
    }
    while(atualO->proximo != NULL){
        atualO = atualO->proximo;
    }
    if(achei == false){
        printf("\nNão achei o prato com esse código");
    }
}


void alterar_prato(){

    int codigo;
    int preco;
    char nome[32];
    printf("\nDigite o codigo do prato que deseja alterar:");
    scanf("%i",&codigo);
    while(atualO->anterior != NULL){
        atualO = atualO->anterior;
    }
    while(atualO->proximo != NULL){
        if(atualO->codigo == codigo){
            break;
        }
        atualO = atualO->proximo;
    }
    printf("Digite o novo nome:");
    scanf("%s",nome);
    printf("Digite o novo preco:");
    scanf("%i",&preco);
    strcpy(atualO->nome,nome);
    atualO->preco = preco;
    while(atualO->proximo != NULL){
        atualO = atualO->proximo;
    }
}


void ADMGarcons(){

    int opcao = 0;
    
    while(true){
        printf("\n\t***************************************************");
        printf("\n\t********** M-E-N-U  A-D-M  G-A-R-Ç-O-N-S  *********");
        printf("\n\t***************************************************\n");
        printf("\nDigite uma das opçẽs abaixo:\n");
        printf("\n(1)Novo garçon\n(2)Excluir garçon\n(3)Alterar garçon\n(4)Consultar garçons\n(5)Voltar para o menu principal\n->:");
        scanf("%i",&opcao);

        switch (opcao)
        {
        case 1:
            novo_garcon();
            break;
        case 2:
            excluir_garcon();
            break;
        case 3:
            alterar_garcon();
            break;
        case 4:
            printagarcons();
            break;
        case 5:
            programa();
            break;
        }
    }
}


void novo_garcon(){

    char nome[32];
    int codigo;

    printf("\nDigite o nome do garçom:");
    scanf("%s",nome);
    printf("Digite o codigo do garçom:");
    scanf("%i",&codigo);
    strcpy(atualG->nome,nome);
    atualG->codigo = codigo;
    atualG = (struct garcons*)malloc(sizeof(struct garcons));
    atualG->proximo = NULL;
    atualG->anterior = auxgarcons;
    auxgarcons->proximo = atualG;
    auxgarcons = atualG;
    r.quantidade_de_garcons++;
}


void excluir_garcon(){

    int codigo;
    bool achei = false;

    printf("\nDigite o codigo do garçon a ser excluído: ");
    scanf("%i",&codigo);

    while(atualG->anterior != NULL){
        atualG = atualG->anterior;
    }
    while(atualG->proximo != NULL){
        if(atualG->proximo->codigo == codigo){
            achei = true;
            printf("\nExclui o garçom: %s",atualG->proximo->nome);
            atualG->proximo = atualG->proximo->proximo;
            r.quantidade_de_garcons--;
        }
        atualG = atualG->proximo;
    }
    while(atualG->proximo != NULL){
        atualG = atualG->proximo;
    }
    if(achei == false){
        printf("\nNão achei o garçom com esse código");
    }
}


void alterar_garcon(){

    int codigo;
    char nome[32];
    printf("\nDigite o codigo do garçom que deseja alterar:");
    scanf("%i",&codigo);
    while(atualG->anterior != NULL){
        atualG = atualG->anterior;
    }
    while(atualG->proximo != NULL){
        if(atualG->codigo == codigo){
            break;
        }
        atualG = atualG->proximo;
    }
    printf("Digite o novo nome:");
    scanf("%s",nome);
    strcpy(atualG->nome,nome);
    while(atualG->proximo != NULL){
        atualG = atualG->proximo;
    }
}

int programa(){

    int opcao = 0;

    while(true){

        printf("\n\t**************************************************");
        printf("\n\t***********  M-E-N-U  C-L-I-E-N-T-E-S  ***********");
        printf("\n\t**************************************************\n");
        printf("\nDigite uma das opçẽs abaixo:\n");
        printf("\n(1)Consultar mesas\n(2)Nova mesa\n(3)Novo pedido\n(4)Alterar pedido\n(5)Excluir pedido\n(6)Fechar conta\n(7)ADM Pratos\n(8)ADM garçons\n(9)Fechar programa\n->:");
        scanf("%i",&opcao);

        switch (opcao)
        {
        case 1:
            printamesas();
            break;
        case 2:
            r.quantidade_de_mesas++;
            criamesas();
            break;
        case 3:
            colocapedidos();
            break;
        case 4:
            mudapedido();
            break;
        case 5:
            excluipedido();
            break;
        case 6:
            notafiscal();
            break;
        case 7:
            ADMPratos();
            break;
        case 8:
            ADMGarcons();
            break;
        case 9:
            fechaprograma();
            exit(0);
            break;
        }
    }
}


void pegadados_garcons(){

    char nome[32];
    int codigo;
    char c;

    f = fopen("garcons.bin","rb");
    rewind(f);
    while(c != EOF){
        c = getc(f);
        if(c == ' '){
            r.quantidade_de_garcons++;
        }
    }

    rewind(f);

    for(int i = 0; i < r.quantidade_de_garcons; i++){
        fscanf(f,"%s %i",nome,&codigo);
        atualG->codigo = codigo;
        strcpy(atualG->nome,nome);
        atualG = (struct garcons*)malloc(sizeof(struct garcons));
        atualG->proximo = NULL;
        atualG->anterior = auxgarcons;
        auxgarcons->proximo = atualG;
        auxgarcons = atualG;
        
    }
    fclose(f);
    
    while(atualG -> anterior != NULL){
        atualG = atualG->anterior;
    }
}


void pegadados_opcoes(){

    char nome[32];
    int preco;
    int codigo;
    char c;

    f = fopen("opcoes.bin","rb");
    rewind(f);
    while(c != EOF){
        c = getc(f);
        if(c == '\n'){
            r.quantidade_de_opcoes++;
        }
    }

    rewind(f);
    for(int i = 0; i < r.quantidade_de_opcoes; i++){
        fscanf(f,"%s %i %i",nome,&codigo,&preco);
        atualO->codigo = codigo;
        atualO->preco = preco;
        strcpy(atualO->nome,nome);
        atualO = (struct opcoes*)malloc(sizeof(struct opcoes));
        atualO->proximo = NULL;
        atualO->anterior = auxopcoes;
        auxopcoes->proximo = atualO;
        auxopcoes = atualO;
    }
    fclose(f);
    while(atualO -> anterior != NULL){
        atualO = atualO->anterior;
    }
}


void declaramesasepedidos(){

    atualM = aux = NULL; // "Aterramento"
    atualM = (struct mesas*)malloc(sizeof(struct mesas));
    atualM->pedido = (struct pedidos*)malloc(sizeof(struct pedidos));
    atualM->inicio = atualM->pedido;
    atualM->pedido->proximo = NULL;
    atualM->conta = 0;
    atualM->valor = 0;
    strcpy(atualM->pedido->nome," ");
    atualM->proximo = NULL;
    aux = atualM;
    atualM -> anterior = atualM -> proximo = NULL;

    atualM = (struct mesas*)malloc(sizeof(struct mesas));
    atualM->pedido = (struct pedidos*)malloc(sizeof(struct pedidos));
    atualM->inicio = atualM->pedido;
    atualM->proximo = NULL;
    atualM->conta = 0;
    atualM->pedido->proximo = NULL;
    strcpy(atualM->pedido->nome," ");
    atualM->anterior = aux;
    aux->proximo = atualM;
    aux = atualM;

}


void declaraopcoesegarcons(){

    atualG = auxgarcons = NULL; // "Aterramento"
    atualG = (struct garcons*)malloc(sizeof(struct garcons));
    atualG->proximo = NULL;
    auxgarcons = atualG;
    atualG -> anterior = atualG -> proximo = NULL;

    atualO = auxopcoes = NULL; // "Aterramento"
    atualO = (struct opcoes*)malloc(sizeof(struct opcoes));
    atualO->proximo = NULL;
    auxopcoes = atualO;
    atualO -> anterior = atualO -> proximo = NULL;

}


void fechaprograma(){

    int quantidade_de_pratos = 0;
    int quantidade_de_garcons = 0;

    while(atualO->anterior != NULL){
        atualO = atualO->anterior;
    }

    while(atualO->proximo != NULL){
        quantidade_de_pratos++;
        atualO = atualO->proximo;
    }

    while(atualO->anterior != NULL){
        atualO = atualO->anterior;
    }

    f = fopen("opcoes.bin","wb");
    rewind(f);

    for(int i = 0; i < quantidade_de_pratos; i++){
        fprintf(f,"%s %i %i\n",atualO->nome,atualO->codigo,atualO->preco);
        atualO = atualO->proximo;
    }
    
    fclose(f);

    while(atualG->anterior != NULL){
        atualG = atualG->anterior;
    }

    while(atualG->proximo != NULL){
        quantidade_de_garcons++;
        atualG = atualG->proximo;
    }

    while(atualG->anterior != NULL){
        atualG = atualG->anterior;
    }

    f = fopen("garcons.bin","wb");
    rewind(f);

    for(int i = 0; i < quantidade_de_garcons; i++){
        fprintf(f,"%s %i\n",atualG->nome,atualG->codigo);
        atualG = atualG->proximo;
    }
    
    fclose(f);

    printf("\nPROGRAMA FECHADO!");
    printf("\n");
    
}


void cria_garcons(){

    f = fopen("garcons.bin","rb");
    if(f != NULL){
        fclose(f);
    }
    else{
        f = fopen("garcons.bin","wb");
        fprintf(f,"lucas 1\n");
        fprintf(f,"luana 2\n");
        fprintf(f,"gabriel 3\n");
        fprintf(f,"matheus 4\n");
        fclose(f);
    }
}


void cria_opcoes(){

    f = fopen("opcoes.bin","rb");
    if(f != NULL){
        fclose(f);
    }
    else{
        f = fopen("opcoes.bin","wb");
        fprintf(f,"arroz 1 10\n");
        fprintf(f,"feijao 2 10\n");
        fprintf(f,"lasanha 3 20\n");
        fprintf(f,"pizza 4 25\n");
        fprintf(f,"batata_frita 5 8\n");
        fprintf(f,"tofu 6 12\n");
        fprintf(f,"farofa 7 5\n");
        fprintf(f,"carne_moida 8 15\n");
        fclose(f);
    }
}


int main(){

    cria_garcons();
    r.quantidade_de_mesas = 0;
    cria_opcoes();
    r.quantidade_de_mesas = 0;
    declaraopcoesegarcons();
    r.gerei_nota_fiscal = false;
    pegadados_garcons();
    r.quantidade_de_mesas = 0;
    pegadados_opcoes();
    r.quantidade_de_opcoes = 0;
    declaramesasepedidos();
    r.quantidade_de_garcons = 0;
    programa();
    
    return 0;
}