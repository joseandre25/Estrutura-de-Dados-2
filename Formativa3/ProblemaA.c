#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista encadeada
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// inicializar um novo nó da lista encadeada
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->next = NULL;
    return node;
}

// inserir um elemento na tabela hash usando encadeamento exterior
void insert(int key, Node** hashTable, int tableSize) {
    int index = key % tableSize;
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode(key);
    } else {
        Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode(key);
    }
}

// imprimir a tabela hash
void printHashTable(Node** hashTable, int tableSize) {
    for (int i = 0; i < tableSize; i++) {
        printf("%d -> ", i);
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("\\\n");
    }
}

int main() {
    int N; // Quantidade de casos de teste
    scanf("%d", &N);

    while (N--) {
        int M, C; // M: quantidade de endereços-base, C: quantidade de chaves
        scanf("%d %d", &M, &C);

        
        Node** hashTable = (Node**)malloc(M * sizeof(Node*));
        for (int i = 0; i < M; i++) {
            hashTable[i] = NULL;
        }

        
        for (int i = 0; i < C; i++) {
            int key;
            scanf("%d", &key);
            insert(key, hashTable, M);
        }

        
        printHashTable(hashTable, M);
        printf("\n");

        
        for (int i = 0; i < M; i++) {
            Node* temp = hashTable[i];
            while (temp != NULL) {
                Node* next = temp->next;
                free(temp);
                temp = next;
            }
        }
        free(hashTable);
    }

    return 0;
}
