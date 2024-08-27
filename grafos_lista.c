#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int v;
    struct no *prox;
}no ;

typedef struct{
    no *adj;
    int n;
} grafo;

grafo *cria_grafo(int n){
    grafo *g = malloc(sizeof(grafo));
    g->adj = calloc(n, sizeof(no));
    g->n = n;
    return g;
}