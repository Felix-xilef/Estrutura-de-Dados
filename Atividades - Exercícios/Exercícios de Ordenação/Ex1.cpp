#include <stdlib.h>
#include <stdio.h>

void ordenaRepetidos(int origem[],int dest[],int tam) {
    int i, j, p;
    //determinar a posição de cada elemento no vetor ordenado
    for(i = 0; i < tam; i++){
        p = 0;
        for(j = 0; j < tam; j++)
            if (origem[i] > origem[j])
                p++;
        while(dest[p] == origem[i]) p++;
        dest[p] = origem[i];
    } 
}

main() {
    int vetI[] = {1, 3, 1, 1, 3, 2, 3, 1, 2}, vetF[9];

    printf("\n\tVetor Original:\n");
    for (int i = 0; i < 9; i++) printf("\t%d", vetI[i]);
    
    ordenaRepetidos(vetI, vetF, 9);
    printf("\n\tVetor Ordenado:\n");
    for (int i = 0; i < 9; i++) printf("\t%d", vetF[i]);

    printf("\n\n");
    system("pause");
}