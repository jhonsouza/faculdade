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