#include <stdio.h>
#include <stdlib.h>
void intercala(int v[], int c1, int f1, int c2, int f2, int *trocas, int *comparacao) {
    int len = (f2 - c1 + 1);
    int *a;
    a = (int*)malloc(len * sizeof(int));
    int i1 = c1;
    int i2 = c2;
    int k = 0;
    while (i1 <= f1 && i2 <= f2) {
        (*comparacao)++;
        if (v[i1] <= v[i2]) {
            (*trocas)++;
            a[k++] = v[i1++]; //é o mesmo que k++;    i1++;
        }
        else {
            (*trocas)++;
            a[k] = v[i2];
            k++;
            i2++;
        }
    }
    while (i1 <= f1) {
        (*trocas)++;
        a[k++] = v[i1++];
    }
    while (i2 <= f2) {
        (*trocas)++;
        a[k++] = v[i2++];
    }
    k = 0; //da pra definir aqui ou no for
    for (int i = c1; i <= f2; i++) {
        (*trocas)++;
        v[i] = a[k];
        k++;
    }
    free(a);
}


void merge(int v[], int c, int f, int *trocas, int *comparacao) {
    if (f > c) {
        int m = (c + f) / 2;
        merge(v, c, m, trocas, comparacao);
        merge(v, m + 1, f, trocas, comparacao);
        intercala(v, c, m, m + 1, f , trocas, comparacao);
    }
}

void main(int argc, char* argv[]) {
    int trocas = 0;
    int comparacao = 0;
    int n = 16;
    int v[] = { 1, 3, 2, 7, 5, 5, 2, 7, 2, 9, 3, 0, 8, 3, 1, 4 };

    merge(v, 0, n - 1, &trocas, &comparacao );

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    printf("Trocas: %d\ncomparacao: %d", trocas, comparacao);
}