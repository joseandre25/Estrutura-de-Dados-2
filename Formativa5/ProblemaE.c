#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000

typedef struct {
    int *itens;
    int frente;
    int tras;
    int capacidade;
} Fila;

void inicializarFila(Fila *f, int n) {
    f->itens = (int *)malloc(n * sizeof(int));
    f->frente = 0;
    f->tras = -1;
    f->capacidade = n;
}

int estaVazia(Fila *f) {
    return f->frente > f->tras;
}

void enfileirar(Fila *f, int valor) {
    f->itens[++f->tras] = valor;
}

int desenfileirar(Fila *f) {
    return f->itens[f->frente++];
}

void liberarFila(Fila *f) {
    free(f->itens);
}

void bfs(int inicio, int **listaAdj, int *tamAdj, int *visitado, int *resultado_or) {
    Fila f;
    inicializarFila(&f, MAX_N);
    enfileirar(&f, inicio);
    visitado[inicio] = 1;
    *resultado_or = inicio;

    while (!estaVazia(&f)) {
        int no = desenfileirar(&f);
        for (int i = 0; i < tamAdj[no]; i++) {
            int vizinho = listaAdj[no][i];
            if (!visitado[vizinho]) {
                enfileirar(&f, vizinho);
                visitado[vizinho] = 1;
                *resultado_or |= vizinho;
            }
        }
    }

    liberarFila(&f);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **listaAdj = (int **)malloc((n + 1) * sizeof(int *));
    int *tamAdj = (int *)calloc(n + 1, sizeof(int));
    int *capacidadeAdj = (int *)malloc((n + 1) * sizeof(int));
    int visitado[MAX_N] = {0};

    for (int i = 0; i <= n; i++) {
        capacidadeAdj[i] = 2;
        listaAdj[i] = (int *)malloc(capacidadeAdj[i] * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (tamAdj[u] == capacidadeAdj[u]) {
            capacidadeAdj[u] *= 2;
            listaAdj[u] = (int *)realloc(listaAdj[u], capacidadeAdj[u] * sizeof(int));
        }
        listaAdj[u][tamAdj[u]++] = v;

        if (tamAdj[v] == capacidadeAdj[v]) {
            capacidadeAdj[v] *= 2;
            listaAdj[v] = (int *)realloc(listaAdj[v], capacidadeAdj[v] * sizeof(int));
        }
        listaAdj[v][tamAdj[v]++] = u;
    }

    int total_xor = 0;

    for (int i = 1; i <= n; i++) {
        if (!visitado[i]) {
            int resultado_or = 0;
            bfs(i, listaAdj, tamAdj, visitado, &resultado_or);
            total_xor ^= resultado_or;
        }
    }

    printf("%d\n", total_xor);

    for (int i = 0; i <= n; i++) {
        free(listaAdj[i]);
    }
    free(listaAdj);
    free(tamAdj);
    free(capacidadeAdj);

    return 0;
}
