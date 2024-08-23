#include <stdio.h>
#include <stdlib.h>

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

registro *aloca_registro() {
    registro *novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

void incluir_vertice(lista *adj, int valor) {
    registro *novo = aloca_registro();
    novo->valor = valor;
    if (adj->inicio == NULL) {
        adj->inicio = novo;
        adj->fim = novo;
    } else {
        adj->fim->prox = novo;
        adj->fim = novo;
    }
}

int dfs(lista *vertices[], int *cor, int inceto, int c) {
    cor[inceto] = c;

    registro *aux = vertices[inceto]->inicio;
    while (aux != NULL) {
        int vizinho = aux->valor;
        if (cor[vizinho] == 0) {  
            if (!dfs(vertices, cor, vizinho, 3 - c)) {
                return 0;  
            }
        } else if (cor[vizinho] == cor[inceto]) {
            return 0;  
        }
        aux = aux->prox;
    }
    return 1;
}

int main() {
    int scenarios;
    scanf("%d", &scenarios);

    for (int s = 1; s <= scenarios; s++) {
        int qtd_incetos, qtd_interacoes;
        scanf("%d %d", &qtd_incetos, &qtd_interacoes);

        lista **vertices = (lista **)calloc((qtd_incetos + 1), sizeof(lista *));
        int *cor = (int *)calloc((qtd_incetos + 1), sizeof(int));

        for (int i = 1; i <= qtd_incetos; i++) {
            vertices[i] = aloca_lista();
            cor[i] = 0;
        }

        for (int i = 0; i < qtd_interacoes; i++) {
            int v1, v2;
            scanf("%d %d", &v1, &v2);
            incluir_vertice(vertices[v1], v2);
            incluir_vertice(vertices[v2], v1);  
        }

        int suspeito = 0;

        for (int i = 1; i <= qtd_incetos; i++) {
            if (cor[i] == 0) {  
                if (!dfs(vertices, cor, i, 1)) {  
                    suspeito = 1;
                    break;
                }
            }
        }

        printf("Scenario #%d:\n", s);
        if (suspeito) {
            printf("Suspicious bugs found!\n");
        } else {
            printf("No suspicious bugs found!\n");
        }

        for (int i = 1; i <= qtd_incetos; i++) {
            free(vertices[i]);
        }
        free(vertices);
        free(cor);
    }

    return 0;
}