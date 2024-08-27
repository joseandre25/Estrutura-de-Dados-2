#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABELA_HASH (1 << 20)

typedef struct Item {
    long long id;
    int quantidade;
    struct Item* proximo;
} Item;

Item* tabela_hash[TAMANHO_TABELA_HASH] = { NULL };

unsigned long hash(long long id) {
    return (unsigned long)(id) % TAMANHO_TABELA_HASH;
}

void adicionar_item(long long id, int quantidade) {
    unsigned long indice = hash(id);
    Item* atual = tabela_hash[indice];
    Item* anterior = NULL;

    while (atual) {
        if (atual->id == id) {
            atual->quantidade += quantidade;
            if (atual->quantidade <= 0) {
                if (anterior) {
                    anterior->proximo = atual->proximo;
                } else {
                    tabela_hash[indice] = atual->proximo;
                }
                free(atual);
            }
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    if (quantidade > 0) {
        Item* novo_item = (Item*)malloc(sizeof(Item));
        novo_item->id = id;
        novo_item->quantidade = quantidade;
        novo_item->proximo = tabela_hash[indice];
        tabela_hash[indice] = novo_item;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        long long id;
        int quantidade;
        scanf("%lld %d", &id, &quantidade);
        adicionar_item(id, quantidade);
    }

    long long quantidade_total = 0;

    for (int i = 0; i < TAMANHO_TABELA_HASH; i++) {
        Item* atual = tabela_hash[i];
        while (atual) {
            quantidade_total += atual->quantidade;
            atual = atual->proximo;
        }
    }

    printf("%lld\n", quantidade_total);

    for (int i = 0; i < TAMANHO_TABELA_HASH; i++) {
        Item* atual = tabela_hash[i];
        while (atual) {
            Item* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }

    return 0;
}