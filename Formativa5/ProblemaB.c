#include <stdio.h>
#include <stdlib.h>

#define MAX_NOS 500000

typedef struct {
    int tipo;
    int esq;
    int dir;
} No;

typedef struct {
    int no;
    int nivel;
} FilaNo;

int main() {
    int N;
    scanf("%d", &N);

    No* nos = (No*)malloc(N * sizeof(No));

    int raiz, esq, dir;
    scanf("%d %d %d", &raiz, &esq, &dir);

    nos[0].tipo = 0;
    nos[0].esq = esq;
    nos[0].dir = dir;

    for (int i = 1; i < N; i++) {
        int tipo, esq, dir;
        scanf("%d %d %d", &tipo, &esq, &dir);
        nos[i].tipo = tipo;
        nos[i].esq = esq;
        nos[i].dir = dir;
    }

    FilaNo* fila = (FilaNo*)malloc(N * sizeof(FilaNo));
    int frente = 0, tras = 0;

    fila[tras++] = (FilaNo){0, 0};

    int* contagemVerdes = (int*)calloc(N, sizeof(int));
    int* contagemVermelhas = (int*)calloc(N, sizeof(int));
    int nivelMaximo = 0;

    while (frente < tras) {
        FilaNo atual = fila[frente++];
        int noAtual = atual.no;
        int nivelAtual = atual.nivel;

        if (nos[noAtual].tipo == 1) {
            contagemVerdes[nivelAtual]++;
        } else if (nos[noAtual].tipo == 2) {
            contagemVermelhas[nivelAtual]++;
        }

        if (nos[noAtual].esq != 0) {
            fila[tras++] = (FilaNo){nos[noAtual].esq - 1, nivelAtual + 1};
        }
        if (nos[noAtual].dir != 0) {
            fila[tras++] = (FilaNo){nos[noAtual].dir - 1, nivelAtual + 1};
        }

        if (nivelAtual > nivelMaximo) {
            nivelMaximo = nivelAtual;
        }
    }

    for (int i = 1; i <= nivelMaximo; i++) {
        printf("%d %d\n", contagemVerdes[i], contagemVermelhas[i]);
    }

    free(nos);
    free(fila);
    free(contagemVerdes);
    free(contagemVermelhas);

    return 0;
}
