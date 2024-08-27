EDA 02 - 03/04

QUICKSORT

-> É um algoritmo que usa a técnica de divisão e conquista e, a cada divisão, resolve o problema de separação (ou particionameto):

----> Dado um vetor V[e...d], queremos definir um indice j tal que:
	V[e.. j-1] <= V[j] < V[j+1..d]
	
* Como resolver o particionamento?

1º Escolher arbitrariamente um elemento do vetor (pivô).
2º Encontrar o índice j e posicionar o pivô neste índice de tal forma a cumprir a primeira condição.


Complexidade do Particiona: O(d-c+1) ->
