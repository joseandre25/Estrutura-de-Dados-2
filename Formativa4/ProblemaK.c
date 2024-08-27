#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo
{
  char chave[11];
  struct Nodo *esquerda;
  struct Nodo *direita;
} Nodo;

typedef struct Formiga
{
  long long identificador;
  Nodo *chaves;
  struct Formiga *esquerda;
  struct Formiga *direita;
} Formiga;

int calculaHash(long long identificador, int tamanho)
{
  return abs(identificador) % tamanho;
}

Nodo *criaNodo(const char *chave)
{
  Nodo *novoNodo = (Nodo *)malloc(sizeof(Nodo));
  strcpy(novoNodo->chave, chave);
  novoNodo->esquerda = novoNodo->direita = NULL;
  return novoNodo;
}

Formiga *criaFormiga(long long identificador)
{
  Formiga *novaFormiga = (Formiga *)malloc(sizeof(Formiga));
  novaFormiga->identificador = identificador;
  novaFormiga->chaves = NULL;
  novaFormiga->esquerda = novaFormiga->direita = NULL;
  return novaFormiga;
}

Nodo *insereArvore(Nodo *raiz, const char *chave)
{
  if (raiz == NULL)
  {
    return criaNodo(chave);
  }
  if (strcmp(chave, raiz->chave) < 0)
  {
    raiz->esquerda = insereArvore(raiz->esquerda, chave);
  }
  else if (strcmp(chave, raiz->chave) > 0)
  {
    raiz->direita = insereArvore(raiz->direita, chave);
  }
  return raiz;
}

int chaveExiste(Nodo *raiz, const char *chave)
{
  if (raiz == NULL)
  {
    return 0;
  }
  int comparacao = strcmp(chave, raiz->chave);
  if (comparacao == 0)
  {
    return 1;
  }
  else if (comparacao < 0)
  {
    return chaveExiste(raiz->esquerda, chave);
  }
  else
  {
    return chaveExiste(raiz->direita, chave);
  }
}

Formiga *insereFormiga(Formiga *raiz, long long identificador)
{
  if (raiz == NULL)
  {
    return criaFormiga(identificador);
  }
  if (identificador < raiz->identificador)
  {
    raiz->esquerda = insereFormiga(raiz->esquerda, identificador);
  }
  else if (identificador > raiz->identificador)
  {
    raiz->direita = insereFormiga(raiz->direita, identificador);
  }
  return raiz;
}

Formiga *encontraFormiga(Formiga *raiz, long long identificador)
{
  if (raiz == NULL || raiz->identificador == identificador)
  {
    return raiz;
  }
  if (identificador < raiz->identificador)
  {
    return encontraFormiga(raiz->esquerda, identificador);
  }
  else
  {
    return encontraFormiga(raiz->direita, identificador);
  }
}

void gerenciaChaves(Formiga **tabelaHash, int tamanho, long long identificador, const char *chave)
{
  int indice = calculaHash(identificador, tamanho);
  if (tabelaHash[indice] == NULL)
  {
    tabelaHash[indice] = criaFormiga(identificador);
  }

  Formiga *formigaAtual = encontraFormiga(tabelaHash[indice], identificador);
  if (formigaAtual == NULL)
  {
    tabelaHash[indice] = insereFormiga(tabelaHash[indice], identificador);
    formigaAtual = encontraFormiga(tabelaHash[indice], identificador);
  }

  if (chaveExiste(formigaAtual->chaves, chave))
  {
    printf("%lld\n", identificador);
  }
  else
  {
    formigaAtual->chaves = insereArvore(formigaAtual->chaves, chave);
  }
}

void liberaArvoreNodos(Nodo *raiz)
{
  if (raiz == NULL)
  {
    return;
  }
  liberaArvoreNodos(raiz->esquerda);
  liberaArvoreNodos(raiz->direita);
  free(raiz);
}

void liberaArvoreFormigas(Formiga *raiz)
{
  if (raiz == NULL)
  {
    return;
  }
  liberaArvoreFormigas(raiz->esquerda);
  liberaArvoreFormigas(raiz->direita);
  liberaArvoreNodos(raiz->chaves);
  free(raiz);
}

int main()
{
  int tamanho = 1048576;
  Formiga **tabelaHash = (Formiga **)malloc(tamanho * sizeof(Formiga *));
  for (int i = 0; i < tamanho; i++)
  {
    tabelaHash[i] = NULL;
  }

  long long identificador;
  char chave[11];
  while (scanf("%lld %10s", &identificador, chave) != EOF)
  {
    gerenciaChaves(tabelaHash, tamanho, identificador, chave);
  }

  for (int i = 0; i < tamanho; i++)
  {
    if (tabelaHash[i] != NULL)
    {
      liberaArvoreFormigas(tabelaHash[i]);
    }
  }
  free(tabelaHash);

  return 0;
}
