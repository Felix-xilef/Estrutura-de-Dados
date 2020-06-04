#include <stdio.h>
#include <stdlib.h>
//uso do fseek

main(){
    FILE *fp;
    int num[20];
    int vet[5];
    for(int i = 0; i < 20; i++) num[i] = i;
    fp = fopen("fseekDeArquivosBinários.bin","w+b"); //abrir arquivo para gravação(w) e depois leitura(+)
    fwrite(num, sizeof(int), 20, fp); //gravação em binário (gera novo arquivo)
    fseek(fp, -5*sizeof(int), SEEK_END); //SEEK_CUR ou SEEK_SET
    fread(vet, sizeof(int), 5, fp); //leitura de binário
    printf("\nVetor resultante\n");
    for(int i = 0; i < 5; i++) printf("%d\t", vet[i]);
    printf("\n\n");   
    fclose(fp);
    system("pause");
}
