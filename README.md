### Programa 1 

```
#include <stdio.h>
#include <locale.h>



int main(){
    setlocale(LC_ALL, "Portuguese");
    int n,i;
   
    n=0;
    i=1;
    while (n==0){
       if (i%3 == 2 && i%5 == 3 && i%7 == 4){
        n = i;
       }
       else{
        i++;
       }
      
    }
    printf("o resto de %d dividido por 3 é %d\n",n, n%3);
    printf("o resto de %d dividido por 5 é %d\n",n, n%5);
    printf("o resto de %d dividido por 7 é %d\n",n, n%7);
    printf("o menor número positivo é %d\n", n);


}
```

## Programa 2
```
#include <stdio.h>
#include <locale.h>

int main (){
    setlocale(LC_ALL, "Portuguese");
    int n,i, count=0;
    printf ("informe o valor de n \n");
    scanf("%d",&n);
    i=1;
    while (i<=n){
        if (n%i == 0){
            count += 1;
            i++;
        }
        else{
            i++;
        }
    }
    if (count == 2){
        printf("valor %d informado é um número primo\n", n);
    }
    else{
        printf("o valor %d informado não é um número primo\n", n);
    }
    
}
```

## Programa 3

```
#include <stdio.h>
#include <locale.h>


int main (){
    setlocale(LC_ALL, "Portuguese");
    int n,i,soma=0;
    printf ("informe uma valor \n");
    scanf("%d",&n);
    i=1;
    while (i<n){
        if(n%i == 0){
            soma += i;
            i++;
        }
        else{
            i++;
        }
    }
    if (soma == n){
        printf("o valor %d é um número perfeito \n",n);
    }
    else{
        printf("o valor %d é diferente da soma dos seus divisores %d\n",n, soma);
    }
    
    
}
```

## Programa 4

```
#include <stdio.h>
#include <locale.h>

int fatorial( int n){
    int resultado;

    if(n==0){
        resultado=1;
        return (resultado);
    }
    resultado = n*fatorial(n-1);
    return (resultado);

}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int n;
    printf("informe o um número \n");
    scanf("%d", &n);
    if (n<0){
        printf("só é permitido números inteiros e positivos\n");
        return main();
    }

    printf("o fatorial de %d é %d\n", n, fatorial(n));

}
```

## Programa 5 

```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <unistd.h> 



int main(){
    setlocale(LC_ALL, "Portuguese");
    double d;
    int r1=0,c50=0,c25=0,c10=0,c5=0,c1=0,parteint,b;
    
    printf("informe o valor do dinheiro:");
    scanf("%lf",&d);
    if (d > 1.0 || d < 0.01){
        printf("o valor informado é inválido \n");
        sleep(20);
        system("clear");
        return main();
    }
    
    parteint = d * 100;
    do{
        if (parteint>=100){
            r1 = parteint/100;
            parteint -= r1*100;
            printf("Quantidade de moedas de R$1 usadas é %d\n", r1);
        }   
        else if(parteint >= 50){
            c50 = parteint/50;
            parteint -= c50*50;
            printf("Quantidade de moedas de R$0,50 usadas é %d\n", c50);
        }
       else if(parteint >= 25){
           c25 = parteint/25;
           //d = fmod(d,25);
           parteint -= c25*25;
           printf("Quantidade de moedas de R$0,25 usadas é %d\n",c25);
       }
       else if(parteint >= 10){
           c10 = parteint/10;
           parteint -= c10*10;
           printf("Quantidade de moedas de R$0,10 usadas é %d\n",c10);
       }
       else if (parteint >= 5 ){
           c5 = parteint/5;
           parteint -= c5*5;
           printf("Quantidade de moedas de R$0,05 usadas é %d\n",c5);
       }
       else if(parteint >= 1){
           c1 = parteint/1;
           parteint-= c1*1;
           printf("Quantidade de moedas de R$0,01 usadas é %d\n",c1);
       }
    }while (parteint > 0);
}
```
## Programa 6

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>



int main(){
    setlocale(LC_ALL, "Portuguse");
    int n,*od,*gl,i;
    int totalq=0,totall=0;
    float qpl=0,ppq=0,*p,precototal=0;

    printf("Informe a quantidade de paradas para reabastecer\n");
    scanf("%d", &n);
    system("clear");
    od = (int *)malloc(n * sizeof(int));
    gl = (int *)malloc(n * sizeof(int));
    p = (float *)malloc(n * sizeof(float));

    
    for(i=1;i <= n;i++){
        printf("informe a quilometragem rodada\n");
        scanf("%d",&od[i]);
        printf("informe a quantidade de litros abastecidos\n");
        scanf("%d",&gl[i]);
        printf("infome o valor pago\n");
        scanf("%f",&p[i]);
        system("clear");
    }
    for(i=1;i <= n;i++){
        totall += gl[i];
        totalq += od[i];
        precototal+=p[i];
        if(i%2==0){
            printf("Quantidade quilometros andados por litro a cada duas paradas é %d\n",totalq/totall);
        }
    }
    qpl = totalq/totall;
    ppq = precototal/totalq;
    printf("Quilometros %d, Litros %d, Preço %.2f \n",totalq,totall,precototal);
    printf("Quilometros por litros: %.2f, Custo do combustível por quilometro: %.2f\n",qpl,ppq);
    
}
```

## Programa 7 
```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 

float average;
typedef struct studants{
    char name[40];
    double grades;
}datastudants;

datastudants studants[50];
datastudants top5[5];

void GetData(){
    int i;
    for(i=0;i<10;i++){
        printf("write the studant name: ");
        scanf("%s", studants[i].name);
        printf("write the studant grades: ");
        scanf("%lf", &(studants[i].grades));
    }
    
}
void GetAverage(){
    float sum=0;
    for (int i = 0; i < 10; i++){
        sum += studants[i].grades;
    }
    average = sum/10;
}
void SelectStudants(){
    double auxgrades;
    char auxname[40];
    for (int i = 0; i < 10; i++){
        if(studants[i].grades>average){
            for (int k = 0; k < 5; k++){
                if (top5[k].grades == 0){
                    auxgrades = top5[k].grades;
                    strcpy(auxname,top5[k].name);
                    top5[k].grades = studants[i].grades;
                    strcpy(top5[k].name,studants[i].name);
                    studants[i].grades = auxgrades;
                    strcpy(studants[i].name,auxname);
                }
                else if (studants[i].grades > top5[k].grades){
                    auxgrades = top5[k].grades;
                    strcpy(auxname,top5[k].name);
                    top5[k].grades = studants[i].grades;
                    strcpy(top5[k].name,studants[i].name);
                    studants[i].grades = auxgrades;
                    strcpy(studants[i].name,auxname);
                }
                
            }
            

        }
    }

}
void PrintStudants(){
    printf("The best studants above average: %2.2f", average);
    printf("\n-----------------------------\n");
    for (int i = 0; i < 5; i++){

        printf("name: %s, grade: %lf \n", top5[i].name, top5[i].grades);
        
    }
    
}
int main(){
    
    GetData();
    GetAverage();
    SelectStudants();
    PrintStudants();
}
```

## Programa 8 
```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>



int main(){
    setlocale(LC_ALL, "Portuguese");
    int vetor[50],i,LargeOne=0,LargeTwo=0;

    srand(time(0));
    for (i=0;i<50;i++){
        vetor[i]=(rand()%1000);
        printf("%d \t",vetor[i]);
    }
    i=0;
    while (i < 50){
        if (LargeOne < vetor[i]){
            LargeTwo = LargeOne;
            LargeOne = vetor[i];
        }
        else if(LargeTwo < vetor[i]){
            LargeTwo = vetor[i];
        }
        i++;
    }
    printf("\no primeiro maior número é: %d\n",LargeOne);
    printf("o segundo maior número é: %d\n",LargeTwo);
    
}
```

## Programa 9 
```
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


int main(){
    char cad[80];
    int tam,i,space=0,j,rep=0;
    int total;


    setlocale(LC_ALL, "Portuguese");

    printf("digite uma palavra de até 80 caracteres: ");
    fgets(cad,80,stdin);

    if(strlen(cad)>80){
        printf("A palavra é maior que 80 caracteres\n");
        return main();
    }
    
    tam=strlen(cad);

    for (i=0; cad[i]!='\n';i++){
        if (cad[i] == ' '){
            space++;
        }
    }

    for(i=0; cad[i]!='\0';i++){
        for(j=0; cad[j]!='\0';j++){
            if(cad[i] == cad[j] && j != i){
                rep++;
                break;
            }
        }
    }
    rep -= space;
    total = tam - space - rep;

    printf("%d tam \t %d space \t %d rep \t",tam,space,rep);
    printf ("\ntotal de letras distintas é %d ",total);
    

}
```

## Programa 10
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char* p;
}word;

void main(){
	char palavra[80] = "banana banana uva mec mec";
	int i = 0;
	int j,z;
	word p[80];
	
	char* teste = strtok(palavra," ");
	while(teste != NULL){
		p[i].p = teste;	
		teste = strtok(NULL," ");
		i++;
	} 

	int rep[80] = {0};
	for(j = 0; j < i; j++){
		printf("\n");
		for(z = 0; z < i; z++){
			if(j != z && strcmp(p[j].p,p[z].p) == 0){
				rep[j]++;
				
			}
		}
	}
	
	for(j = 0; j < i;j++){
		printf("palavra: %s",p[j].p);
		printf(" Repeticoes: %d",rep[j]);
		printf("\n");
	}

}
```
## Programa 11

```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

int pos=0;
typedef struct text
{
    char text[88][88];
    char word[88][88];
}wordtext;
wordtext words;


void GetText(){
    
    FILE* arq;
    char c;
    int i=0, j=0;
    if((arq = fopen("prog11.txt", "r")) == NULL){
        printf("Falha ao abrir o arquivo");
    }
    while (c != EOF){
        c = fgetc(arq);
        if(c != EOF && c != ' ' && c != ',' && c != '.' && c != '\n'){
            words.text[i][j] = c;
            j++;
        }
        else {
            j=0;
            i++;
        }
    }
    fclose(arq);
    
}
void CountVowels(){
    int count =0;
    for (int i = 0; i < 88; i++){
        count=0;
        for (int k = 0; k < strlen(words.text[i]); k++){
            switch (words.text[i][k]){
            case 'a':
                count+=1;
                break;
            case 'A':
                count +=1;
                break;
            case 'e':
                count+=1;
                break;
            case 'E':
                count +=1;
                break;
            case 'i':
                count+=1;
                break;
            case 'I':
                count += 1;
                break;
            case 'o':
                count+=1;
                break;
            case 'O':
                count +=1;
                break;
            case 'u':
                count+=1;
                break;
            case 'U':
                count +=1;
                break;
            default:
                break;
            }
        }
        if(count>2){
            strcpy(words.word[pos],words.text[i]);
            pos++;
        }
        
    }
    
}
void PrintWords(){
    
    for (int i = 0; i < pos; i++){
        printf("Word: %s \n",words.word[i]);
    }
    
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    GetText();
    CountVowels();
    PrintWords();
}
```
## Programa 12
```
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
```
## Programa 13
```
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
```

## Programa 14
```
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

int main(){
    
    printf("********** RELÓGIO **********\n\n");
    int segundos = 0;
    int minutos = 0;
    int horas = 0;
    int aux = 100;
    int aux2 = 0;

    while (horas < 25)
    {
        printf("\r\t%2d : %2d : %2d",horas,minutos,segundos);
        aux2++;
        usleep(aux*125);
        if(aux2 == 60){
            segundos++;
            aux2 = 0;
        }
        if(segundos == 59){
            segundos = 0;
            minutos++;
        }
        if(minutos == 59){
            segundos = 0;
            minutos = 0;
            horas++;
        }
        if(horas == 24){
            segundos = 0;
            minutos = 0;
            horas = 0;
        }
    }
    return 0;
}
```
## Programa 15
```
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
```
## Programa 16
```
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
```