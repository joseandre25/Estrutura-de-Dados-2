#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int vetor[N];
    double soma = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    double media = soma / N; 

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (vetor[i] > media) {
            printf("%d", vetor[i]);
            count++;
            if (count < N - 1) {
                printf(" ");
            }
        }
    }

    if (count == 0) {
        printf("0");
    }

    return 0;
}
