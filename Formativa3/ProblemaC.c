#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 11
#define HASH_TABLE_SIZE 292399

long int duplicate_keys[HASH_TABLE_SIZE * 20];
int duplicate_key_index = 0;

unsigned int hash_function(long int key) {
    double A = 0.6180339887;
    double temp = key * A;
    temp -= (unsigned int)temp;
    return (unsigned int)(HASH_TABLE_SIZE * temp);
}

typedef struct Node {
    long int key;
    char strings[15][MAX_STRING_LEN];
    struct Node* next;
} Node;

Node* create_node(long int key) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Erro: Não foi possível alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
    new_node->key = key;
    for (int i = 0; i < 10; i++) {
        strcpy(new_node->strings[i], "");
    }
    new_node->next = NULL;
    return new_node;
}

void insert(Node* hash_table[], long int key, const char* string) {
    unsigned int index = hash_function(key);
    Node* current = hash_table[index];
    while (current != NULL) {
        if (current->key == key) {
            for (int i = 0; i < 15; i++) {
                if (strcmp(current->strings[i], string) == 0) {
                    duplicate_keys[duplicate_key_index++] = key;
                    return;
                }
            }
            for (int i = 0; i < 15; i++) {
                if (strcmp(current->strings[i], "") == 0) {
                    strcpy(current->strings[i], string);
                    return;
                }
            }
            printf("Erro: Não há espaço suficiente para inserir mais strings.\n");
            return;
        }
        current = current->next;
    }

    Node* new_node = create_node(key);
    strcpy(new_node->strings[0], string);
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

int main() {
    Node* hash_table[HASH_TABLE_SIZE] = {NULL};
    long int key;
    char string[MAX_STRING_LEN];
    while (scanf("%ld %s", &key, string) != EOF) {
        insert(hash_table, key, string);
    }
    for (int i = 0; i < duplicate_key_index; i++) {
        printf("%ld\n", duplicate_keys[i]);
    }
    return 0;
}
