#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no {
    char valor;
    struct no* esq;
    struct no* dir;
};

struct no* inserir(struct no* raiz, char valor) {
    if (raiz == NULL) {
        struct no* novo = (struct no*)malloc(sizeof(struct no));
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    
    return raiz;
}

void infixo(struct no* raiz, int* primeiro) {
    if (raiz != NULL) {
        infixo(raiz->esq, primeiro);
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
        infixo(raiz->dir, primeiro);
    }
}

void prefixo(struct no* raiz, int* primeiro) {
    if (raiz != NULL) {
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
        prefixo(raiz->esq, primeiro);
        prefixo(raiz->dir, primeiro);
    }
}

void posfixo(struct no* raiz, int* primeiro) {
    if (raiz != NULL) {
        posfixo(raiz->esq, primeiro);
        posfixo(raiz->dir, primeiro);
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
    }
}

int pesquisar(struct no* raiz, char valor) {
    if (raiz == NULL) {
        return 0;
    }
    
    if (valor == raiz->valor) {
        return 1;
    }
    
    if (valor < raiz->valor) {
        return pesquisar(raiz->esq, valor);
    } else {
        return pesquisar(raiz->dir, valor);
    }
}

int main() {
    struct no* raiz = NULL;
    char linha[10];
    char valor;
    
    while (scanf("%s", linha) != EOF) {
        if (strcmp(linha, "I") == 0) {
            scanf(" %c", &valor);
            raiz = inserir(raiz, valor);
        } else if (strcmp(linha, "INFIXA") == 0) {
            int primeiro = 1;
            infixo(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(linha, "PREFIXA") == 0) {
            int primeiro = 1;
            prefixo(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(linha, "POSFIXA") == 0) {
            int primeiro = 1;
            posfixo(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(linha, "P") == 0) {
            scanf(" %c", &valor);
            if (pesquisar(raiz, valor)) {
                printf("%c existe\n", valor);
            } else {
                printf("%c nao existe\n", valor);
            }
        }
    }
    
    return 0;
}