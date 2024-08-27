#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
    celula *p1 = l1->prox; 
    celula *p2 = l2->prox;
    celula *p3 = l3;      

    while (p1 != NULL && p2 != NULL) {
        if (p1->dado <= p2->dado) {
            p3->prox = p1;
            p1 = p1->prox;
        } else {
            p3->prox = p2;
            p2 = p2->prox;
        }
        p3 = p3->prox;
    }

    while (p1 != NULL) {
        p3->prox = p1;
        p1 = p1->prox;
        p3 = p3->prox;
    }

    while (p2 != NULL) {
        p3->prox = p2;
        p2 = p2->prox;
        p3 = p3->prox;
    }

    p3->prox = NULL;
}

celula *criar_no(int dado) {
    celula *novo = (celula *)malloc(sizeof(celula));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(EXIT_FAILURE);
    }
    novo->dado = dado;
    novo->prox = NULL;
    return novo;
}

void inserir_em_ordem(celula *cabeca, int valor) {
    celula *atual = cabeca;
    while (atual->prox != NULL && atual->prox->dado <= valor) {
        atual = atual->prox;
    }
    celula *novo = criar_no(valor);
    novo->prox = atual->prox;
    atual->prox = novo;
}

void imprimir_lista(celula *cabeca) {
    celula *atual = cabeca->prox;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

