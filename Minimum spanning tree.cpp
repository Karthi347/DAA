#include <stdio.h>
#include <stdlib.h>

#define VERTICES 5  

typedef struct Edge {
    int src, dest;
    int weight;
} Edge;

typedef struct Graph {
    int V, E;
    Edge* edge;
} Graph;

typedef struct Subset {
    int parent;
    int rank;
} Subset;

Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*) malloc(graph->E * sizeof(Edge));
    return graph;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*) a;
    Edge* edgeB = (Edge*) b;
    return edgeA->weight > edgeB->weight;
}

void KruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

    Subset* subsets = (Subset*) malloc(V * sizeof(Subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E) {
        Edge nextEdge = graph->edge[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    printf("Edges in MST using Kruskal's Algorithm:\n");
    for (i = 0; i < e; ++i)
        printf("%c -- %c == %d\n", result[i].src + 'A', result[i].dest + 'A', result[i].weight);

    free(subsets);
}

void addEdge(Graph* graph, int index, char src, char dest, int weight) {
    graph->edge[index].src = src - 'A';
    graph->edge[index].dest = dest - 'A';
    graph->edge[index].weight = weight;
}

int main() {
    int V = VERTICES;
    int E = 7;
    Graph* graph = createGraph(V, E);

    addEdge(graph, 0, 'A', 'B', 1);
    addEdge(graph, 1, 'A', 'C', 3);
    addEdge(graph, 2, 'B', 'C', 3);
    addEdge(graph, 3, 'B', 'D', 6);
    addEdge(graph, 4, 'C', 'D', 4);
    addEdge(graph, 5, 'C', 'E', 2);
    addEdge(graph, 6, 'D', 'E', 5);

    KruskalMST(graph);

    free(graph->edge);
    free(graph);

    return 0;
}

