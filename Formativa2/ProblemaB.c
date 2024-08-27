#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float value;
    int member;
    int problem;
} Problem;

int compare(const void *a, const void *b) {
    Problem *problemA = (Problem *)a;
    Problem *problemB = (Problem *)b;

    if (problemA->value == problemB->value) {
        if (problemA->member == problemB->member)
            return problemA->problem - problemB->problem;
        else
            return problemA->member - problemB->member;
    } else {
        return (problemB->value - problemA->value) > 0 ? 1 : -1;
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int M, N;
        scanf("%d %d", &M, &N);

        Problem problems[M * N];

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%f", &problems[i * N + j].value);
                problems[i * N + j].member = i + 1;
                problems[i * N + j].problem = j + 1;
            }
        }

        qsort(problems, M * N, sizeof(Problem), compare);

        for (int i = 0; i < M * N; i++) {
            printf("%d,%d", problems[i].member, problems[i].problem);
            if (i != M * N - 1)
                printf(" ");
        }

        printf("\n");
    }

    return 0;
}
