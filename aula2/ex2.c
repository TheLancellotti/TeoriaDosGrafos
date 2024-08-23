#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    struct lista *adj;
    int visitado;
    int distancia;
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

void incluir_vertice(vertice *v, int valor)
{
    if (v->adj == NULL)
    {
        v->adj = aloca_lista();
    }
    registro *novo = aloca_registro();
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

int dfs(vertice *vertices, int raiz, int pai)
{
    vertices[raiz].visitado = 1;
    registro *aux = vertices[raiz].adj->inicio;
    while (aux != NULL)
    {
        if (aux->valor != pai)
        {
            if (vertices[aux->valor].visitado == 1)
            {
                return 0;
            }
            if (!dfs(vertices, aux->valor, raiz))
            {
                return 0;
            }
        }
        aux = aux->prox;
    }
    return 1;
}

int main()
{
    int qtd_vertices, qtd_arestas;
    int v1, v2;
    
    scanf("%d %d", &qtd_vertices, &qtd_arestas);

    if (qtd_arestas != qtd_vertices - 1)
    {
        printf("NO\n");
        return 0;
    }

    vertice *vertices = (vertice *)calloc(qtd_vertices + 1, sizeof(vertice));

    for (int i = 0; i < qtd_arestas; i++)
    {
        scanf("%d %d", &v1, &v2);
        incluir_vertice(&vertices[v1], v2);
        incluir_vertice(&vertices[v2], v1);  // Aresta bidirecional
    }

    if (!dfs(vertices, 1, -1))
    {
        printf("NO\n");
        free(vertices);
        return 0;
    }

    for (int i = 1; i <= qtd_vertices; i++)
    {
        if (vertices[i].visitado == 0)
        {
            printf("NO\n");
            free(vertices);
            return 0;
        }
    }

    printf("YES\n");
    free(vertices);
    return 0;
}
