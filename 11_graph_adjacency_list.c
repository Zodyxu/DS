#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Node structure
struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *adjList[MAX];

// Create new node
struct Node* createNode(int v)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->vertex = v;
    newNode->next = NULL;

    return newNode;
}

// Add edge
void addEdge(int src, int dest)
{
    struct Node *newNode;

    // Add edge src -> dest
    newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // Add edge dest -> src (Undirected graph)
    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// Display adjacency list
void display(int vertices)
{
    int i;
    struct Node *temp;

    printf("\nAdjacency List:\n");

    for(i = 0; i < vertices; i++)
    {
        printf("%d -> ", i);

        temp = adjList[i];

        while(temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int vertices, edges;
    int i, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Initialize adjacency list
    for(i = 0; i < vertices; i++)
    {
        adjList[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Input edges
    for(i = 0; i < edges; i++)
    {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);

        addEdge(src, dest);
    }

    display(vertices);

    return 0;
}
