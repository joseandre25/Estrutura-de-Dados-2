#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void insere_inicio(celula *le, int x) {
    celula *nova_celula = (celula *)malloc(sizeof(celula));
    nova_celula->dado = x;
    nova_celula->prox = le->prox;
    le->prox = nova_celula;
}

void insere_antes(celula *le, int x, int y) {
    celula *atual = le;
    while (atual->prox != NULL && atual->prox->dado != y) {
        atual = atual->prox;
    }
    celula *nova_celula = (celula *)malloc(sizeof(celula));
    nova_celula->dado = x;
    nova_celula->prox = atual->prox;
    atual->prox = nova_celula;
}

