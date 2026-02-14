// dijkstra_dynamic.c
// Dijkstra's shortest path using adjacency list (dynamic memory)
// Hinglish comments for beginners

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>   // INT_MAX

// Adjacency list node (weighted)
typedef struct node {
    int vertex;
    int weight;
    struct node *next;
} Node;

typedef struct {
    Node *head;
} List;

// Add undirected edge (u <-> v)
void addEdge(List *adj, int u, int v, int w) {
    Node *n1 = malloc(sizeof(Node));
    n1->vertex = v;
    n1->weight = w;
    n1->next = adj[u].head;
    adj[u].head = n1;

    Node *n2 = malloc(sizeof(Node));
    n2->vertex = u;
    n2->weight = w;
    n2->next = adj[v].head;
    adj[v].head = n2;
}

// Dijkstra algorithm (O(n^2) version, simple and easy to understand)
void dijkstra(List *adj, int n, int src) {
    int *dist = malloc(n * sizeof(int));      // shortest known distances
    int *visited = calloc(n, sizeof(int));    // visited set

    // init
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    // repeat n times (pick minimum distance vertex not visited)
    for (int iter = 0; iter < n; iter++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && (u == -1 || dist[v] < dist[u]))
                u = v;
        }

        if (u == -1 || dist[u] == INT_MAX) break; // remaining unreachable
        visited[u] = 1;

        // relax edges from u
        Node *t = adj[u].head;
        while (t) {
            int v = t->vertex;
            int w = t->weight;
            if (dist[u] + w < dist[v]) dist[v] = dist[u] + w;
            t = t->next;
        }
    }

    // print result
    printf("Vertex : Distance from source %d\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) printf(" %d : INF\n", i);
        else printf(" %d : %d\n", i, dist[i]);
    }

    free(dist);
    free(visited);
}

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 0;
    printf("Enter number of edges: ");
    if (scanf("%d", &m) != 1) return 0;

    List *adj = calloc(n, sizeof(List));
    for (int i = 0; i < n; i++) adj[i].head = NULL;

    printf("Enter edges (u v w) 0-based indices (undirected):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
    }

    int src;
    printf("Source vertex: ");
    scanf("%d", &src);

    dijkstra(adj, n, src);

    // free adjacency lists
    for (int i = 0; i < n; i++) {
        Node *t = adj[i].head;
        while (t) {
            Node *tmp = t;
            t = t->next;
            free(tmp);
        }
    }
    free(adj);
    return 0;
}
