#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 10000

typedef struct node{
    char m;
    struct node *prox;
}node;

void insere(node **lista, char x){
    node *novo = malloc(sizeof(node));
    novo->m = x;
    novo->prox = *lista;
    *lista = novo;
}

void deleta(node **lista){
    if(*lista == NULL){
        return;
    }
    node *q = *lista;
    *lista = (*lista)->prox;
    free(q);
}

int verificaExpressao(char exp[]){
    node *lista = NULL;
    int n = strlen(exp); //qtd de caracteres
    
    for(int i = 0; i < n; i++){
        if(exp[i] == '('){ //se for '(' adiciona na lista
            insere(&lista, exp[i]);
        }
        else if(exp[i] == ')'){ 
            if(lista == NULL){ // se achar ')' e a lista estiver vazia
                return 0; //incorreto
            }
            deleta(&lista);
        }
    }
    
    // se a lista estiver vazia = correto
    return lista == NULL;
}

int main(){
    char exp[MAX];
    
    while(scanf("%s", exp) != EOF){
        if(verificaExpressao(exp)){
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    
    return 0;
}