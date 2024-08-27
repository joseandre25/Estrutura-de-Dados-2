#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 15
#define MAX_INSTRUCOES 10000

typedef struct {
    int codigo;
    char palavra_chave[MAX_LENGTH + 1]; 
} Instrucao;

int comparar(const void *a, const void *b) {
    return ((Instrucao*)a)->codigo - ((Instrucao*)b)->codigo;
}

void buscar_e_imprimir(const Instrucao instrucoes[], int n, int codigo) {
    int inicio = 0, fim = n - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (instrucoes[meio].codigo == codigo) {
            printf("%s\n", instrucoes[meio].palavra_chave);
            return;
        } else if (instrucoes[meio].codigo < codigo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    printf("undefined\n");
}

int main() {
    int n;
    scanf("%d", &n);

    Instrucao instrucoes[MAX_INSTRUCOES];
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &instrucoes[i].codigo, instrucoes[i].palavra_chave);
    }

    qsort(instrucoes, n, sizeof(Instrucao), comparar);

    int codigo;
    while (scanf("%d", &codigo) != EOF) {
        buscar_e_imprimir(instrucoes, n, codigo);
    }

    return 0;
}
