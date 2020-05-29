#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct lista{
    int matricula;
    float nota;
    struct lista *prev;
    struct lista *next;
}Lista;

int aux(int mat, Lista *ls) {
    if (ls == NULL) return 0;
    if (ls->matricula == mat) return 1;
    return aux(mat, ls->next);
}

//Ex3
void buscaNota(Lista *ls, int mat) {
    if (ls == NULL) printf("\nMatricula Inexistente\n\n");
    else if (ls->matricula == mat) printf("\nNota referente a matricula %d = %.2f\n\n", mat, ls->nota);
    else buscaNota(ls->next, mat);
}
//Fim

//Ex4
int contaNotas(Lista *ult, float nota) {
    if (ult == NULL) return 0;
    if (ult->nota == nota) return contaNotas(ult->prev, nota) + 1;
    return contaNotas(ult->prev, nota);
}
//Fim

main() {
    srand((unsigned)time(NULL));
    int continuar, auxI;
    float auxF;
    do {
        //enchendo lista aleatoriamente
        system("cls");
        int tam = (rand() % 10) + 1;
        Lista *alunos = NULL;
        for (int i = 0; i < tam; i++) {
            Lista *nova = (Lista*)malloc(sizeof(Lista));
            do {
                nova->matricula = rand() + 1;
            } while (aux(nova->matricula, alunos));
            nova->nota = float(rand() % 1001) / 100;
            nova->prev = NULL;
            nova->next = alunos;
            if (alunos != NULL) alunos->prev = nova;
            alunos = nova;
            printf("Mat = %d\n\tNota = %.2f\n", alunos->matricula, alunos->nota);
        }
        
        //ex3
        printf("\nDigite a matricula que deseja procurar\n\t\t>> ");
        scanf("%d", &auxI);
        buscaNota(alunos, auxI);

        //ex4
        Lista *ultimo = alunos;
        while (ultimo->next != NULL) ultimo = ultimo->next;
        printf("\nDigite a nota que deseja contar\n\t\t>> ");
        scanf("%f", &auxF);
        printf("Quantidade de notas %.2f encontradas: %d\n", auxF, contaNotas(ultimo, auxF));

        //repetir programa sem fechar e abrir dnv
        printf("Deseja continuar?\n[0] Nao\n[1] Sim\n  >>");
        scanf("%d", &continuar);
    }while(continuar);
}