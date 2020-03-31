#include <stdio.h>
#include <stdlib.h>//necess�rio para malloc
int main(){
	int tam;
	printf("Informe o tamanho do vetor: ");
	scanf("%d",&tam);
	int *vet=(int*)malloc(sizeof(int)*tam);
	int i;
	printf("Vet=%d\n",vet);
	printf("&i=%d\n",&i);
	printf("&tam=%d\n",&tam);
	printf("\n");
	for(i=0;i<tam;i++){
		vet[i]=i+1;
		printf("%d\t",vet[i]);
	}
	free(vet);
	system("pause");
}
	
