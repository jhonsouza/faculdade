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
	
	char* split = strtok(palavra," ");
	while(split != NULL){
		p[i].p = split;	
		split = strtok(NULL," ");
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