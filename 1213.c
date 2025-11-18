#include <stdio.h>

int main() {
    int n;
    
    while (scanf("%d", &n) != EOF) {
        int digitos = 1;
        int numero = 1;
        
        while (numero % n != 0) {
            numero = (numero * 10 + 1) % n;
            digitos++;
        }
        
        printf("%d\n", digitos);
    }
    
    return 0;
}