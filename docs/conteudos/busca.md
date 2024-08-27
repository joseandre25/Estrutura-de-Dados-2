## O problema de busca

Consiste em determinar se um elemento X pertence ou não a um determinado conjunto.

- Suponha que temos:
-> Um conjunto universo com S elementos.
-> Um conjunto de dados com N elementos.
-> Deseja-se realizar M consultas.

# 1º Busca Sequencial

`int busca(int *V, int n, int x){
    for(int i=o, i<n, i++){
        if(v[i] == x) return 1;
    }
    return 0;
}`

Considerando que queremos realizar M consultas, o custo total é m . O(n) = O(m.n).

# 2º Busca Binária 

int buscaBinaria(int array[], int tamanho, int chave)
{
    int inicio = 0, i = 0, fim = tamanho - 1;

    do
    {
        int meio = (inicio + fim) / 2;
        if (array[meio] == chave)
        {
            return meio;
        }
        else if (array[meio] < chave)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    } while (inicio <= fim && chave != array[i]);
    return -1;
}

Premissa: O conjunto precisa estar ordenado.

Para realizar M consultas:
1 - Ordenar v. O(n lgn)
2 - Aplicar M buscas binárias. (M.O(lg n))

Logo, o custo total é O(n lg n) + M . O(lg n) = O((n + m) lg n)

// Se M for constante, a busca binária não compensa pelo custo da ordenação

- Até o momento, 1º compensa se m for O(1). Se m for O(lg n) são similares. Demais casos, 2º é mais rápido.

# 3º Endereçamento Direto

- 1: Uso um vetor V auxiliar de 0s e 1s de tamanho S. (Geralmente de char)
- 2: Para cada elemento y do conjunto, marco V[y - offset] como sendo 1, os demais 0.
(offset geralmente será o menor elemento do conjunto universo)

int busca(char *v, int x){
    return V[x - offset];
    // if(V[x - offset] == 1){
    //  elemento estará presente
    // }
}

- Considerando m buscas, o custo é O(m). // + O(S) de memória auxiliar (esse é o ônus)
- Quando usar? quando ela é viável e temos a disposição de gastar o espaço de memória
- Não é viável quando o conjunto S é infinito ou quando o espaço de memória é muito grande

# 4º Tabela de Dispersão (Tab. Hash)

- Cada chave é mapeada em uma tabela (vetor ou lista encadeada), cuja posição é determinada por uma função de espalhamento (função hash).
- A ideia é que o tamanho da tabela seja menor que s. Nesse caso, pode ocorrer uma **colisão**, ou seja, duas chaves distintas serem mapeadas para a mesma posição na tabela. -> Se tiver muitas colisões, estará indo para a busca sequencial.
- A ideia é que a quantidade de colisões seja constante.

*Endereçamento Direto é um caso especial de Tabela Hash.*
