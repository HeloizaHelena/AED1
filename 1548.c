#include <stdio.h>
#include <stdlib.h>

//contar quantos alunos mantiveram a mesma posição depois de ordenar
int cont_estaticos(int *original, int *ordenado, int tamanho) {
    int estaticos = 0;
    for (int i = 0; i < tamanho; i++) {
       
        if (original[i] == ordenado[i]) { //se forem iguais na mesma posição
            estaticos++; // incrementa o contador de alunos estáticos
        }
    }
    return estaticos;
}

// Função de comparação para o qsort
int comparar(const void *a, const void *b) {
    // Retorna positivo se b > a (ordena do maior para o menor)
    // Retorna negativo se b < a
    // Retorna 0 se forem iguais
    return (*(int*)b - *(int*)a);
}

int main() {
    int N, M;
    
    // Lê o número de casos de teste 
    scanf("%d", &N);
    
    while (N--) {
        // Lê o número de alunos
        scanf("%d", &M);
        
        int notas_original[M];
        int notas_ordenadas[M];
        
        // Lê as notas dos M alunos
        for (int i = 0; i < M; i++) {
            scanf("%d", &notas_original[i]);
            notas_ordenadas[i] = notas_original[i];
        }
        
        // Ordena o array de notas_ordenadas em ordem DECRESCENTE com quicksort
        qsort(notas_ordenadas, M, sizeof(int), comparar);
        
        // Conta quantos alunos mantiveram a mesma posição
        int alunos_estaticos = cont_estaticos(notas_original, notas_ordenadas, M);
        printf("%d\n", alunos_estaticos);
    }
    
    return 0;
}