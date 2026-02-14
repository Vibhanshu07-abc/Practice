#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int vertex;
    struct node *next;
} vertex;

typedef struct list {
    vertex *head;
} list;

/* ========== ADD EDGE ========== */
void add(list *adj[], int src, int dst) {
    vertex *newNode = (vertex *)malloc(sizeof(vertex));
    newNode->vertex = dst;
    newNode->next = NULL;

    if (adj[src]->head == NULL) {
        adj[src]->head = newNode;
        return;
    }

    vertex *temp = adj[src]->head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

/* ========== PRINT GRAPH ========== */
void print(list *adj[], int n) {
    for (int i = 0; i < n; i++) {
        vertex *temp = adj[i]->head;
        printf("The vertices connected to %d are:\n", i);
        while (temp) {
            printf("\t%d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

/* ========== BFS WITH visited = -1 ========== */
void bfs(list *adj[], int start, int n) {

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = -1;       // -1 = unvisited

    int queue[n];
    int front = 0, rear = 0;

    visited[start] = 1;        // mark start as visited
    queue[rear++] = start;

    printf("BFS starting from %d: ", start);

    while (front < rear) {
        int v = queue[front++];   // dequeue
        printf("%d ", v);

        vertex *temp = adj[v]->head;
        while (temp) {
            int adjver = temp->vertex;
            if (visited[adjver] == -1) {   // unvisited
                visited[adjver] = 1;       // mark visited
                queue[rear++] = adjver;    // enqueue
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

/* ========== MAIN ========== */
int main() {
    int i, n, ch, src, dst;
    printf("Enter the number of vertices: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of vertices\n");
        return 1;
    }

    list *adj[n];
    for (i = 0; i < n; i++) {
        adj[i] = (list *)malloc(sizeof(list));
        adj[i]->head = NULL;
    }

    while (1) {
        printf("\nEnter:\n 1. Add edge\n 2. Print graph\n 3. Exit\n 4. BFS Traversal\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the source of edge: ");
                scanf("%d", &src);
                printf("Enter the destination of edge: ");
                scanf("%d", &dst);
                if (src < 0 || src >= n || dst < 0 || dst >= n) {
                    printf("Vertex out of range (0..%d)\n", n - 1);
                } else {
                    add(adj, src, dst);
                }
                break;

            case 2:
                print(adj, n);
                break;

            case 3:
                printf("\nExiting...\n");
                for (i = 0; i < n; i++) {
                    vertex *cur = adj[i]->head;
                    while (cur) {
                        vertex *tmp = cur;
                        cur = cur->next;
                        free(tmp);
                    }
                    free(adj[i]);
                }
                return 0;

            case 4:
                printf("Enter BFS start vertex: ");
                scanf("%d", &src);
                if (src < 0 || src >= n)
                    printf("Invalid start vertex\n");
                else
                    bfs(adj, src, n);
                break;

            default:
                printf("Invalid choice\n");
        }
    }
}
