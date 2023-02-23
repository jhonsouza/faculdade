#include<stdio.h>
#include<string.h>
#define MAX 100
char X[MAX],Y[MAX];
int i,j,m,n,c[MAX][MAX],b[MAX][MAX],k;

char* concatenar(char *s1, int n) {
    int i, j;
    for (i = 0; s1[i] != '\0'; ++i);
    int aux = i;
    for(int k = 0; k < n-1; k++){
        for (j = 0; j < aux; j++, i++) {
            s1[i] = s1[j];
        }
    }
    // printf("%s\n", s1);
    return s1;
}

int LCSlenght(){
	concatenar(X,k);
  m = strlen(X);
  n = strlen(Y);
  for(i=1;i<=m;i++) c[i][0] = 0;
  for(j=0;j<=n;j++) c[0][j] = 0;
  for(i=1;i<=m;i++)
    for(j=1;j<=n;j++){
      if(X[i-1]==Y[j-1]){
        c[i][j] = c[i-1][j-1]+1;
        b[i][j] = 1;
      }
      else if(c[i-1][j]>=c[i][j-1]){
        c[i][j] = c[i-1][j];
        b[i][j] = 2;
      }
      else{
        c[i][j] = c[i][j-1];
        b[i][j] = 3;
      }
    }
  return c[m][n];
}
void showLCS(int i, int j){
  if(i==0 || j==0)
   return;
  if(b[i][j]==1){
    showLCS(i-1,j-1);
    printf("%c",X[i-1]);
  }
  else if(b[i][j]==2){
    showLCS(i-1,j);
  }
  else{
    showLCS(i,j-1);
  }
}
void printMatrix(int i, int j){
	printf("\n");
	for(int k = 0; k <= i; k++){
		for(int w = 0; w <= j; w++){
			printf("%d\t", c[k][w]);
		}
		printf("\n");
	}
}
int main(){
  int num,i;
    printf("\ninforme o padrão que deve ser achado na mensagem: ");
    scanf("%s",X);
    printf("\ninforme a mensagem recebida: ");
    scanf("%s",Y);
    printf("\ninforme a quantidade de vezes que o padrão deve ser achado na mensagem: ");
    scanf("%d",&k);
		if (LCSlenght() == strlen(X)){
			printf("Y\n");
		}
		else{
			printf("N\n");
		}
		
    // printf("Tamanho da LCS: %d - tamanho de X: %ld", LCSlenght(), strlen(X));
    // printf("\nResutado da LCS: ");
    // showLCS(m,n);
		// // printMatrix(m,n);
    // printf("\n");
  
}