#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ** adj;
    int n;
} grafo;

grafo *cria_grafo(int n){
    grafo *g = malloc(sizeof(grafo));
    g->adj = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        g->adj[i] = malloc(n * sizeof(int));
    }
    g->n = n;
    return g;
}

void libera_grafo(grafo *g) {
    for (int i = 0; i < g->n; i++) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);
}

int main() {
    int n = 5; // Número de vértices
    grafo *g = cria_grafo(n);

    // Inicializa a matriz de adjacência com 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->adj[i][j] = 1;
        }
    }

    // Exemplo de impressão da matriz de adjacência
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }

    // Libera a memória do grafo
    libera_grafo(g);

    return 0;
}