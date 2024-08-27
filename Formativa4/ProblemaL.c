#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} HeapMin;

HeapMin* criarHeapMin(int capacidade) {
    HeapMin* heap = (HeapMin*) malloc(sizeof(HeapMin));
    heap->dados = (int*) malloc(capacidade * sizeof(int));
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    return heap;
}

void trocar(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(HeapMin *heap, int idx) {
    int menor = idx;
    int esquerda = 2 * idx + 1;
    int direita = 2 * idx + 2;

    if (esquerda < heap->tamanho && heap->dados[esquerda] < heap->dados[menor])
        menor = esquerda;

    if (direita < heap->tamanho && heap->dados[direita] < heap->dados[menor])
        menor = direita;

    if (menor != idx) {
        trocar(&heap->dados[idx], &heap->dados[menor]);
        minHeapify(heap, menor);
    }
}

void inserirHeapMin(HeapMin *heap, int chave) {
    if (heap->tamanho == heap->capacidade) {
        heap->capacidade *= 2;
        heap->dados = (int*) realloc(heap->dados, heap->capacidade * sizeof(int));
    }
    heap->tamanho++;
    int i = heap->tamanho - 1;
    heap->dados[i] = chave;

    while (i != 0 && heap->dados[(i - 1) / 2] > heap->dados[i]) {
        trocar(&heap->dados[i], &heap->dados[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extrairMin(HeapMin *heap) {
    if (heap->tamanho <= 0)
        return INT_MAX;
    if (heap->tamanho == 1) {
        heap->tamanho--;
        return heap->dados[0];
    }

    int raiz = heap->dados[0];
    heap->dados[0] = heap->dados[heap->tamanho - 1];
    heap->tamanho--;
    minHeapify(heap, 0);

    return raiz;
}

typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} HeapMax;

HeapMax* criarHeapMax(int capacidade) {
    HeapMax* heap = (HeapMax*) malloc(sizeof(HeapMax));
    heap->dados = (int*) malloc(capacidade * sizeof(int));
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    return heap;
}

void maxHeapify(HeapMax *heap, int idx) {
    int maior = idx;
    int esquerda = 2 * idx + 1;
    int direita = 2 * idx + 2;

    if (esquerda < heap->tamanho && heap->dados[esquerda] > heap->dados[maior])
        maior = esquerda;

    if (direita < heap->tamanho && heap->dados[direita] > heap->dados[maior])
        maior = direita;

    if (maior != idx) {
        trocar(&heap->dados[idx], &heap->dados[maior]);
        maxHeapify(heap, maior);
    }
}

void inserirHeapMax(HeapMax *heap, int chave) {
    if (heap->tamanho == heap->capacidade) {
        heap->capacidade *= 2;
        heap->dados = (int*) realloc(heap->dados, heap->capacidade * sizeof(int));
    }
    heap->tamanho++;
    int i = heap->tamanho - 1;
    heap->dados[i] = chave;

    while (i != 0 && heap->dados[(i - 1) / 2] < heap->dados[i]) {
        trocar(&heap->dados[i], &heap->dados[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extrairMax(HeapMax *heap) {
    if (heap->tamanho <= 0)
        return INT_MIN;
    if (heap->tamanho == 1) {
        heap->tamanho--;
        return heap->dados[0];
    }

    int raiz = heap->dados[0];
    heap->dados[0] = heap->dados[heap->tamanho - 1];
    heap->tamanho--;
    maxHeapify(heap, 0);

    return raiz;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    HeapMin *tuboA = criarHeapMin(n);
    HeapMax *tuboB = criarHeapMax(n);
    int *combinacoes = (int*) malloc(n * sizeof(int));
    int contadorCombinacoes = 0;

    for (int i = 0; i < n; i++) {
        int densidade;
        scanf("%d", &densidade);
        inserirHeapMin(tuboA, densidade);
    }

    while (tuboA->tamanho > 0) {
        int minA = extrairMin(tuboA);
        if (tuboB->tamanho == 0) {
            inserirHeapMax(tuboB, minA);
        } else {
            int maxB = extrairMax(tuboB);
            if (abs(minA - maxB) <= k && abs(minA - maxB) > 0) {
                combinacoes[contadorCombinacoes++] = minA + maxB;
            } else {
                inserirHeapMax(tuboB, maxB);
                inserirHeapMax(tuboB, minA);
            }
        }
    }

    printf("%d\n", contadorCombinacoes);
    if (contadorCombinacoes > 0) {
        for (int i = 0; i < contadorCombinacoes; i++) {
            printf("%d ", combinacoes[i]);
        }
        printf("\n");
    }

    free(tuboA->dados);
    free(tuboB->dados);
    free(tuboA);
    free(tuboB);
    free(combinacoes);

    return 0;
}
