#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_V 100
#define UPPER_BOUND 1000
#define LOWER_BOUND 100

int minKey(int key[], bool mstSet[], int V) 
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int graph[MAX_V][MAX_V], int V) 
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[MAX_V][MAX_V], int V) 
{
    int parent[MAX_V];
    int key[MAX_V];
    bool mstSet[MAX_V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) 
    {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, V);
}

void printGraph(int graph[MAX_V][MAX_V], int V) 
{
    printf("Graph (Edges with Weights):\n");
    for (int i = 0; i < V; i++) 
    {
        for (int j = i + 1; j < V; j++) 
        {
            if (graph[i][j] != 0)
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
    primMST(graph, V);
    printf("\n");
    system("PAUSE");
    return 0;
}
