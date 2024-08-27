#include <stdio.h>
#include <stdlib.h>

// Definição da struct no
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função para criar um novo nó
no* criar_no(int chave) {
    no *novo = (no*)malloc(sizeof(no));
    novo->chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Função para encontrar o valor máximo na árvore binária de busca
no* maximo(no *r) {
    if (r == NULL) {
        return NULL;
    }

    // Percorrer à direita até encontrar o último nó
    while (r->dir != NULL) {
        r = r->dir;
    }

    return r;
}
