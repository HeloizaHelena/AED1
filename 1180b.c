#include <stdio.h>

int main(){
    int N;
    do{
        scanf("%d", &N);
    }while(N <= 1 || N >= 1000);
    int X[N];
    
    int *ptr = X;
    for(int i = 0; i < N; i++){
        scanf("%d", ptr);
        ptr++;
    }
    
    int *menor_ptr = X;
    int posicao = 0;
    ptr = X + 1; 
    for(int i = 1; i < N; i++){
        if(*ptr < *menor_ptr){
            menor_ptr = ptr;
            posicao = i;
        }
        ptr++;
    }
    printf("Menor valor: %d\n", *menor_ptr);
    printf("Posicao: %d\n", posicao);
    
    return 0;
}