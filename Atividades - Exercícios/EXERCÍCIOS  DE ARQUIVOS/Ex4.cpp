#include <stdio.h>
#include <stdlib.h>

main(){
    FILE *arq = fopen("NumBin", "w+b");
    float aux;
    for (int i = 0; i < 10; i++) {
        printf("Digte o %d float: ", i + 1);
        scanf("%f", &aux);
        fwrite(&aux, sizeof(float), 1, arq);
    }
    fseek(arq, 0, SEEK_SET);
    while (fread(&aux, sizeof(float), 1, arq) == 1) printf("%.2f\n", aux);
    fclose(arq);
    system("pause");
}