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