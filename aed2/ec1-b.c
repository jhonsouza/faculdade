#include <stdio.h>


int CountF(char v[], int k, int n){
	int qtde = 0;
	for(int i = k; i <= n; i++){
		if (v[i] == 'F'){
			qtde += 1;
		}
	}
	return qtde;
}
int CountFs(char v[], int n){
	int meio = n/2;
	if (v[n-1] != 'F'){
		return 0;
	}
	else if (v[0] == 'F'){
		return n;
	}
	else{
		return CountF(v,0,meio) + CountF(v,meio+1,n);
	}
}


int main(){
	char vetor1[7] = {'V','V','V','V','F','F','F'};
	char vetor2[4] = {'V','V','V','V'};
	char vetor3[4] = {'F','F','F','F'};
	char vetor4[9] = {'V','V','V','V','F','F','F','F','F'};

	printf("%d\n", CountFs(vetor1,7));
	printf("%d\n", CountFs(vetor2,4));
	printf("%d\n", CountFs(vetor3,4));
	printf("%d\n", CountFs(vetor4,9));

}