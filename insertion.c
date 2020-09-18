#include <stdio.h>

void insertion(int v[], int n, int *troca_insertion, int *comparacao_insertion) {
	for (int i = 1; i < n; i++) {
		(*troca_insertion)++; 
		int x = v[i];
		int j = i - 1;
		while (j >= 0 && v[j] > x) {
			(*comparacao_insertion)++;
			(*troca_insertion)++;
			v[j + 1] = v[j];
			j--;
		}
		//if usado apenas para testar o caso de ter ocorrido ou nao curto circuito
		if (j >= 0) {
			(*comparacao_insertion)++;
		}
		(*troca_insertion)++;
		v[j + 1] = x;
	}
}



void main(int argc, char* argv[]) {
	int troca_insertion = 0;
	int comparacao_insertion = 0;
	int n = 8;
	int a[] = { 58, 94, 96, 32, 49,180, 11, 21 };
	insertion(a, n, &troca_insertion, &comparacao_insertion);
	printf("o numero de trocas: %d\n", troca_insertion);
	printf("o numero de comparacoes: %d\n", comparacao_insertion);

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}