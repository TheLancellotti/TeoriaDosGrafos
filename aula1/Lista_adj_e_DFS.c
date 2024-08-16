#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    struct lista *adj;
    int visitado;
}vertice;

typedef struct lista{
    struct registro *inicio;
    struct registro *fim;
}lista;

typedef struct registro{
    int valor;
    struct registro *prox;
}registro;

lista * aloca_lista (){
    lista * adj = (lista *) calloc(1, sizeof (lista));
    return adj;
}

registro * aloca_registro (){
    registro * novo = (registro *) calloc(1, sizeof (registro));
    return novo;
}

void mostrar_lista (lista * adj){
    registro * aux = adj->inicio;
    if (aux == NULL){
        printf("lista vazia\n");
        return;
    }else{
        while (aux != NULL){
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }

}

void incluir_vertice (vertice * v, int valor){
    if (v->adj == NULL){
        v->adj = aloca_lista();
    }
    registro * novo;
    novo = aloca_registro();
    novo->valor = valor;
    if (v->adj->inicio == NULL){
        v->adj->inicio = novo;
        v->adj->fim = novo;
    }else{
        v->adj->fim->prox = novo;
        v->adj->fim = novo;
    }
}

void dfs (vertice * vertices, int raiz){
    printf("%d ", raiz);
    vertices[raiz].visitado = 1;
    registro * aux = vertices[raiz].adj->inicio;
    while(aux != NULL){
        if (vertices[aux->valor].visitado == 0){
            dfs(vertices, aux->valor);
        }
        aux = aux->prox;
    }
}

int main (){

    int qtd_vertices;
    int qtd_arestas;
    int v1, v2;
    vertice * vertices;

    scanf("%d %d", &qtd_vertices, &qtd_arestas);

    vertices = (vertice *) calloc(sizeof(vertice),qtd_vertices + 1);

    for (int i = 0; i < qtd_arestas; i++){
        scanf("%d %d", &v1, &v2);
        incluir_vertice(&vertices[v1], v2);
        incluir_vertice(&vertices[v2], v1);
    }

    for  (int j = j; j < qtd_vertices; j++)
    {
        printf("Vertice %d: ", j);
        mostrar_lista(vertices[j].adj);
    }
    

    return 0;
}
