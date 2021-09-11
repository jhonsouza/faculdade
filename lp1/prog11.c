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