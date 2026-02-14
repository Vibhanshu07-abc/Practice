#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100   // maximum vertices
#define MAXE 1000 // maximum edges

// -------------------- NODE OF ADJACENCY LIST --------------------
typedef struct node {
    int vertex;
    int weight;
    struct node *next;
} Node;

// -------------------- GRAPH LIST FOR EACH VERTEX --------------------
typedef struct {
    Node *head;
} List;

// -------------------- EDGE STRUCT FOR KRUSKAL --------------------
typedef struct {
    int src, dst, wt;
} Edge;

// ================================================================
// ADDING UNDIRECTED EDGE
// ================================================================
void addEdge(List adj[], Edge edges[], int *edgeCount,
             int src, int dst, int wt)
{
    // add src -> dst
    Node *n1 = (Node*)malloc(sizeof(Node));
    n1->vertex = dst;
    n1->weight = wt;
    n1->next = adj[src].head;
    adj[src].head = n1;

    // add dst -> src (undirected graph)
    Node *n2 = (Node*)malloc(sizeof(Node));
    n2->vertex = src;
    n2->weight = wt;
    n2->next = adj[dst].head;
    adj[dst].head = n2;

    // store edge once (for Kruskal)
    edges[*edgeCount].src = src;
    edges[*edgeCount].dst = dst;
    edges[*edgeCount].wt = wt;
    (*edgeCount)++;
}

// ================================================================
// PRINT GRAPH
// ================================================================
void printGraph(List adj[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node *t = adj[i].head;
        while (t) {
            printf(" -> (%d, w=%d)", t->vertex, t->weight);
            t = t->next;
        }
        printf("\n");
    }
}

// ================================================================
// BFS
// ================================================================
void bfs(List adj[], int start, int n)
{
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS: ");

    while (front < rear) {
        int v = queue[front++];   // dequeue
        printf("%d ", v);

        Node *t = adj[v].head;
        while (t) {
            int nbr = t->vertex;
            if (!visited[nbr]) {
                visited[nbr] = 1;
                queue[rear++] = nbr;
            }
            t = t->next;
        }
    }
    printf("\n");
}

// ================================================================
// KRUSKAL'S MST (BEGINNER VERSION)
// ================================================================
int findParent(int parent[], int x)
{
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void kruskal(Edge edges[], int edgeCount, int n)
{
    // sort edges by weight (very simple bubble sort for beginners)
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].wt > edges[j + 1].wt) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int parent[MAX];
    for (int i = 0; i < n; i++) parent[i] = i;

    int mstWeight = 0;

    printf("Kruskal MST edges:\n");

    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].src;
        int v = edges[i].dst;

        int pu = findParent(parent, u);
        int pv = findParent(parent, v);

        if (pu != pv) {   // no cycle
            printf(" %d -- %d (w=%d)\n", u, v, edges[i].wt);
            parent[pu] = pv;
            mstWeight += edges[i].wt;
        }
    }

    printf("Total MST weight = %d\n", mstWeight);
}

// ================================================================
// PRIM'S MST
// ================================================================
void prim(List adj[], int n, int start)
{
    int key[MAX];
    bool inMST[MAX];
    int parent[MAX];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
        parent[i] = -1;
    }

    key[start] = 0;

    // Pick min key vertex n times
    for (int i = 0; i < n; i++) {

        int u = -1;

        for (int v = 0; v < n; v++)
            if (!inMST[v] && (u == -1 || key[v] < key[u]))
                u = v;

        inMST[u] = true;

        Node *t = adj[u].head;
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

    printf("Prim MST edges:\n");
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            printf(" %d -- %d (w=%d)\n", parent[i], i, key[i]);
            sum += key[i];
        }
    }

    printf("Total MST weight = %d\n", sum);
}

// ================================================================
// DIJKSTRA
// ================================================================
void dijkstra(List adj[], int n, int src)
{
    int dist[MAX];
    bool visited[MAX] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 0; i < n; i++) {

        int u = -1;

        for (int v = 0; v < n; v++)
            if (!visited[v] && (u == -1 || dist[v] < dist[u]))
                u = v;

        visited[u] = true;

        Node *t = adj[u].head;
        while (t) {
            int v = t->vertex;
            int w = t->weight;

            if (dist[u] + w < dist[v])
                dist[v] = dist[u] + w;

            t = t->next;
        }
    }

    printf("Dijkstra distances:\n");
    for (int i = 0; i < n; i++)
        printf(" %d → %d\n", i, dist[i]);
}

// ================================================================
// MAIN
// ================================================================
int main()
{
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    List adj[MAX];
    for (int i = 0; i < n; i++)
        adj[i].head = NULL;

    Edge edges[MAXE];
    int edgeCount = 0;

    while (1) {
        int ch;

        printf("\n1 Add Edge\n2 Print Graph\n3 BFS\n4 Kruskal\n5 Prim\n6 Dijkstra\n7 Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            int u, v, w;
            printf("Enter src dst weight: ");
            scanf("%d %d %d", &u, &v, &w);
            addEdge(adj, edges, &edgeCount, u, v, w);
        }
        else if (ch == 2) printGraph(adj, n);
        else if (ch == 3) {
            int s; printf("Start? "); scanf("%d", &s); bfs(adj, s, n);
        }
        else if (ch == 4) kruskal(edges, edgeCount, n);
        else if (ch == 5) {
            int s; printf("Start? "); scanf("%d", &s); prim(adj, n, s);
        }
        else if (ch == 6) {
            int s; printf("Source? "); scanf("%d", &s); dijkstra(adj, n, s);
        }
        else if (ch == 7) break;
        else printf("Invalid choice!\n");
    }

    return 0;
}
