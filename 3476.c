#include <stdio.h>

int main() {
    double S, B, C;
    scanf("%lf %lf %lf", &S, &B, &C);

    double total = (1.0 / S) + (1.0 / B) + (1.0 / C);
    double T = 1.0 / total;

    printf("%.3f\n", T);
    return 0;
}
