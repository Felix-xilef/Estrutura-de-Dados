#include <stdio.h>
#include <stdlib.h>//necess�rio para malloc
int main(){
	int vet[8], i,n=1;
	int *pv=vet;//atribui��o de ponteiro
	for (i=0;i<6;i++){
		vet[i]=n++;
	}
	//mostra
	printf("&pv=%d - pv=%u  - *pv=%u\n\n",&pv,pv,*pv);
	for(i=0;i<6;i++){
		printf("%u - %u\n",&vet[i], vet[i]);
	}
	printf("\n");
	system("pause");
}
