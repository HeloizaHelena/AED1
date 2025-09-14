#include <stdio.h>

int sudoku() {
    int s[9][9];
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            scanf("%d", &s[i][j]);
        }
    }

    // Caso 1: Verificar se há apenas um valor de 1 - 9 nos quadrantes
    //1 quadrante
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1){
             return 0;
        }
    }

    //2 quadrante
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 3; j < 6; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1){
             return 0;
        }
    }

    //3 quadrante
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 6; j < 9; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1){
             return 0;
        }
    }

    //4 quadrante
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 3; i < 6; i++) {
            for(int j = 0; j < 3; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1){
             return 0;
        }
    }

    //5 quadrante
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 3; i < 6; i++) {
            for(int j = 3; j < 6; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1){
             return 0;
        }
    }

    //6 quadrante
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 3; i < 6; i++) {
            for(int j = 6; j < 9; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1){
             return 0;
        }
    }

    //7 quadrante 
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 6; i < 9; i++) {
            for(int j = 0; j < 3; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1){
             return 0;
        }
    }

    //8 quadrante
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 6; i < 9; i++) {
            for(int j = 3; j < 6; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1){
             return 0;
        }
    }

    //9 quadrante
    for(int a = 1; a < 10; a++) {
        int qtd = 0;
        for(int i = 6; i < 9; i++) {
            for(int j = 6; j < 9; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
        }
        if(qtd != 1){
             return 0;
        }
    }

    //Caso 2: verificar linhas
    for(int i = 0; i < 9; i++) {
        for(int a = 1; a < 10; a++) {
            int qtd = 0;
            for(int j = 0; j < 9; j++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
            if(qtd != 1){
             return 0;
            }
        }  
    }

    //Caso 3: verificar colunas
    for(int j = 0; j < 9; j++) {
        for(int a = 1; a < 10; a++) {
            int qtd = 0;
            for(int i = 0; i < 9; i++) {
                if(a == s[i][j]) {
                    qtd++;
                }
            }
            if(qtd != 1){
             return 0;
            }
        }  
    }

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