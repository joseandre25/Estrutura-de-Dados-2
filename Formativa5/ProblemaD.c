#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoArvore {
    char nome[50];
    unsigned id;
    struct NoArvore *esq;
    struct NoArvore *dir;
} NoArvore;

#define verdadeiro 1
#define falso 0
#define TAMANHO_MAX 310

char visitado[TAMANHO_MAX];
char adjacente[TAMANHO_MAX][TAMANHO_MAX];

void buscaProfundidade(const unsigned);
NoArvore *inserir(NoArvore *, char *);
int encontrar(NoArvore *, char *);

unsigned indice;
unsigned m, n;

int main(int argc, char **argv) {    
    int u, v, i, j;
    NoArvore *arvore = NULL;
    char nome1[50], nome2[50], conexao[50];
    
    scanf("%u %u", &m, &n);
    int tmp = n;
    while (tmp--) {
        scanf("%s %s %s", nome1, conexao, nome2);
        arvore = inserir(arvore, nome1);
        arvore = inserir(arvore, nome2);

        u = encontrar(arvore, nome1);
        v = encontrar(arvore, nome2);

        adjacente[u][v] = adjacente[v][u] = 1;    
    }

    int resposta = 0;

    for (i = 1; i <= m; ++i)
        if (!visitado[i])
            resposta++, buscaProfundidade(i);

    printf("%d\n", resposta);

    return 0;
}

void buscaProfundidade(const unsigned vertice) {
    unsigned i;
    visitado[vertice] = verdadeiro;
    for (i = 1; i <= m; ++i)
        if (adjacente[vertice][i])
            if (!visitado[i])
                buscaProfundidade(i);
}

NoArvore *inserir(NoArvore *arvore, char *str) {
    if (!arvore) {
        arvore = (NoArvore *)malloc(sizeof(NoArvore));
        arvore->esq = arvore->dir = NULL;
        strcpy(arvore->nome, str);
        arvore->id = ++indice;
    } else if (strcmp(arvore->nome, str) > 0)
        arvore->esq = inserir(arvore->esq, str);
    else if (strcmp(arvore->nome, str) < 0)
        arvore->dir = inserir(arvore->dir, str);
    
    return arvore;
}

int encontrar(NoArvore *arvore, char *str) {
    if (!arvore)
        return -1;
    
    if (strcmp(arvore->nome, str) > 0)
        return encontrar(arvore->esq, str);
    else if (strcmp(arvore->nome, str) < 0)
        return encontrar(arvore->dir, str);
    else
        return arvore->id;
}
