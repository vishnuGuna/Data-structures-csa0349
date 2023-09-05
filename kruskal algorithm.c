#include <stdio.h>
#include <stdlib.h>
struct Edge {
    int src, dest, weight;
};
struct Subset {
    int parent, rank;
};
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
void kruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[V]; // Array to store the resultant MST
    int e = 0; 
    int i = 0;
    qsort(edges, E, sizeof(struct Edge), compareEdges);
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1 && i < E) {
        struct Edge next_edge = edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            unionSets(subsets, x, y);
        }
    }
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++)
        printf("%d - %d: %d\n", result[i].src, result[i].dest, result[i].weight);
    free(subsets);
}
int main() {
    int V = 4; 
    int E = 5; 
    struct Edge edges[E];
    edges[0].src = 0;
    edges[0].dest = 1;
    edges[0].weight = 10;
    edges[1].src = 0;
    edges[1].dest = 2;
    edges[1].weight = 6;
    edges[2].src = 0;
    edges[2].dest = 3;
    edges[2].weight = 5;
    edges[3].src = 1;
    edges[3].dest = 3;
    edges[3].weight = 15;
    edges[4].src = 2;
    edges[4].dest = 3;
    edges[4].weight = 4;
    kruskalMST(edges, V, E);
    return 0;
}
