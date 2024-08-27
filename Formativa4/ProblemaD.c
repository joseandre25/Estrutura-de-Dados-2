#include <stdio.h>
#include <string.h>

void construirPosOrdem(char* pre, char* in, int tam, char* pos) {
    if (tam <= 0) {
        return;
    }

    // A raiz é sempre o primeiro elemento em pre
    char raiz = pre[0];
    
    // Encontra a raiz no percurso infixo
    int raizIndice;
    for (raizIndice = 0; raizIndice < tam; ++raizIndice) {
        if (in[raizIndice] == raiz) {
            break;
        }
    }

    // Recursivamente construir as sub-árvores esquerda e direita
    construirPosOrdem(pre + 1, in, raizIndice, pos); // Sub-árvore esquerda
    construirPosOrdem(pre + 1 + raizIndice, in + raizIndice + 1, tam - raizIndice - 1, pos + raizIndice); // Sub-árvore direita

    // Adiciona a raiz no final do percurso posfixo
    pos[tam - 1] = raiz;
}

int main() {
    int casos;
    scanf("%d", &casos);

    while (casos--) {
        int N;
        char pre[53], in[53], pos[53];
        
        scanf("%d %s %s", &N, pre, in);

        construirPosOrdem(pre, in, N, pos);
        pos[N] = '\0'; // Adiciona o terminador nulo ao final da string pos

        printf("%s\n", pos);
    }

    return 0;
}
