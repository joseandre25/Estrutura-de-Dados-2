#include <stdio.h>
#include <stdlib.h>

#define MAX_TEST_CASES 16

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int **matriz = malloc(MAX_TEST_CASES / 2 * sizeof(int *)); 
    int *vetorSubmissoes = malloc(MAX_TEST_CASES / 2 * sizeof(int)); 

    int totalSubmissoes = 0;
    for (int i = 0; i < MAX_TEST_CASES / 2; i++) {
        int submissoes;
        scanf("%d", &submissoes);
        vetorSubmissoes[i] = submissoes;
        totalSubmissoes += submissoes;
        matriz[i] = malloc(submissoes * sizeof(int));
        for (int j = 0; j < submissoes; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }


    int *vOrdenado = malloc(totalSubmissoes * sizeof(int));
    int idx = 0;
    for (int i = 0; i < MAX_TEST_CASES / 2; i++) {
        for (int j = 0; j < vetorSubmissoes[i]; j++) {
            vOrdenado[idx++] = matriz[i][j];
        }
        free(matriz[i]);
    }
    free(matriz); 


    qsort(vOrdenado, totalSubmissoes, sizeof(int), comparar);

    for (int i = 0; i < totalSubmissoes; i++) {
        printf("%d ", vOrdenado[i]);
    }
    printf("\n");

    free(vOrdenado);
    free(vetorSubmissoes);

    return 0;
}