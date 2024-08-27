#include <stdio.h>
#include <stdlib.h>

typedef struct par {
  int primeiro;
  int segundo;
} par;

typedef par Item;

int comparar(Item a, Item b) {
  return a.primeiro == b.primeiro ? a.segundo < b.segundo : a.primeiro < b.primeiro; 
}

#define compararMerge(a, b) (a.segundo < b.segundo)
#define trocar(a, b)                                                         \
  Item temp = a;                                                                  \
  a = b;                                                                       \
  b = temp;

int particionar(Item *v, int esquerda, int direita) {
  int i = esquerda - 1;
  int j = direita;
  Item pivot = v[direita];
  for (;;) {
    while (comparar(v[++i], pivot));

    while (comparar(pivot, v[--j])) if(j == esquerda) break;

    if (i >= j)
      break;

    trocar(v[i], v[j]);
  }
  trocar(v[i], v[direita]);
  return i;
}

void selecaoRapida(Item *v, int esquerda, int direita, int k) {
  if(esquerda >= direita) return;

  int i = particionar(v, esquerda, direita);

  if (i > k)
    selecaoRapida(v, esquerda, i - 1, k);
  else if (i < k)
    selecaoRapida(v, i + 1, direita, k);
}

void merge(Item *v, int esquerda, int direita) {
    int meio = esquerda + (direita - esquerda) / 2;
    int pl = esquerda;
    int pr = meio + 1;
    int p = 0;
    Item *aux = malloc(sizeof(Item) * (direita - esquerda + 1));

    while(pl <= meio && pr <= direita) {
        if(compararMerge(v[pl], v[pr]))
            aux[p++] = v[pl++];
        else
            aux[p++] = v[pr++];
    }

    while(pl <= meio)
        aux[p++] = v[pl++];

    while(pr <= direita)
        aux[p++] = v[pr++];
    
    p = 0;
    for(int i = esquerda; i <= direita; ++i)
        v[i] = aux[p++];

    free(aux);
}

void ordenacaoMerge(Item *v, int esquerda, int direita) {
    if(esquerda >= direita) return;

    int meio = esquerda + (direita - esquerda) / 2;

    ordenacaoMerge(v, esquerda, meio);
    ordenacaoMerge(v, meio + 1, direita);

    merge(v, esquerda, direita);
}

int main(void) {
  int k;
  scanf("%d", &k);
  Item *elementos = malloc(sizeof(Item) * ((int)1e7 + 1));
  int cnt = 0;
  int n, s;
  while (scanf("%d %d", &s, &n) != EOF) {
    elementos[cnt].primeiro = n;
    elementos[cnt].segundo = s;
    cnt++;
  }

  selecaoRapida(elementos, 0, cnt - 1, k);
  ordenacaoMerge(elementos, 0, k - 1);

  for (int i = 0; i < k; ++i) {
    printf("%d %d\n", elementos[i].segundo, elementos[i].primeiro);
  }

  free(elementos);
  
  return 0;
}
