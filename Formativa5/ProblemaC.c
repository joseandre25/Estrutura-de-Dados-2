#include <stdio.h>
#include <stdbool.h>

bool explorarMapa(char mapa[100][100], int largura, int altura) {
    int x = 0, y = 0;
    bool visitado[100][100] = {false};

    while (x >= 0 && x < largura && y >= 0 && y < altura) {
        if (visitado[y][x]) return false;
        visitado[y][x] = true;

        switch (mapa[y][x]) {
            case '>': x++; break;
            case '<': x--; break;
            case 'v': y++; break;
            case '^': y--; break;
            case '*': return true;
            case '.': break;
            default: return false;
        }
    }
    return false;
}

int main() {
    int largura, altura;
    scanf("%d %d", &largura, &altura);
    char mapa[100][100];

    for (int i = 0; i < altura; i++) {
        scanf("%s", mapa[i]);
    }

    if (explorarMapa(mapa, largura, altura)) {
        printf("*\n");
    } else {
        printf("!\n");
    }
    return 0;
}
