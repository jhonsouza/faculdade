#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct number{
    char n[4];
    char ex[4][40];
}num;

num nume;

void GetNumber(){
    char aux[6];
    printf("informe um número entre 0 e 9.999: ");
    fgets(aux,6,stdin);
    if(strlen(aux)>5){
        printf("o número informado é maior que 9.999\n");
        strcpy(aux, "");
        return GetNumber(); 
    }
    if(strlen(aux)==2){
        nume.n[3]=aux[0];
    }
    else if (strlen(aux)==3){
        nume.n[3]=aux[1];
        nume.n[2]=aux[0];
    }
    else if(strlen(aux)==4){
        nume.n[3]=aux[2];
        nume.n[2]=aux[1];
        nume.n[1]=aux[0];
    }
    else{
        nume.n[3]=aux[3];
        nume.n[2]=aux[2];
        nume.n[1]=aux[1];
        nume.n[0]=aux[0];
    }
}

void extenso(){
    
    switch (nume.n[0]){
    case '9':
        strcpy(nume.ex[0],"nove mil ");
        break;
    case '8':
        strcpy(nume.ex[0],"oito mil ");
        break;
    case '7':
        strcpy(nume.ex[0],"sete mil ");
        break;
    case '6':
        strcpy(nume.ex[0],"seis mil ");
        break;
    case '5':
        strcpy(nume.ex[0],"cinco mil ");
        break;
    case '4':
        strcpy(nume.ex[0],"quatro mil ");
        break;
    case '3':
        strcpy(nume.ex[0],"tres mil ");
        break;
    case '2':
        strcpy(nume.ex[0],"dois mil ");
        break;
    case '1':
        strcpy(nume.ex[0],"mil ");
        break;
    }
    switch (nume.n[1]){
    case '9':
        strcpy(nume.ex[1],"novecentos e ");
        break;
    case '8':
        strcpy(nume.ex[1],"oitocentos e ");
        break;
    case '7':
        strcpy(nume.ex[1],"setecentos e ");
        break;
    case '6':
        strcpy(nume.ex[1],"seiscentos e ");
        break;
    case '5':
        strcpy(nume.ex[1],"quinhetos e ");
        break;
    case '4':
        strcpy(nume.ex[1],"quatrocentos e ");
        break;
    case '3':
        strcpy(nume.ex[1],"trezentos e ");
        break;
    case '2':
        strcpy(nume.ex[1],"duzentos e ");
        break;
    case '1':
        strcpy(nume.ex[1],"cento e ");
        break;
    }
    switch (nume.n[2])
    {
    case '9':
        strcpy(nume.ex[2],"noventa e ");
        break;
    case '8':
        strcpy(nume.ex[2],"oitenta e ");
        break;
    case '7':
        strcpy(nume.ex[2],"setenta e ");
        break;
    case '6':
        strcpy(nume.ex[2],"sessenta e ");
        break;
    case '5':
        strcpy(nume.ex[2],"cinquenta e ");
        break;
    case '4':
        strcpy(nume.ex[2],"quarenta e ");
        break;
    case '3':
        strcpy(nume.ex[2],"trinta e ");
        break;
    case '2':
        strcpy(nume.ex[2],"vinte e ");
        break;
    case '1':
        switch (nume.n[3])
        {
        case '9':
            strcpy(nume.ex[2],"dezenove");
            break;
        case '8':
            strcpy(nume.ex[2],"dezoito");
            break;
        case '7':
            strcpy(nume.ex[2],"dezessete");
            break;
        case '6':
            strcpy(nume.ex[2],"dezesseis");
            break;
        case '5':
            strcpy(nume.ex[2],"quinze");
            break;
        case '4':
            strcpy(nume.ex[2],"catorze");
            break;
        case '3':
            strcpy(nume.ex[2],"treze");
            break;
        case '2':
            strcpy(nume.ex[2],"doze");
            break;
        case '1':
            if(nume.n[3] == '1'){
                strcpy(nume.ex[2],"onze");
            }
            else{
                strcpy(nume.ex[2],"dez");
            }
            break;

        }

    }
    if(nume.n[2] != '1'){
        switch (nume.n[3])
        {
        case '9':
            strcpy(nume.ex[3],"nove");
            break;
        case '8':
            strcpy(nume.ex[3],"oito");
            break;
        case '7':
            strcpy(nume.ex[3],"sete");
            break;
        case '6':
            strcpy(nume.ex[3],"seis");
            break;
        case '5':
            strcpy(nume.ex[3],"cinco");
            break;
        case '4':
            strcpy(nume.ex[3],"quatro");
            break;
        case '3':
            strcpy(nume.ex[3],"tres");
            break;
        case '2':
            strcpy(nume.ex[3],"dois");
            break;
        case '1':
            strcpy(nume.ex[3],"um");
            break;

        }
    }
}

void printext(){
    printf("%s %s %s %s", nume.ex[0],nume.ex[1],nume.ex[2],nume.ex[3]);
}
int main(){
    setlocale(LC_ALL, "Portuguese");
    GetNumber();
    extenso();
    printext();
}