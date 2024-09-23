#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node 
{
    int dest;
    struct Node* next;
};

struct AdjList 
{
    struct Node* head;
};

struct Node* createNode(int dest) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct AdjList adj[], int s, int t) 
{
    struct Node* newNode = createNode(t);
    newNode->next = adj[s].head;
    adj[s].head = newNode;

    newNode = createNode(s);
    newNode->next = adj[t].head;
    adj[t].head = newNode;
}

void printGraph(struct AdjList adj[], int V) 
{
    for (int i = 0; i < V; i++) 
    {
        struct Node* current = adj[i].head;
        printf("%d -> ", i);
        while (current != NULL) 
        {
            printf("%d ", current->dest);
            current = current->next;
        }
        printf("\n");
    }
}

void BFS(struct AdjList adj[], int V, int s) 
{
    int visited[V];
    for (int i = 0; i < V; i++) 
    {
        visited[i] = 0;
    }

    int queue[V];
    int front = 0, rear = 0;

    visited[s] = 1;
    printf("%d ", s);
    queue[rear++] = s;

    while (front < rear) 
    {
        int current = queue[front++];
        struct Node* temp = adj[current].head;
        while (temp != NULL) 
        {
            int dest = temp->dest;
            if (!visited[dest]) 
            {
                visited[dest] = 1;
                printf("%d ", dest);
                queue[rear++] = dest;
            }
            temp = temp->next;
        }
    }
}

int main() 
{
    srand(time(NULL));
    const int V = 5;
    struct AdjList adj[V];

    for (int i = 0; i < V; i++) 
    {
        adj[i].head = NULL;
    }
    
    int E = rand() % (V * (V - 1) / 2) + 1;
    int edges[E][2];

    for (int i = 0; i < E; i++) 
    {
        int src = rand() % V;
        int dest = rand() % V;
        while (src == dest) 
        {
            dest = rand() % V;
        }
        int duplicate = 0;
        for (int j = 0; j < i; j++) 
        {
            if ((edges[j][0] == src && edges[j][1] == dest) || 
                (edges[j][0] == dest && edges[j][1] == src)) 
            {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate) 
        {
            edges[i][0] = src;
            edges[i][1] = dest;
            addEdge(adj, src, dest);
        } 
        else 
        {
            i--;
        }
    }

    printf("Graph adjacency list:\n");
    printGraph(adj, V);

    int source = rand() % V;
    printf("BFS from source: %d\n", source);
    BFS(adj, V, source);
    printf("\n");
    system("PAUSE");
    return 0;
}
