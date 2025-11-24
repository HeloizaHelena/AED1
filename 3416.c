#include <stdio.h>

int main() {
    int N, L, D;
    scanf("%d %d %d", &N, &L, &D);

    int minL = N * D;         // Necessário em ml
    int capaci = L * 1000;       // Capacidade de um preparo (ml)

 
    int k = (minL + capaci - 1) / capaci;

    printf("%d\n", k * L);

    return 0;
}
