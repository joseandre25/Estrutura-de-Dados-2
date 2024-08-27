#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no* criar_no(int chave) {
    no *novo = (no*)malloc(sizeof(no));
    novo->chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

no* minimo(no *r) {
    if (r == NULL) {
        return NULL;
    }
    while (r->esq != NULL) {
        r = r->esq;
    }

    return r;
}

