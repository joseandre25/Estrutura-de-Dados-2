#include <stdio.h>
#include <stdlib.h>

#define minimo(a, b) (a < b ? a : b)
#define maximo(a, b) (b < a ? a : b)
#define Elemento int
#define chave(x) (x)
#define menor(a, b) (a > b)
#define trocar(a, b)  \
    {                 \
        Elemento temp = a; \
        a = b;        \
        b = temp;     \
    }
#define cmpTrocar(a, b) \
    if (menor(b, a))    \
    trocar(a, b)

Elemento ITEM_NULL = -1;

typedef struct
{
    Elemento *array;
    size_t tamanho, capacidade;
} FilaDePrioridade;

void HEAP_subir(Elemento *array, int indice)
{
    for (; indice > 1 && menor(array[indice / 2], array[indice]); indice /= 2)
        trocar(array[indice], array[indice / 2]);
}

void HEAP_descer(Elemento *array, size_t tamanho, int indice)
{
    for (int maior = indice * 2; indice * 2 <= tamanho; indice = maior, maior = indice * 2)
    {
        if (maior < tamanho && menor(array[maior], array[maior + 1]))
            maior++;

        if (!menor(array[indice], array[maior]))
            break;

        trocar(array[indice], array[maior]);
    }
}

FilaDePrioridade FP_iniciar(size_t capacidade)
{
    FilaDePrioridade fp = {.capacidade = capacidade, .tamanho = 0};
    fp.array = malloc((capacidade + 1) * sizeof(Elemento));
    return fp;
}

void FP_liberar(FilaDePrioridade fp)
{
    free(fp.array);
}

int FP_estaVazia(FilaDePrioridade fp)
{
    return fp.tamanho == 0;
}

void FP_garantirCapacidade(FilaDePrioridade *fp, size_t novaCapacidade)
{
    if (novaCapacidade <= fp->capacidade)
        return;

    fp->capacidade *= 4;
    fp->array = realloc(fp->array, (fp->capacidade + 1) * sizeof(Elemento));
}

void FP_inserir(FilaDePrioridade *fp, Elemento x)
{
    FP_garantirCapacidade(fp, fp->tamanho + 1);
    fp->array[++fp->tamanho] = x;
    HEAP_subir(fp->array, fp->tamanho);
}

Elemento FP_obterTopo(FilaDePrioridade fp)
{
    return fp.array[1];
}

Elemento FP_extrairTopo(FilaDePrioridade *fp)
{
    if (FP_estaVazia(*fp))
        return ITEM_NULL;

    Elemento topo = FP_obterTopo(*fp);
    fp->array[1] = fp->array[fp->tamanho--];
    HEAP_descer(fp->array, fp->tamanho, 1);
    return topo;
}

int main()
{
    FilaDePrioridade fp = FP_iniciar(16);
    int comando, valor, arrayAux[100];

    while (scanf(" %d %d", &comando, &valor) == 2)
    {
        if (comando == 1)
            FP_inserir(&fp, valor);
        else
        {
            int contador;
            for (contador = 0; contador < valor; contador++)
            {
                int topo = FP_extrairTopo(&fp);
                if (topo == ITEM_NULL)
                    break;
                arrayAux[contador] = topo;
            }
            for (int i = 0; i < contador; i++)
            {
                printf("%d%c", arrayAux[i], " \n"[i == contador-1]);
                FP_inserir(&fp, arrayAux[i]);
            }
        }
    }

    FP_liberar(fp);

    return 0;
}
