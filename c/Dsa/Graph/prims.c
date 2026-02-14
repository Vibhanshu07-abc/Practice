#include <stdio.h>
#include <stdlib.h>
#include <limits.h>   // INT_MAX

// Node for adjacency list
typedef struct node {
    int vertex;
    int weight;
    struct node *next;
} Node;

// Adjacency list type
typedef struct {
    Node *head;
} List;

// Undirected edge add karne ka function
void addEdge(List *adj[], int u, int v, int w) {
    // u -> v
    Node *n1 = (Node *)malloc(sizeof(Node));
    n1->vertex = v;
    n1->weight = w;
    n1->next = adj[u]->head;
    adj[u]->head = n1;
    // v -> u
    Node *n2 = (Node *)malloc(sizeof(Node));
    n2->vertex = u;
    n2->weight = w;
    n2->next = adj[v]->head;
    adj[v]->head = n2;
}

void prim(List *adj[], int n, int start) {

    int key[n];  
    int parent[n];  
    int inMST[n];  
    // Initialization
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        inMST[i] = 0;    
    }
    key[start] = 0; // start vertex ka key 0
    for (int j = 0; j < n; j++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && (u == -1 || key[v] < key[u]))
                u = v;
        }

        if (u == -1) break; // koi reachable vertex na ho toh break
        inMST[u] = 1;       // include u in MST

        // update keys of neighbours
        Node *t = adj[u]->head;
        while (t) {
            int v = t->vertex;
            int w = t->weight;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
            t = t->next;
        }
    }

    // Print MST edges and total weight
    printf("Prim MST edges:\n");
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            printf(" %d -- %d (w=%d)\n", parent[i], i, key[i]);
            total += key[i];
        }
    }
    printf("Total MST weight = %d\n", total);
}

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 0;
    printf("Enter number of edges: ");
    if (scanf("%d", &m) != 1) return 0;

    // adjacency list array dynamically allocate karo
    // yaha har vertex ke liye ek List* hoga
    List **adj = (List **)malloc(n * sizeof(List *));
    for (int i = 0; i < n; i++) {
        adj[i] = (List *)malloc(sizeof(List));
        adj[i]->head = NULL;
    }

    printf("Enter edges (u v w) 0-based indices:\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
    }

    int start;
    printf("Start vertex for Prim: ");
    scanf("%d", &start);

    prim(adj, n, start);

    // free adjacency lists
    for (int i = 0; i < n; i++) {
        Node *t = adj[i]->head;
        while (t) {
            Node *tmp = t;
            t = t->next;
            free(tmp);
        }
        free(adj[i]);   // List struct ko bhi free karo
    }
    free(adj);          // array of List* ko free karo

    return 0;
}
