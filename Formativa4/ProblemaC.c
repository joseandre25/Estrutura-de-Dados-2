#include <stdio.h>
#include <stdlib.h>

// Definição da struct no
typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

// Definição da struct pilha
typedef struct pilha {
    no *nodo;
    struct pilha *prox;
} pilha;

// Função para criar um novo nó
no* criar_no(int dado) {
    no *novo = (no*)malloc(sizeof(no));
    novo->dado = dado;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Função para empilhar um nó
void empilhar(pilha **topo, no *nodo) {
    pilha *novo = (pilha*)malloc(sizeof(pilha));
    novo->nodo = nodo;
    novo->prox = *topo;
    *topo = novo;
}

// Função para desempilhar um nó
no* desempilhar(pilha **topo) {
    if (*topo == NULL) {
        return NULL;
    }
    pilha *temp = *topo;
    no *nodo = temp->nodo;
    *topo = (*topo)->prox;
    free(temp);
    return nodo;
}

// Função para verificar se a pilha está vazia
int pilha_vazia(pilha *topo) {
    return topo == NULL;
}

// Função de percurso pós-ordem não recursiva
void pos_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }

    pilha *pilha1 = NULL;
    pilha *pilha2 = NULL;
    empilhar(&pilha1, raiz);

    while (!pilha_vazia(pilha1)) {
        no *atual = desempilhar(&pilha1);
        empilhar(&pilha2, atual);

        if (atual->esq != NULL) {
            empilhar(&pilha1, atual->esq);
        }

        if (atual->dir != NULL) {
            empilhar(&pilha1, atual->dir);
        }
    }

    while (!pilha_vazia(pilha2)) {
        no *atual = desempilhar(&pilha2);
        printf("%d ", atual->dado);
    }
}

