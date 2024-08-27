#include <stdio.h>

int main() {

    //1 (Norte), 2 (Sul), 3 (Leste) e 4 (Oeste). O professor PA inicia seu trajeto sempre 
    //na posição (1,1) e o professor PB na posição (N,M).
    int N, M, P;
    scanf("%d %d", &N, &M);
    scanf("%d", &P);

    int PA_x = 1, PA_y = 1; 
    int PB_x = N, PB_y = M; 

    int i;
    for (i = 1; i <= P; i++) {
        int A, B;
        scanf("%d %d", &A, &B);

        switch (A) {
            case 1: 
                PA_y++;
                break;
            case 2: 
                PA_y--;
                break;
            case 3:
                PA_x++;
                break;
            case 4:
                PA_x--;
                break;
        }

        switch (B) {
            case 1: 
                PB_y++;
                break;
            case 2: 
                PB_y--;
                break;
            case 3: 
                PB_x++;
                break;
            case 4: 
                PB_x--;
                break;
        }

        if (PA_x == PB_x && PA_y == PB_y) {
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", PA_x, PA_y, i);
            return 0;
        }
        if (PA_x < 1 || PA_x > N || PA_y < 1 || PA_y > M) {
            printf("PA saiu na posicao (%d,%d) no passo %d\n", PA_x, PA_y, i);
            return 0;
        }
        if (PB_x < 1 || PB_x > N || PB_y < 1 || PB_y > M) {
            printf("PB saiu na posicao (%d,%d) no passo %d\n", PB_x, PB_y, i);
            return 0;
        }
    }

    printf("Nao se encontraram\n");

    return 0;
}

