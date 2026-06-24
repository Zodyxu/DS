#include <stdio.h>

#define MAX 10

int main()
{
    int graph[MAX][MAX];
    int vertices, edges;
    int i, j, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Initialize matrix with 0
    for(i = 0; i < vertices; i++)
    {
        for(j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Input edges
    for(i = 0; i < edges; i++)
    {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);

        graph[src][dest] = 1;
        graph[dest][src] = 1; // Undirected graph
    }

    // Display adjacency matrix
    printf("\nAdjacency Matrix:\n");

    for(i = 0; i < vertices; i++)
    {
        for(j = 0; j < vertices; j++)
        {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }

    return 0;
}
