#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

typedef struct node{
    char m;
    struct node *prox;
}node;

void push(node **pilha, char x){
    node *novo = malloc(sizeof(node));
    novo->m = x;
    novo->prox = *pilha;
    *pilha = novo;
}

void pop(node **pilha){
    if(*pilha == NULL) return;
    node *q = *pilha;
    *pilha = (*pilha)->prox;
    free(q);
}

int verificaExpressao(char exp[]){
    node *pilha = NULL;
    int n = strlen(exp); //qtd de caracteres
    
    for(int i = 0; i < n; i++){
        if(exp[i] == '('){ //se for '(' adiciona na pilha
            push(&pilha, exp[i]);
        }
        else if(exp[i] == ')'){ 
            if(pilha == NULL){ // se achar ')' e a pilha estiver vazia
                return 0; //incorreto
            }
            pop(&pilha);
        }
    }
    
    // se a pilha estiver vazia = correto
    return pilha == NULL;
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