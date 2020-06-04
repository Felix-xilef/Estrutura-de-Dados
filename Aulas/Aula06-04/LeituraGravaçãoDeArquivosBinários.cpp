#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num; 
    char nome[10];
    float nota;
}Aluno;

main(){
    FILE *fp;
    Aluno a, b; 
    a.num = 100;
    strcpy(a.nome, "Maria");
    a.nota = 9.5;
    fp = fopen("LeituraGravaçãoDeArquivosBinários.bin", "wb");
    fwrite(&a, sizeof(Aluno), 1, fp); //gravação em binário
    fclose(fp);
    fp = fopen("LeituraGravaçãoDeArquivosBinários.bin", "rb");
    fread(&b, sizeof(Aluno), 1, fp); //leitura de binário
    printf("\nDados gravados:\nNum: %d, Nome: %s, Nota=%.1f\n\n", b.num, b.nome, b.nota);   
    fclose(fp);
    system("pause");
}