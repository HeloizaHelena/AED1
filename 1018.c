#include <stdio.h>

int main()
{
    int n;
    int c;
    scanf("%d", &n);
    printf("%d\n", n);
    c = n / 100;
    printf("%d nota(s) de R$ 100,00\n", c);
    n -= c * 100;
    c = n / 50;
    printf("%d nota(s) de R$ 50,00\n", c);
    n -= c * 50;
    c = n/20;
    printf("%d nota(s) de R$ 20,00\n", c);
    n -= c*20;
    c = n/10;
    printf("%d nota(s) de R$ 10,00\n", c);
    n -= c*10;
    c = n/5;
    printf("%d nota(s) de R$ 5,00\n", c);
    n -= c*5;
    c = n/2;
    printf("%d nota(s) de R$ 2,00\n", c);
    n -= c*2;
    printf("%d nota(s) de R$ 1,00\n", n);
    return 0;
}