#include <stdio.h>
#include <stdlib.h>

void libera_matriz(int **s) {
    for(int i = 0; i < 9; i++) {
        free(s[i]);
    }
    free(s);
}

int sudoku() {
    int **s = (int**)malloc(9 * sizeof(int*));
    
    for(int i = 0; i < 9; i++) {
        s[i] = (int*)malloc(9 * sizeof(int));
    }
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            scanf("%d", &s[i][j]);
        }
    }

    // Verifica quadrantes
    // Quadrante 1
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1) {
            libera_matriz(s);
            return 0;
        }
    }

    // Quadrante 2 
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 3; j < 6; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1) {
            libera_matriz(s);
            return 0;
        }
    }

    // Quadrante 3
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 6; j < 9; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1) {
            libera_matriz(s);
            return 0;
        }
    }

    // Quadrante 4
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 3; i < 6; i++) {
            for(int j = 0; j < 3; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1) {
            libera_matriz(s);
            return 0;
        }
    }

    // Quadrante 5
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 3; i < 6; i++) {
            for(int j = 3; j < 6; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1) {
            libera_matriz(s);
            return 0;
        }
    }

    // Quadrante 6
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 3; i < 6; i++) {
            for(int j = 6; j < 9; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1) {
            libera_matriz(s);
            return 0;
        }
    }

    // Quadrante 7
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 6; i < 9; i++) {
            for(int j = 0; j < 3; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1) {
            libera_matriz(s);
            return 0;
        }
    }

    // Quadrante 8
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 6; i < 9; i++) {
            for(int j = 3; j < 6; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1) {
            libera_matriz(s);
            return 0;
        }
    }

    // Quadrante 9
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 6; i < 9; i++) {
            for(int j = 6; j < 9; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1) {
            libera_matriz(s);
            return 0;
        }
    }

    // Verifica linhas
    for(int i = 0; i < 9; i++) {
        for(int a = 1; a < 10; a++) {
            int qtd = 0;
            for(int j = 0; j < 9; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
            if(qtd != 1) {
                libera_matriz(s);
                return 0;
            }
        }  
    }

    // Verifica colunas
    for(int j = 0; j < 9; j++) {
        for(int a = 1; a < 10; a++) {
            int qtd = 0;
            for(int i = 0; i < 9; i++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
            if(qtd != 1) {
                libera_matriz(s);
                return 0;
            }
        }  
    }

    libera_matriz(s);
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        printf("Instancia %d\n", i + 1);
        
        if(sudoku()) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}