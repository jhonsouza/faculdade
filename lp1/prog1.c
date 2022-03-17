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