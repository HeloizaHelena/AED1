#include <stdio.h>

#define MAX 2048

long long sortudo[MAX];
int lc = 0;

// Gera todos os números sortudos até 2^31
void generate(long long x) {
    if (x > (1LL << 31)) return;
    if (x != 0) sortudo[lc++] = x;
    generate(x * 10 + 4);
    generate(x * 10 + 7);
}

// Verifica se número é sortudo
int eh_sortudo(long long n) {
    if (n == 0) return 0;
    while (n > 0) {
        int d = n % 10;
        if (d != 4 && d != 7) return 0;
        n /= 10;
    }
    return 1;
}

int main() {
    long long N;

    generate(0); 

    while (scanf("%lld", &N) != EOF) {

        if (eh_sortudo(N)) {
            printf("sortudo\n");
            continue;
        }

        int ok = 0;
        for (int i = 0; i < lc; i++) {
            if (N % sortudo[i] == 0) {
                ok = 1;
                break;
            }
        }

        if (ok) printf("quase sortudo\n");
        else    printf("azarado\n");
    }

    return 0;
}
