#include <stdlib.h>
#include <stdio.h>
main() {
    char nome[20];
    int idade;
    printf("Informe seu nome: ");
    gets(nome); //scanf(" %s", nome); //scanf(" %s", &nome[0]);
    printf("informe sua idade: ");
    scanf("%d", &idade);

    if (idade > 18)
    {
        printf("Informe seu nome: ");
    }
    printf("%s, voce tem %d anos\n", nome, idade);

    

    system("pause");
}