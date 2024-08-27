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

// Função de percurso em ordem não recursiva
void em_ordem(no *raiz) {
    pilha *p = NULL;
    no *atual = raiz;
    
    while (atual != NULL || !pilha_vazia(p)) {
        // Percorre até o nó mais à esquerda
        while (atual != NULL) {
            empilhar(&p, atual);
            atual = atual->esq;
        }
        
        // Desempilha o nó e processa
        atual = desempilhar(&p);
        printf("%d ", atual->dado);
        
        // Vai para o nó à direita
        atual = atual->dir;
    }
}
