#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *prox;
    struct node *ant;
}node;

typedef struct {
    node *ini;
    node *fim;
} Lista;

void insere(Lista *lista, int x){
    node *novo = malloc(sizeof(node));
    novo->data = x;
    novo->prox = NULL;
    novo->ant = NULL;
    
    if(lista->ini == NULL){ // se estiver vazia novo = ini e fim
        lista->ini = novo;
        lista->fim = novo;
    }else{
        lista->fim->prox = novo; // adicionar no final
        novo->ant = lista->fim;
        lista->fim = novo;
    }
}

int removeInicio(Lista *lista){
    node *temp = lista->ini;
    int valor = temp->data;
    
    lista->ini = lista->ini->prox;
    if(lista->ini != NULL){
        lista->ini->ant = NULL;
    }else{
        lista->fim = NULL; // lista vazia
    }
    
    free(temp);
    return valor;
}

void moveInicioParaFim(Lista *lista){
    if(lista->ini == NULL || lista->ini->prox == NULL) return;
    
    int valor = removeInicio(lista);
    insere(lista, valor);
}

int tamanhoLista(Lista *lista){
    int count = 0;
    node *atual = lista->ini;
    while(atual != NULL){
        count++;
        atual = atual->prox;
    }
    return count;
}

void liberaLista(Lista *lista){
    while(lista->ini != NULL){
        removeInicio(lista);
    }
}

int main(){
    int n;
    
    do{
        scanf("%d", &n);
        if(n == 0) break;
        
        Lista lista = {NULL, NULL};
                
        for(int i = 1; i <= n; i++){    // lista com valores de 1 a n
            insere(&lista, i);
        }
        
        printf("Discarded cards:");
        int primeiro = 1;
        
        while(tamanhoLista(&lista) >= 2){
            // descarta a primeira carta
            int descartada = removeInicio(&lista);
            
            if(primeiro){
                printf(" %d", descartada);
                primeiro = 0;
            }else{
                printf(", %d", descartada);
            }
            
            // Move a próxima carta para o final
            if(tamanhoLista(&lista) >= 1){
                moveInicioParaFim(&lista);
            }
        }
        
        //carta restante
        int restante = removeInicio(&lista);
        printf("\nRemaining card: %d\n", restante);
        
        liberaLista(&lista); //libera oq sobrou
        
    }while(n != 0);

    return 0;
}