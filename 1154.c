#include <stdio.h>

int main(){
    int idade = 0;
    int total = 0;
    int qtd = 0;

    while(1){
        scanf("%d", &idade);
        if(idade < 0) {
            break;
        }
        total += idade;
        qtd += 1;
    }
    
    if(qtd > 0) {
        float media = (float)total / qtd;
        printf("%.2f\n", media);
    }
    
    return 0;
}