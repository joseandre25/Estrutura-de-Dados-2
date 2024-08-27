#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

// Estrutura para armazenar o caractere e sua frequência
typedef struct {
    char character;
    int frequency;
} CharFrequency;

// Função de comparação para qsort
int compare(const void *a, const void *b) {
    CharFrequency *cf1 = (CharFrequency *)a;
    CharFrequency *cf2 = (CharFrequency *)b;
    if (cf1->frequency != cf2->frequency) {
        return cf1->frequency - cf2->frequency;
    } else {
        return cf1->character - cf2->character;
    }
}

int main() {
    char line[1001];
    int frequencies[MAX_CHARS];
    CharFrequency charFrequencies[MAX_CHARS];
    int isFirstLine = 1;

    while (fgets(line, sizeof(line), stdin)) {
        // Inicializa as frequências
        memset(frequencies, 0, sizeof(frequencies));

        // Conta as frequências dos caracteres na linha
        for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
            frequencies[(unsigned char)line[i]]++;
        }

        // Preenche a estrutura CharFrequency com os caracteres presentes e suas frequências
        int count = 0;
        for (int i = 0; i < MAX_CHARS; i++) {
            if (frequencies[i] > 0) {
                charFrequencies[count].character = i;
                charFrequencies[count].frequency = frequencies[i];
                count++;
            }
        }

        // Ordena a estrutura CharFrequency
        qsort(charFrequencies, count, sizeof(CharFrequency), compare);

        // Imprime o resultado
        if (!isFirstLine) {
            printf("\n");
        }
        isFirstLine = 0;
        for (int i = 0; i < count; i++) {
            printf("%d %d\n", charFrequencies[i].character, charFrequencies[i].frequency);
        }
    }

    printf("\n");
    return 0;
}
