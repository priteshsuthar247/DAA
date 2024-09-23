#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_V 100
#define UPPER_BOUND 1000
#define LOWER_BOUND 100

typedef struct 
{
    int src, dest, weight;
} Edge;

int compareEdges(const void *a, const void *b) 
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int find(int parent[], int i) 
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSets(int parent[], int x, int y) 
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    if (xset != yset)
        parent[xset] = yset;
}

void kruskalMST(int graph[MAX_V][MAX_V], int V) 
{
    Edge edges[MAX_V * (MAX_V - 1) / 2];
    int edgeCount = 0;

    for (int i = 0; i < V; i++) 
    {
        for (int j = i + 1; j < V; j++) 
        {
            if (graph[i][j] > 0) 
            {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }

    qsort(edges, edgeCount, sizeof(edges[0]), compareEdges);

    int parent[MAX_V];
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    printf("Edge \tWeight\n");
    for (int i = 0; i < edgeCount; i++) 
    {
        int x = find(parent, edges[i].src);
        int y = find(parent, edges[i].dest);

        if (x != y) 
        {
            printf("%d - %d \t%d\n", edges[i].src, edges[i].dest, edges[i].weight);
            unionSets(parent, x, y);
        }
    }
}

void printGraph(int graph[MAX_V][MAX_V], int V) 
{
    printf("Graph (Edges with Weights):\n");
    for (int i = 0; i < V; i++) 
    {
        for (int j = i + 1; j < V; j++) 
        {
            if (graph[i][j] > 0)
                printf("%d - %d: %d\n", i, j, graph[i][j]);
        }
    }
}

int main() 
{
    srand(time(NULL));
    int V = rand() % (10 - 0 + 1) + 0;
    int graph[MAX_V][MAX_V] = {0};

    for (int i = 0; i < V; i++) 
    {
        for (int j = i + 1; j < V; j++) 
        {
            if (rand() % 2) 
            {
                int weight = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;
                graph[i][j] = weight;
                graph[j][i] = weight;
            }
        }
    }

    printGraph(graph, V);
    printf("\n");
    kruskalMST(graph, V);
    printf("\n");
    system("PAUSE");
    return 0;
}
