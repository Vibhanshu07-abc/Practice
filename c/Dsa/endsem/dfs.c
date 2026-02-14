#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} vertex;

typedef struct list {
    vertex *head;
} list;

void add_edge(list *adj[], int src, int dst) {
    vertex *newnode = (vertex *)malloc(sizeof(vertex));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = dst;
    newnode->next = NULL;

    if (adj[src]->head == NULL) {
        adj[src]->head = newnode;
    } else {
        vertex *temp = adj[src]->head;
        while (temp->next != NULL) {   // go to last node
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void enqueue(int *rear, int data, int queue[]) {
    queue[(*rear)++] = data;   // insert then increment rear
}

int dequeue(int *front, int queue[]) {
    return queue[(*front)++];  // return then increment front
}

void bfs(list *adj[], int start, int n) {
    int *visited = (int *)calloc(n, sizeof(int));
    int *queue   = (int *)malloc(n * sizeof(int));

    if (!visited || !queue) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int front = 0, rear = 0;

    visited[start] = 1;
    enqueue(&rear, start, queue);

    printf("BFS traversal starting from %d: ", start);

    while (front < rear) {
        int v = dequeue(&front, queue);
        printf("%d ", v);

        vertex *temp = adj[v]->head;
        while (temp != NULL) {
            int u = temp->data;
            if (!visited[u]) {
                visited[u] = 1;
                enqueue(&rear, u, queue);
            }
            temp = temp->next;
        }
    }
    printf("\n");
    
    free(visited);
    free(queue);
}

int main() {
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    list *adj[n];
    for (int i = 0; i < n; i++) {
        adj[i] = (list *)malloc(sizeof(list));
        adj[i]->head = NULL;   // VERY important
    }

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter edges as: src dst (0-based indices)\n");
    for (int i = 0; i < e; i++) {
        int src, dst;
        scanf("%d %d", &src, &dst);
        add_edge(adj, src, dst);

        // If the graph is undirected, also do:
        // add_edge(adj, dst, src);
    }

    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    bfs(adj, start, n);

    // Optional: free all allocated memory
    for (int i = 0; i < n; i++) {
        vertex *temp = adj[i]->head;
        while (temp != NULL) {
            vertex *next = temp->next;
            free(temp);
            temp = next;
        }
        free(adj[i]);
    }

    return 0;
}
