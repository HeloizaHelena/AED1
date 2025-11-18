#include <stdio.h>

void mul(unsigned long long A[2][2], unsigned long long B[2][2], unsigned long long m) {
    unsigned long long x = (A[0][0]*B[0][0] + A[0][1]*B[1][0]) % m;
    unsigned long long y = (A[0][0]*B[0][1] + A[0][1]*B[1][1]) % m;
    unsigned long long z = (A[1][0]*B[0][0] + A[1][1]*B[1][0]) % m;
    unsigned long long w = (A[1][0]*B[0][1] + A[1][1]*B[1][1]) % m;
    A[0][0]=x; A[0][1]=y; A[1][0]=z; A[1][1]=w;
}

void mpow(unsigned long long R[2][2], unsigned long long F[2][2],
          unsigned long long e, unsigned long long m) {
    while (e) {
        if (e & 1) mul(R, F, m);
        mul(F, F, m);
        e >>= 1;
    }
}

unsigned long long fib_mod(unsigned long long n, unsigned long long m) {
    if (n == 0) return 0;
    unsigned long long F[2][2] = {{1,1},{1,0}};
    unsigned long long R[2][2] = {{1,0},{0,1}};
    mpow(R, F, n-1, m);
    return R[0][0] % m;
}

int main() {
    unsigned long long n, b;
    int cs = 1;
    while (scanf("%llu %llu", &n, &b) == 2) {
        if (n == 0 && b == 0) break;
        unsigned long long f = fib_mod(n+1, b);
        unsigned long long ans = (2*f + b - 1) % b;
        printf("Case %d: %llu %llu %llu\n", cs++, n, b, ans);
    }
    return 0;
}
