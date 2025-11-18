#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *esq;
    struct node *dir;
}node;

node *cria(int x){
    node *novo = malloc(sizeof(node));
    novo->data = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

node *insere(node *raiz, int x){
    if(raiz == NULL){
        return cria(x);
    }
    if(x < raiz->data){
        raiz->esq = insere(raiz->esq, x);
    }else{
        raiz->dir = insere(raiz->dir, x);
    }
    return raiz;
}

void pre(node *raiz, int *first){
    if(raiz == NULL) return;
    if(*first) {
        printf("%d", raiz->data);
        *first = 0;
    } else {
        printf(" %d", raiz->data);
    }
    pre(raiz->esq, first);
    pre(raiz->dir, first);
}

void in(node *raiz, int *first){
    if(raiz == NULL) return;
    in(raiz->esq, first);
    if(*first) {
        printf("%d", raiz->data);
        *first = 0;
    } else {
        printf(" %d", raiz->data);
    }
    in(raiz->dir, first);
}

void pos(node *raiz, int *first){
    if(raiz == NULL) return;
    pos(raiz->esq, first);
    pos(raiz->dir, first);
    if(*first) {
        printf("%d", raiz->data);
        *first = 0;
    } else {
        printf(" %d", raiz->data);
    }
}

void limpa(node *raiz){
    if(raiz == NULL) return;
    limpa(raiz->esq);
    limpa(raiz->dir);
    free(raiz);
}

int main(){
    int C;
    scanf("%d", &C);
    
    for(int i = 1; i <= C; i++){
        node *raiz = NULL;
        int qtd;
        scanf("%d", &qtd);
        
        for(int j = 0; j < qtd; j++){
            int aux;
            scanf("%d", &aux);
            raiz = insere(raiz, aux);
        }
        
        printf("Case %d:\n", i);
        
        int first = 1;
        printf("Pre.: ");
        pre(raiz, &first);
        printf("\n");
        
        first = 1;
        printf("In..: ");
        in(raiz, &first);
        printf("\n");
        
        first = 1;
        printf("Post: ");
        pos(raiz, &first);
        printf("\n\n");
        
        limpa(raiz);
    }

    return 0;
}