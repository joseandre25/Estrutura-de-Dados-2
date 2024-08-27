#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 65536

typedef struct Node {
    char word[21];
    int occurrence;
    struct Node* next;
} Node;

unsigned int hash_function(const char* word) {
    unsigned int hash = 0;
    while (*word != '\0') {
        hash = (hash * 31) + *word++;
    }
    return hash % TABLE_SIZE;
}

Node* create_node(const char* word) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Erro: Não foi possível alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_node->word, word);
    new_node->occurrence = 0;
    new_node->next = NULL;
    return new_node;
}

void insert_or_update(Node* hash_table[], const char* word, int command) {
    unsigned int index = hash_function(word);
    Node* current = hash_table[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            if (command == 1) {
                current->occurrence++;
            } else if (command == 3) {
                current->occurrence = 0;
            }
            return;
        }
        current = current->next;
    }
    Node* new_node = create_node(word);
    if (command == 1) {
        new_node->occurrence++;
    }
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

int count_occurrences(Node* hash_table[], const char* word) {
    unsigned int index = hash_function(word);
    Node* current = hash_table[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current->occurrence;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    Node* hash_table[TABLE_SIZE] = {NULL};

    int command;
    char word[21];
    while (scanf("%d %s", &command, word) != EOF) {
        if (command == 1 || command == 3) {
            insert_or_update(hash_table, word, command);
        } else if (command == 2) {
            int occurrences = count_occurrences(hash_table, word);
            printf("%d\n", occurrences);
        }
    }

    return 0;
}
