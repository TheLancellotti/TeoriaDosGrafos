#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    struct lista *adj;
    int visitado;
} vertice;

typedef struct lista
{
    struct registro *inicio;
    struct registro *fim;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

lista *aloca_lista()
{
    lista *adj = (lista *)calloc(1, sizeof(lista));
    return adj;
}

registro *aloca_registro()
{
    registro *novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

void mostrar_lista(lista *adj)
{
    if (adj == NULL)
    {
        printf("lista vazia\n");
        return;
    }
    registro *aux = adj->inicio;
    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

void incluir_vertice(vertice *v, int valor)
{
    v->visitado = 0;
    if (v->adj == NULL)
    {
        v->adj = aloca_lista();
    }
    registro *novo;
    novo = aloca_registro();
    novo->valor = valor;
    if (v->adj->inicio == NULL)
    {
        v->adj->inicio = novo;
        v->adj->fim = novo;
    }
    else
    {
        v->adj->fim->prox = novo;
        v->adj->fim = novo;
    }
}

void dfs (vertice * vertices, int raiz){
    // printf("%d ", raiz);
    vertices[raiz].visitado = 1;
    if (vertices[raiz].adj == NULL){
        return;
    }
    registro * aux = vertices[raiz].adj->inicio;
    while (aux != NULL){
        if (vertices[aux->valor].visitado == 0){
            dfs(vertices, aux->valor);
        }
        aux = aux->prox;
    }
}

int main()
{

    int n;
    int e;
    int u, v;
    int x = 0;
    vertice *vertices;
    scanf("%d %d", &n, &e);

    vertices = (vertice *)calloc(sizeof(vertice), n + 1);
    for (int i = 1; i <= e; i++)
    {
        scanf("%d %d", &u, &v);
        incluir_vertice(&vertices[u], v);
        incluir_vertice(&vertices[v], u);
    }

    /*for (int j = 1; j <= n; j++)
    {
        mostrar_lista(vertices[j].adj);
    } */

    for (int m = 1; m <= n; m++)
    {
        if (vertices[m].visitado == 0)
        {
            dfs(vertices, m);
            x++;
        }
    }
    printf("%d\n", x);

    return 0;
}