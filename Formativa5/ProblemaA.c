#include <stdio.h>
#include <stdlib.h>

#define MAX_N 2000
#define MAX_J 1000000

int n, m, j;
int visitado[MAX_N];
int adj[MAX_N][MAX_N];
int grau[MAX_N];
int fila[MAX_N];
int frente, tras;

void bfs() {
    while (frente != tras) {
        int atual = fila[frente++];
        for (int i = 0; i < grau[atual]; i++) {
            int vizinho = adj[atual][i];
            if (!visitado[vizinho]) {
                visitado[vizinho] = 1;
                fila[tras++] = vizinho;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &j);

    // Inicializa grau de cada nó
    for (int i = 0; i < n; i++) {
        grau[i] = 0;
    }

    // Lê as adjacências
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        for (int k = 0; k < a; k++) {
            int vizinho;
            scanf("%d", &vizinho);
            adj[i][grau[i]++] = vizinho;
        }
    }

    // Marca locais onde Juliano já esteve
    frente = tras = 0;
    for (int i = 0; i < m; i++) {
        int local;
        scanf("%d", &local);
        if (!visitado[local]) {
            visitado[local] = 1;
            fila[tras++] = local;
        }
    }

    // Executa a BFS para marcar todos os locais alcançáveis por Juliano
    bfs();

    // Responde as perguntas
    for (int i = 0; i < j; i++) {
        int consulta;
        scanf("%d", &consulta);
        if (visitado[consulta]) {
            printf("Eu vou estar la\n");
        } else {
            printf("Nao vou estar la\n");
        }
    }

    return 0;
}
