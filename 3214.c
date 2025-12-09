#include <stdio.h>

int main() {
    int E, F, C;
    while (scanf("%d %d %d", &E, &F, &C) != EOF) {
        int garrafas = E + F;
        int total = 0;

        while (garrafas >= C) {
            garrafas = garrafas - C + 1; // troca C por 1 cheia
            total++;
        }

        printf("%d\n", total);
    }
    return 0;
}
