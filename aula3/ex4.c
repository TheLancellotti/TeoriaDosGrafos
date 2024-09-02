#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int resposta = 0;

typedef struct vertice {
    struct lista *adj;
    int visitado;
} vertice;

typedef struct node {
    char *aresta;
    struct node *prox;
} node;

typedef struct lista_arestas {
    struct node *inicio;
    struct node *fim;
} lista_arestas;

lista_arestas *foward, *back;

typedef struct lista {
    struct registro *inicio;
    struct registro *fim;
} lista;

typedef struct registro {
    int valor;
    struct registro *prox;
} registro;

lista *aloca_lista() {
    lista *adj = (lista *)calloc(1, sizeof(lista));
    return adj;
}

node *aloca_node(char *aresta) {
    node *novo = (node *)calloc(1, sizeof(node));
    novo->aresta = (char *)calloc(strlen(aresta) + 1, sizeof(char));
    strcpy(novo->aresta, aresta);
    return novo;
}

registro *aloca_registro() {
    registro *novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

lista_arestas *aloca_lista_arestas() {
    lista_arestas *aresta = (lista_arestas *)calloc(1, sizeof(lista_arestas));
    return aresta;
}

void mostrar_lista_arestas(lista_arestas *l) {
    if (l == NULL) {
        printf("lista vazia\n");
        return;
    }
    node *aux = l->inicio;
    while (aux != NULL) {
        printf("%s\n", aux->aresta);
        aux = aux->prox;
    }
    printf("\n");
}

void mostrar_lista(lista *adj) {
    if (adj == NULL) {
        printf("lista vazia\n");
        return;
    }
    registro *aux = adj->inicio;
    while (aux != NULL) {
        printf("%d", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

void push_aresta(lista_arestas *l, char *aresta) {
    node *novo = aloca_node(aresta);
    if (l->inicio == NULL) {
        l->inicio = novo;
        l->fim = novo;
    } else {
        l->fim->prox = novo;
        l->fim = novo;
    }
}

void incluir_vertice(vertice *v, int valor) {
    v->visitado = 0;
    if (v->adj == NULL) {
        v->adj = aloca_lista();
    }
    registro *novo;
    novo = aloca_registro();
    novo->valor = valor;
    if (v->adj->inicio == NULL) {
        v->adj->inicio = novo;
        v->adj->fim = novo;
    } else {
        v->adj->fim->prox = novo;
        v->adj->fim = novo;
    }
}

void dfs(vertice *vertices, int raiz, int pai) {
    vertices[raiz].visitado = 1;
    if (vertices[raiz].adj == NULL) {
        return;
    }
    registro *aux = vertices[raiz].adj->inicio;
    while (aux != NULL) {
        if (pai != 0 && vertices[aux->valor].visitado == 1 && aux->valor != pai) {
            char aresta[50];
            snprintf(aresta, sizeof(aresta), "Ciclo: %d -> %d", raiz, aux->valor);
            push_aresta(back, aresta);
            resposta = 1;
            return;
        }
        if (vertices[aux->valor].visitado == 0) {
            char aresta[50];
            snprintf(aresta, sizeof(aresta), "%d -> %d", raiz, aux->valor);
            push_aresta(foward, aresta);
            dfs(vertices, aux->valor, raiz);
        }
        aux = aux->prox;
    }
}

int main() {
    int n;
    int e;
    int u, v;
    vertice *vertices;
    // printf("Digite o numero de vertices e arestas: ");
    scanf("%d %d", &n, &e);
    foward = aloca_lista_arestas();
    back = aloca_lista_arestas();

    vertices = (vertice *)calloc(n + 1, sizeof(vertice));
    for (int i = 1; i <= e; i++) {
        // printf("Digite a aresta %d: ", i);
        scanf("%d %d", &u, &v);
        incluir_vertice(&vertices[u], v);
        incluir_vertice(&vertices[v], u);
    }

    /*
    printf("Lista de adjacencia:\n");
    for (int j = 1; j <= n; j++) {
        mostrar_lista(vertices[j].adj);
    }
    */

    for (int m = 1; m <= n; m++) {
        dfs(vertices, m, 0);
    }

    /*
    printf("Foward:\n");
    mostrar_lista_arestas(foward);
    printf("Back:\n");
    mostrar_lista_arestas(back); 
    */

    printf("%d\n", resposta);
    
    // Liberação de memória
    for (int i = 1; i <= n; i++) {
        registro *aux = vertices[i].adj->inicio;
        while (aux != NULL) {
            registro *temp = aux;
            aux = aux->prox;
            free(temp);
        }
        free(vertices[i].adj);
    }
    free(vertices);

    node *aux = foward->inicio;
    while (aux != NULL) {
        node *temp = aux;
        aux = aux->prox;
        free(temp->aresta);
        free(temp);
    }
    free(foward);

    aux = back->inicio;
    while (aux != NULL) {
        node *temp = aux;
        aux = aux->prox;
        free(temp->aresta);
        free(temp);
    }
    free(back);

    return 0;
}