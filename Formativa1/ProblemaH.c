#include <stdio.h>
#include <string.h>

int main() {
    char escolha_sheldon[10], escolha_raj[10];
    
    scanf("%s %s", escolha_sheldon, escolha_raj);
    
    if (strcmp(escolha_sheldon, escolha_raj) == 0) {
        printf("De novo!\n");
    } else if ((strcmp(escolha_sheldon, "pedra") == 0 && strcmp(escolha_raj, "tesoura") == 0) ||
               (strcmp(escolha_sheldon, "tesoura") == 0 && strcmp(escolha_raj, "papel") == 0) ||
               (strcmp(escolha_sheldon, "papel") == 0 && strcmp(escolha_raj, "pedra") == 0) ||
               (strcmp(escolha_sheldon, "pedra") == 0 && strcmp(escolha_raj, "lagarto") == 0) ||
               (strcmp(escolha_sheldon, "lagarto") == 0 && strcmp(escolha_raj, "Spock") == 0) ||
               (strcmp(escolha_sheldon, "Spock") == 0 && strcmp(escolha_raj, "tesoura") == 0) ||
               (strcmp(escolha_sheldon, "tesoura") == 0 && strcmp(escolha_raj, "lagarto") == 0) ||
               (strcmp(escolha_sheldon, "lagarto") == 0 && strcmp(escolha_raj, "papel") == 0) ||
               (strcmp(escolha_sheldon, "papel") == 0 && strcmp(escolha_raj, "Spock") == 0) ||
               (strcmp(escolha_sheldon, "Spock") == 0 && strcmp(escolha_raj, "pedra") == 0)) {
        printf("Bazinga!\n");
    } else {
        printf("Raj trapaceou!\n");
    }
    
    return 0;
}
