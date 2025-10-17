#include <stdio.h>
#include <stdlib.h>

void intercala(int p, int q, int r, int v[]) {
    int i, j, k;
    int n1 = q - p;
    int n2 = r - q;
    
    //arrays temporários
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    
    // copiar dados para os arrays temporários
    for (i = 0; i < n1; i++)
        L[i] = v[p + i];
    for (j = 0; j < n2; j++)
        R[j] = v[q + j];
    
    // Merge dos arrays temporários de volta em v[]
    i = 0;
    j = 0;
    k = p;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
    
    // copia elementos restantes de L[]
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }
    
    // copia elementos restantes de R[]
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

void merge(int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        merge(p, q, v);
        merge(q, r, v);
        intercala(p, q, r, v);
    }
}

void mergeWrapper(int v[], int n) {
    merge(0, n, v);
}
//leitura mais eficiente 
int fast_read() {
    int value = 0;
    char c = getchar();
    
    while (c < '0' || c > '9') {
        c = getchar();
    }
    
    while (c >= '0' && c <= '9') {
        value = value * 10 + (c - '0');
        c = getchar();
    }
    
    return value;
}

int main() {
    int qtd = fast_read();

    for(int k = 0; k < qtd; k++) {
        int n = fast_read();
        int *v = malloc(n * sizeof(int));
        
        for(int l = 0; l < n; l++) {
            v[l] = fast_read();
        }
        
        mergeWrapper(v, n);
        
        // imprime 
        printf("%d", v[0]);
        for(int l = 1; l < n; l++) {
            printf(" %d", v[l]);
        }
        printf("\n");
        
        free(v);
    }

    return 0;
}