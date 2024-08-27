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

// Função de percurso pré-ordem não recursiva
void pre_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }
    
    pilha *p = NULL;
    empilhar(&p, raiz);
    
    while (!pilha_vazia(p)) {
        no *atual = desempilhar(&p);
        printf("%d ", atual->dado);
        
        if (atual->dir != NULL) {
            empilhar(&p, atual->dir);
        }
        
        if (atual->esq != NULL) {
            empilhar(&p, atual->esq);
        }
    }
}
