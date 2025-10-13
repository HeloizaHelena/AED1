#include <stdio.h>

int calls;

int fib(int n) {
    calls++;
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int N, X;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &X);
        calls = 0;
        int result = fib(X);
        printf("fib(%d) = %d calls = %d\n", X, calls - 1, result);
    }
    
    return 0;
}