#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break; // fim da entrada

        while (1) {
            int desired[MAX];
            scanf("%d", &desired[0]);

            if (desired[0] == 0) { // fim do bloco
                printf("\n");
                break;
            }

            // lê o resto da permutação
            for (int i = 1; i < n; i++) {
                scanf("%d", &desired[i]);
            }

            int stack[MAX];
            int top = -1;
            int next = 1; // próximo vagão que chega
            int possible = 1;

            for (int i = 0; i < n; i++) {
                int want = desired[i];

                // empilha até chegar no vagão que queremos
                while (next <= want) {
                    stack[++top] = next++;
                }

                // verifica se o topo é o que queremos tirar
                if (stack[top] == want) {
                    top--; // retira da pilha
                } else {
                    possible = 0;
                    break;
                }
            }

            if (possible)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}