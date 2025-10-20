#include <stdio.h>

void insertion_sort(int v[], int n){
    int i, j, aux;
    for(i = 1; i<n; i++){
        aux = v[i];
        j = i-1;

        while((j>=0)&& (aux < v[j])){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }
}

int main(){
    int qtd;
    scanf("%d", &qtd);

    for(int k=0; k<qtd; k++){ //qtd de vezes a executar
        int n;
        scanf("%d", &n);
        int v[n]; //vetor com n elementos 
        for(int l=0; l<n; l++){ //inserir os elementos do vetor
            scanf("%d", &v[l]);
        }
        insertion_sort(v, n);
        for(int l=0; l<n; l++){ 
            printf("%d ", v[l]); // imprimir o vetor agora ordenado
        }
        printf("\n");  
    }


    return 0;
}