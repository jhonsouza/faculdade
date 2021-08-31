#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct text
{
    char text[88][88];
    char word[88][88];
}wordtext;
wordtext words;

void GetText(){
    
    FILE* arq;
    char c;
    int i=0,j=0;
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
    for (int i = 0; i < 88; i++)
    {
        printf("\n%s",words.text[i]);
    }
    
}
void CountVowels(){
    int count =0, pos=0;
    for (int i = 0; i < 88; i++){
        count=0;
        for (int k = 0; k < strlen(words.text[i]); i++){
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
        printf("%d",count);
        if(count>2){
            strcpy(words.word[pos],words.text[i]);
            pos++;
        }
        
    }
    
}
void PrintWords(){
    //size_t n = sizeof(words.word)/sizeof(char);
    for (int i = 0; i < 88; i++){
        printf("\n Word: %s",words.word[i]);
    }
    
}

int main(){

    GetText();
    CountVowels();
    PrintWords();
}