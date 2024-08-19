# 🌐 Teoria dos Grafos - Um Mergulho Profundo nos Mundos Conectados 🌐

Bem-vindo ao meu repositório de anotações sobre Teoria dos Grafos! Aqui, mergulhamos no fascinante universo das estruturas que conectam tudo, desde redes sociais até rotas de trânsito. Se você adora nós e arestas, prepare-se para um passeio emocionante!

## 🚀 O Que É Um Grafo?

Um **grafo** é uma coleção de **vértices** (também conhecidos como nós) conectados por **arestas**. Em termos simples, é como uma rede de amigos onde as pessoas são os vértices e as amizades são as arestas. Mas essa estrutura vai muito além!

### 🎯 Tipos de Grafos

- **Grafo Não Direcional**: As arestas não têm direção; a conexão é mútua (amizade recíproca, talvez?).
- **Grafo Direcional (Digrafo)**: As arestas têm uma direção específica; nem todas as conexões são recíprocas.
- **Grafo Ponderado**: As arestas carregam um peso; algumas conexões são mais "pesadas" do que outras.
- **Grafo Não Ponderado**: As arestas não têm peso; todas as conexões são iguais.
- **Grafo Completo**: Todos os vértices estão conectados; aqui, todos são amigos de todos!

## 🛠️ Representação de Grafos

Como podemos representar esses grafos? Aqui estão as opções:

- **Matriz de Adjacência**: Imagine uma tabela onde cada linha e coluna é um vértice, e os valores indicam a presença de arestas.
- **Lista de Adjacência**: Cada vértice possui uma lista de vértices conectados a ele. Simples e eficiente!
- **Matriz de Incidência**: Cada linha é um vértice, e cada coluna é uma aresta. Conexões mapeadas com precisão.
- **Lista de Arestas**: Aqui, cada aresta é representada por uma lista de vértices conectados.

## 🔗 Grafos Fortemente Conectados

Um grafo é **fortemente conectado** se existe um caminho entre todos os pares de vértices. Em outras palavras, todos estão ligados de alguma forma!

### 🎯 Componentes do Grafo

- **Componentes Fortemente Conectados**: Um grupo de vértices é fortemente conectado se há um caminho de ida e volta entre todos eles.
- **Componentes Fracamente Conectados**: Um grupo é fracamente conectado se há uma conexão, independentemente da direção.

## 🧠 Busca em Profundidade (DFS)

A **Busca em Profundidade (Depth-First Search - DFS)** é uma técnica de exploração de grafos que segue um caminho até o fim antes de retroceder. Aqui está um exemplo simples:

```plaintext
1 -> 2, 3
2 -> 1
3 -> 1, 4, 5, 6
4 -> 3, 7, 8
5 -> 3
6 -> 3, 8
7 -> 4, 8
8 -> 4, 6, 7
