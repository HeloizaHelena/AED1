#include <stdio.h>

int main() {
    int d, m;
    scanf("%d/%d", &d, &m);

    if ((m == 3  && d >= 21) || (m == 4 && d <= 20)) printf("aries\n");
    else if ((m == 4  && d >= 21) || (m == 5 && d <= 20)) printf("touro\n");
    else if ((m == 5  && d >= 21) || (m == 6 && d <= 20)) printf("gemeos\n");
    else if ((m == 6  && d >= 21) || (m == 7 && d <= 22)) printf("cancer\n");
    else if ((m == 7  && d >= 23) || (m == 8 && d <= 22)) printf("leao\n");
    else if ((m == 8  && d >= 23) || (m == 9 && d <= 22)) printf("virgem\n");
    else if ((m == 9  && d >= 23) || (m == 10 && d <= 22)) printf("libra\n");
    else if ((m == 10 && d >= 23) || (m == 11 && d <= 21)) printf("escorpiao\n");
    else if ((m == 11 && d >= 22) || (m == 12 && d <= 21)) printf("sagitario\n");
    else if ((m == 12 && d >= 22) || (m == 1 && d <= 19)) printf("capricornio\n");
    else if ((m == 1  && d >= 20) || (m == 2 && d <= 18)) printf("aquario\n");
    else if ((m == 2  && d >= 19) || (m == 3 && d <= 20)) printf("peixes\n");

    return 0;
}
