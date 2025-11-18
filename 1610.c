#include <stdio.h>

int grafo[10001][301];
int grau[10001];
int visitado[10001];
int pilha[10001];

int dfs(int documento) {
    visitado[documento] = 1;
    pilha[documento] = 1;
    
    for (int i = 0; i < grau[documento]; i++) {
        int vizinho = grafo[documento][i];
        if (!visitado[vizinho]) {
            if (dfs(vizinho)) return 1;
        } else if (pilha[vizinho]) {
            return 1;
        }
    }
    
    pilha[documento] = 0;
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        
        for (int i = 1; i <= N; i++) {
            grau[i] = 0;
            visitado[i] = 0;
            pilha[i] = 0;
        }
        
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            grafo[A][grau[A]++] = B;
        }
        
        int ciclo = 0;
        for (int i = 1; i <= N; i++) {
            if (!visitado[i]) {
                if (dfs(i)) {
                    ciclo = 1;
                    break;
                }
            }
        }
        
        printf(ciclo ? "SIM\n" : "NAO\n");
    }
    
    return 0;
}