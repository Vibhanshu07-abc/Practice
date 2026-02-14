// kruskal_minheap.c
// Kruskal using Linked List to store edges + Min Heap to pick min edges
// Beginner-friendly version (easy logic + Hinglish comments)

#include <stdio.h>
#include <stdlib.h>

// ============ EDGE NODE (Linked List) ============
typedef struct edge {
    int src, dst, wt;
    struct edge *next;
} edge;

// Insert edge node at END of linked list
void addEdge(edge **head, int u, int v, int w) {
    edge *newNode = (edge*)malloc(sizeof(edge));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->src = u;
    newNode->dst = v;
    newNode->wt  = w;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    edge *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Print Linked List of edges
void printEdges(edge *head) {
    if (!head) {
        printf("No edges entered yet.\n");
        return;
    }
    printf("Edges (u -- v : w):\n");
    edge *t = head;
    while (t) {
        printf(" %d -- %d : %d\n", t->src, t->dst, t->wt);
        t = t->next;
    }
}

// ============ UNION-FIND (Disjoint Set) ============
int findParent(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = findParent(parent, parent[x]); // path compression
    return parent[x];
}

void unionSet(int parent[], int rankv[], int a, int b) {
    int pa = findParent(parent, a);
    int pb = findParent(parent, b);

    if (pa == pb) return;

    // union by rank
    if (rankv[pa] < rankv[pb]) parent[pa] = pb;
    else if (rankv[pb] < rankv[pa]) parent[pb] = pa;
    else {
        parent[pb] = pa;
        rankv[pa]++;
    }
}

// ========== Convert Linked List to Array (for heap) ==========
edge* listToArray(edge *head, int m) {
    if (m == 0) return NULL;

    edge *arr = (edge*)malloc(m * sizeof(edge));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    edge *t = head;
    int i = 0;
    while (t && i < m) {
        arr[i] = *t;      // copy struct
        arr[i].next = NULL; // linked list pointer not needed in array
        t = t->next;
        i++;
    }
    return arr;
}

// ===================== MIN HEAP ON EDGES =====================
// Heap based on wt (weight)

void swapEdge(edge *a, edge *b) {
    edge temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify from index i in array of size n (min-heap)
void heapify(edge arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1; // left child index
    int r = 2 * i + 2; // right child index

    if (l < n && arr[l].wt < arr[smallest].wt)
        smallest = l;
    if (r < n && arr[r].wt < arr[smallest].wt)
        smallest = r;

    if (smallest != i) {
        swapEdge(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// Build min-heap from an array
void buildMinHeap(edge arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Extract minimum edge from heap
edge extractMin(edge arr[], int *n) {
    edge root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return root;
}

// ===================== KRUSKAL USING MIN HEAP =====================
void kruskal(edge *head, int n, int m) {
    if (!head || m == 0) {
        printf("No edges available.\n");
        return;
    }

    // Linked List → Array (so we can make a heap)
    edge *arr = listToArray(head, m);
    if (!arr) return;

    // Build Min Heap based on weights
    int heapSize = m;
    buildMinHeap(arr, heapSize);

    // Make-set for Union-Find
    int *parent = (int*)malloc(n * sizeof(int));
    int *rankv  = (int*)calloc(n, sizeof(int));

    if (!parent || !rankv) {
        printf("Memory allocation failed!\n");
        free(arr);
        if (parent) free(parent);
        if (rankv) free(rankv);
        return;
    }

    for (int i = 0; i < n; i++) parent[i] = i;

    printf("\nKruskal MST edges (using Min-Heap):\n");
    int mstWeight = 0, taken = 0;

    // Jab tak heap khali nahi ho jata aur MST complete nahi hota
    while (heapSize > 0 && taken < n - 1) {
        edge e = extractMin(arr, &heapSize);   // O(log m)
        int u = e.src;
        int v = e.dst;
        int w = e.wt;

        int pu = findParent(parent, u);
        int pv = findParent(parent, v);

        // Agar alag components mein hai, to include in MST
        if (pu != pv) {
            printf(" %d -- %d (w=%d)\n", u, v, w);
            mstWeight += w;
            taken++;
            unionSet(parent, rankv, pu, pv);
        }
        // Agar same component, ignore (cycle banega)
    }

    if (taken != n - 1) {
        printf("MST NOT possible → Graph disconnected!\n");
    } else {
        printf("Total MST Weight = %d\n", mstWeight);
    }

    free(arr);
    free(parent);
    free(rankv);
}

// ===================== FREE LINKED LIST =====================
void freeList(edge *head) {
    while (head) {
        edge *tmp = head;
        head = head->next;
        free(tmp);
    }
}

// ===================== MAIN MENU =====================
int main() {
    int n, mChoice = 0;
    edge *head = NULL;  // Linked list head

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    while (1) {
        printf("\n===== MENU =====\n");
        printf("1. Add Edge (Linked List)\n");
        printf("2. Print Edges\n");
        printf("3. Run Kruskal MST (Min-Heap)\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        int ch; 
        scanf("%d", &ch);

        if (ch == 1) {
            int u, v, w;
            printf("Enter u v w: ");
            scanf("%d %d %d", &u, &v, &w);

            if (u < 0 || u >= n || v < 0 || v >= n) {
                printf("Invalid vertices!\n");
                continue;
            }

            addEdge(&head, u, v, w);
            mChoice++;
            printf("Edge added.\n");
        }
        else if (ch == 2) {
            printEdges(head);
        }
        else if (ch == 3) {
            kruskal(head, n, mChoice);
        }
        else if (ch == 4) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    freeList(head);
    return 0;
}
