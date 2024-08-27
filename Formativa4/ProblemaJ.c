#include <stdio.h>
#include <stdlib.h>

#define MAX_N 5000

typedef struct no {
    int id;
    struct no *esq, *dir;
} no;

no* criar_no(int id) {
    no *novo = (no*)malloc(sizeof(no));
    novo->id = id;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Função auxiliar para verificar se a árvore é balanceada e calcular a altura
int verificar_balanceamento(no *r, int *balanceada) {
    if (r == NULL) {
        return 0;
    }

    int altura_esq = verificar_balanceamento(r->esq, balanceada);
    int altura_dir = verificar_balanceamento(r->dir, balanceada);

    if (abs(altura_esq - altura_dir) > 1) {
        *balanceada = 0;
    }

    return 1 + (altura_esq > altura_dir ? altura_esq : altura_dir);
}

int main() {
    int N;
    scanf("%d", &N);

    if (N == 1) {
        printf("Sim\n");
        return 0;
    }

    no* nos[MAX_N + 1];
    for (int i = 1; i <= N; i++) {
        nos[i] = criar_no(i);
    }

    for (int i = 2; i <= N; i++) {
        int pai;
        scanf("%d", &pai);
        if (nos[pai]->esq == NULL) {
            nos[pai]->esq = nos[i];
        } else {
            nos[pai]->dir = nos[i];
        }
    }

    int balanceada = 1;
    verificar_balanceamento(nos[1], &balanceada);

    if (balanceada) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    // Liberar memória (opcional)
    for (int i = 1; i <= N; i++) {
        free(nos[i]);
    }

    return 0;
}
