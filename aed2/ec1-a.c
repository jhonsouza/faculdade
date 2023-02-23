#include <stdio.h>
#include <stdlib.h>
int Maioria(int v[],int n){
	int meio = n/2;
	int m1 = 0, m2 = 0, c1 = 1, c2 = 1, rep1 = 0, rep2 = 0;
	int j,i;
	if( n == 0){
		return -1;
	}
	else if(n == 1){
		return v[0];
	}
	else if (n == 2){
		if (v[1] == v[0]){
			return v[0];
		}
		else{
			return -1;
		}
	}
	else{
		for(j = 0;j <= meio;j++){
			if (v[j] == v[j+1]){
				c1 += 1;
			}
			else if (rep1 < c1){
				m1 = v[j];
				rep1 = c1;
				c1 = 1;
			}
		}
		for(i = meio + 1; i <= n; i++){
			if (v[i] == v[i+1]){
				c2 += 1;
			}
			else if (rep2 < c2){
				m2 = v[i];
				rep2 = c2;
				c2 = 1;
			}
		}

		if(m2 == m1){
			return m1;
		}
		else if (rep1 > meio){
			return m1;
		}
		else if (rep2 > meio){
			return m2;
		}
		else if (rep1 > rep2){
			return m1;
		}
		else{
			return m2;
		}
		
	}
}
int main(){
	int array[]={1,2,2,2,2,0,0,0,7,50,1,36,45,-5,19,120};
	int array1[]={30};
	int array2[]={1,40};
	int array3[]={55,55};
	int array4[]={1,5,2,5,2,5,2,5,2,5,0,5,0,5,0,5,7,50,1,36,45,-5,19,120,5};

	printf("%d\n",Maioria(array,16));
	printf("%d\n",Maioria(array1,1));
	printf("%d\n",Maioria(array2,2));
	printf("%d\n",Maioria(array3,2));
	printf("%d\n",Maioria(array4,25));
}