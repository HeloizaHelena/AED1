#include <stdio.h>

int main() {
    int T, A, B, C, D, E;
    scanf("%d", &T);
    scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
    
    int acerto = 0;
    
    if (A == T) acerto++;
    if (B == T) acerto++;
    if (C == T) acerto++;
    if (D == T) acerto++;
    if (E == T) acerto++;
    
    printf("%d\n", acerto);
    
    return 0;
}