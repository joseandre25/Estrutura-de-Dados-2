 ## QuickSelect 
- Filho do quickSort, msm problema> vetor ordenado: Árvore desbalanceada. 

Pior caso: O(n²)
Caso médio: O(n)
Melhor caso: O(n)

Como escolher o pivô pra evitar o pior caso? Mediana de 3.

'''
Problema: Como encontrar o k-ésimo menor elemento em um vetor?

Quando k = 1, menor elemento, o custo é O(N).

Para k >= 2,
1º Ordena e recupere o elemento na posição K (ou k-1). O(n lg n).


Sepração: Dado um vetor V[e..d], queremos encontrar J E [e,d] tal que:
		V[e...j-1] <= V[j] < V [j+1..d].
		
Resolver esse problema significa:

1º Encontrar a posição "correta" (no vetor ordenado) do pivô.
2º Rearranja o vetor de tal forma que todos os <= pivô estejam à sua esquerda e todos > pivô, à sua direita.


Para encontrar o k-ésimo menor:
-> Resolve o problema da separação.
	-> Se k < j, aplico separação à esquerda
	-> Se k > j, ''       ''     '' direita.
	
void quickSelect(int *v, int e, int d, int k){
	if(e<d){
		int j = particiona(v,e,d);
		if(k<j) quickSelect(v,e,j-1,k);
		if(k>j) quickSelect(v,j+1, d,k;
	}
}
