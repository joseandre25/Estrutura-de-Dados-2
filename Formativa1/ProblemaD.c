#include <stdio.h>
#include <string.h>

int trocar_letra(char caractere)
{
    if (caractere >= 'A' || caractere <= 'T')
    {
        return caractere - 'A';
    }
}

char trocar_caractere(int numero)
{
    if (numero >= 0 && numero <= 19)
    {
        return 'A' + numero;
    }
}

int main()
{
    int f, l, num, num_caractere;
    char caractere = ' ';
    scanf("%d %d\n", &f, &l);
    printf("  ");

    char cinema[f][l][3];

    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < l; j++)
        {
            strcpy(cinema[i][j], "--");
        }
    }

    while (scanf(" %c %d", &caractere, &num) != EOF)
    {
        num_caractere = trocar_letra(caractere);
        strcpy(cinema[num_caractere][num - 1], "XX");
    }

    printf("  ");
    for (int j = 0; j < l; j++)
    {
        printf("%02d  ", j + 1);
    }
    puts("");
    for (int i = f - 1; i >= 0; i--)
    {
        char num_linha = trocar_caractere(i);
        printf("%c", num_linha);
        for (int j = 0; j < l; j++)
        {
            printf(" %s ", cinema[i][j]);
        }
        puts("");
    }

    return 0;
}
