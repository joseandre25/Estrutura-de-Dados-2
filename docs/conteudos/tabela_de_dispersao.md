## Tabelas de Dispersão (Hashing)

- conj. universo de tam. S
- conj. de dados de tam. N

#### Construir uma tabela de tamanho T < S.

- *colisão:* duas chaves ocupam a mesma posição na tabela: hash(x) = hash(y), x != y.
- *função de espalhamento:* dada uma chave x, a posição na tabela será hash(x). hash: U -> {0,...,T-1}<br>

Boas escolhas para T: números primos, preferencialmente bem maior que n. <br>
Primos de Mersenne: 2^n - 1

#### Para implementar tabelas hash, precisamos de:

- 1: Uma forma de armazenamento da tabela.
- 2: Uma função de espalhamento.
- 3: Um método para lidar com colisões.

##### Função de espalhamento

A função hash ideal preencheria toda a tabela sem colisões. A primeira colisão aconteceria apenas quando N > T.

- Hash universal uniforme

A função hash mais comum segue o método da divisão:

```
int hash(int x){
    return x % T;
}
```

- 1) Encadeamento Separado <br>
Dado um vetor de loista encadeada de tamanho T-1 <br>

Seja o tamanho 13, onde inserir o elemento 13?

13 % 13 = 0, posição 0.
E o elemento 26? -> 26 entrará na posição 0, na cabeça da lista encadeada, colocando o 13 no fim. 
Por que fazer isso? Porque inserir na cabeça é mais barato: O(1).

##### Implementação

```
typedef struct no{
    int dado;
    struct no *prox;
}no;

typedef struct{
    no *tab;                // Tabela + Tamanho
    int T;
}TH;


void cria_tabela(TH *h, int T);
void destroi_tabela(TH *h);
void insere(TH *h, int x);
void remove(TH *h, int x);
int busca(TH *h, int x);
```

- Busca
```
int busca(TH *h, int x){
    no *p = h->tab[hash(x)]->prox;
    while(p != null){
        if(p->dado === x) return 1;
        p = p->prox;    
        }
    return 0;
}
```
Complexidade: <br>
--> Pior Caso: O(n). Acontece quando há muitas colisões (chaves na mesma posição). <br>
--> Caso Médio: O(n/T) ou O(X), onde X é o maior número de colisões na tabela.

Portanto, uma boa implementação de hash consiste em limitar o *total de colisões*. Isso pode ser feito: <br>
- Escolhedo uma função hash ótimo (pode exigir conhecimento sobre o conj. de dados) <br>
- Limitar as colisões na inserção (consequentemente podemos ter tabela cheia).

- 2) Encadeamento Aberto <br>
Consiste no uso de *vetores* para implementar tabelas hash. <br>
Para resolução de colisões, há algumas técnicas, dentre as quais a mais comum chama-se *sondagem linear:* se houver colisão, procura-se pela próxima "posição livre" no vetor.<br>
Posição Livre = Posição que não há valor significativo. <br>
Vai ser boa quando a tabela for *esparsa* (Esparso é quando há "muitos" elementos vazios).<br>

*Densidade* é a porcentagem de elementos não-vazios do vetor. <br>

```Densidade = qtd de elementos nao vazios / tamanho da tabela``` <br>
Quando uma matriz/vetor é esparsa? Quando a densidade <= 0,3 (30)%<br>

Na prática, quando a tabela hash atingir uma densidade D < 1, podemos resimensioná-la.
Uma boa é dobrar o tamanho. <br>
Ao redimensionar, é necessário reinserir os elementos (pois T muda e, consequenetemente, a função hash).

O bizu nesse método de enderaçamento é sempre manter o vetor esparso.

- *Inserção*
pos = hash(ch);
while(V[pos] != -1) pos = (pos+1) % T; // while(V[pos] != -1) pode-se verificar a existência da chave se for o caso.
V[pos] = ch;

- *Busca*
pos = hash(ch);
while(V[pos] != -1 && V[pos] != ch) pos = (pos+1) % T;
if(V[pos] == ch) return pos;
return -1;

- *Remoção*
pos = busca(ch);
if(pos>=0){
    V[pos] = -1;
    pos = (pos+1) % T;
    while(V[pos] != -1){
        int elemen = V[pos];
        V[pos] = -1;
        insere(elem);
        pos = (pos+1) % T;
    }
}

Na remoção temos duas opções:
-> Remove e marca como disponível mas não vazia.
-> Reinserir na hash todos os elementos à direita até encontrar vazio.

##### Comentários
A Tabela Hash é a união do enderaçemento direto com a busca sequencial.