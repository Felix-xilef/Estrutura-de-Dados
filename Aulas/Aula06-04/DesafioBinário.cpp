#include <stdio.h>
#include <stdlib.h>

main() {
    FILE *arq = fopen("DesafioBinário.bin", "rb");
    int i;
    if (arq == NULL) {
        arq = fopen("DesafioBinário.bin", "w+b");
        i = 0;
    } else {
        fseek(arq, -1*sizeof(int), SEEK_END);
        fread(&i, sizeof(int), 1, arq);
        i++;
        fclose(arq);
        arq = fopen("DesafioBinário.bin", "a+b");
    }
    for (int aux = i + 20; i < aux; i++) fwrite(&i, sizeof(int), 1, arq);
    fseek(arq, 0, SEEK_SET);
    int numeros[i];
    fread(numeros, sizeof(int), i, arq);
    fclose(arq);
    for (int aux = 0; aux < i; aux++) printf("%d\t", numeros[aux]);
    system("pause");
}