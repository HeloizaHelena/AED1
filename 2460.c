#define MAX 50000
#include <stdio.h>

int main() {
    int N, M;
    
    //pessoas na fila
    scanf("%d", &N);
    
    int fila[MAX];
    //identificadores
    for (int i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }
    
    //quantas pessoas saíram
    scanf("%d", &M);
    
    int saidas[MAX];
    // identificadores de quem saiu
    for (int i = 0; i < M; i++) {
        scanf("%d", &saidas[i]);
    }
    
    // um array grande para marcar quem saiu
    int saiu[100001] = {0}; // Inicializa tudo com 0
    
    // Marca todas as pessoas que saíram
    for (int i = 0; i < M; i++) {
        saiu[saidas[i]] = 1; // 1 = saiu
    }
    
    // imprime
    int primeiro = 1; //saida sem espaço no começo
    for (int i = 0; i < N; i++) {
        // Se a pessoa NÃO está na lista de saídas
        if (saiu[fila[i]] == 0) {
            if (primeiro == 1) {
                printf("%d", fila[i]);
                primeiro = 0;
            } else {
                printf(" %d", fila[i]);
            }
        }
    }
    printf("\n");
    
    return 0;
}