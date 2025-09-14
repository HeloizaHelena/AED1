#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, i;
    do{
        scanf("%d", &N);
    }while(N <= 1 || N >= 1000);

    int *X = (int *)malloc(N * sizeof(int));
    if (X == NULL) {
        printf("Erro de alocacao\n");
        return 1;
    }

    for(i = 0; i<N; i++){
        scanf("%d", &X[i]);
    }

    int menor = X[0];
    int posicao = 0;
    
    for(i = 1; i < N; i++) {
        if(X[i] < menor) {
            menor = X[i];
            posicao = i;
        }
    }
    
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);
    
    free(X);

    return 0;

}
