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

// Função para encontrar o maior valor na sub-árvore esquerda (antecessor)
no* maximo(no *r) {
    while (r->dir != NULL) {
        r = r->dir;
    }
    return r;
}

// Função para remover um valor da árvore binária de busca
no* remover(no *r, int x) {
    if (r == NULL) {
        // A chave não está na árvore
        return NULL;
    }

    if (x < r->chave) {
        // Remover da sub-árvore esquerda
        r->esq = remover(r->esq, x);
    } else if (x > r->chave) {
        // Remover da sub-árvore direita
        r->dir = remover(r->dir, x);
    } else {
        // Encontrou o nó a ser removido
        if (r->esq == NULL) {
            // Nó com zero ou um filho (direito)
            no *temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            // Nó com um filho (esquerdo)
            no *temp = r->esq;
            free(r);
            return temp;
        }

        // Nó com dois filhos: pegar o antecessor (maior na sub-árvore esquerda)
        no *temp = maximo(r->esq);
        r->chave = temp->chave;
        r->esq = remover(r->esq, temp->chave);
    }
    return r;
}
void pre_ordem(no *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

