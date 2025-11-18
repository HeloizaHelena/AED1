#include <stdio.h>

int main()
{
    int num, h; //numero e hora
    float s; //salario
    scanf("%d %d %f", &num, &h, &s);
    printf("NUMBER = %d\nSALARY = U$ %.2f\n", num, s * h);
    return 0;
}