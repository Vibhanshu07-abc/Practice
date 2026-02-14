#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int vertex;
    struct node *next;
} vertex;

typedef struct list {
    vertex *head;
} list;

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
void print(list *adj[], int n) {
    for (int i = 0; i < n; i++) {
        vertex *temp = adj[i]->head;
        printf("the vertex connected to %d are\n", i);
        while (temp) {
            printf("\t%d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main() {
    int i, n, ch, src, dst;
    printf("enter the number of vertices: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("invalid number of vertices\n");
        return 1;
    }
    list *adj[n];
    for (i = 0; i < n; i++) {
        adj[i] = (list *)malloc(sizeof(list));
        adj[i]->head = NULL;
    }
    while (1) {
        printf("enter \t 1.add edge\t2.print\t3.exit\n ");
        scanf("%d", &ch); 
        switch (ch) {
            case 1:
                printf("enter the source of edge :\t");
                scanf("%d", &src);
                printf("enter the destination of edge :\t");
                scanf("%d", &dst);
                if (src < 0 || src >= n || dst < 0 || dst >= n) {
                    printf("vertex out of range (0..%d)\n", n - 1);
                } else {
                    add(adj, src, dst);
                }
                break;
            case 2:
                print(adj, n);
                break;
            case 3:
                printf("\nexiting...\n");
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
            default:
                printf("invalid\n");
        }
    }
}
