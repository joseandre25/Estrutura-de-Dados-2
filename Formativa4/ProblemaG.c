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

int altura(no *r) {
    if (r == NULL) {
        return 0;
    } else {
        int altura_esq = altura(r->esq);
        int altura_dir = altura(r->dir);
        return 1 + (altura_esq > altura_dir ? altura_esq : altura_dir);
    }
}

