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

no* inserir(no *r, int x) {
    if (r == NULL) {
        return criar_no(x);
    }

    if (x < r->chave) {
        r->esq = inserir(r->esq, x);
    } else if (x > r->chave) {
        r->dir = inserir(r->dir, x);
    }
    // Se x é igual a r->chave, não inserir (chaves duplicadas não permitidas)

    return r;
}

void pre_ordem(no *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

