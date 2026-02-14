#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
} tree;

// Utility functions
int max(int a, int b) {
    return a > b ? a : b;
}

int getheight(tree *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getbf(tree *node) {
    if (node == NULL)
        return 0;
    return getheight(node->left) - getheight(node->right);
}

tree *create(int key) {
    tree *newnode = (tree *)malloc(sizeof(tree));
    newnode->data = key;
    newnode->left = newnode->right = NULL;
    newnode->height = 1; // leaf node
    return newnode;
}

// Right rotate subtree rooted with y
tree *rightrotate(tree *y) {
    tree *x = y->left;
    tree *T2 = x->right;
    // Perform rotation
    x->right = y;
    y->left = T2;
    // Update heights
    y->height = 1 + max(getheight(y->left), getheight(y->right));
    x->height = 1 + max(getheight(x->left), getheight(x->right));
    // New root
    return x;
}
   // Left rotate subtree rooted with x
tree *leftrotate(tree *x) {
    tree *y = x->right;
    tree *T2 = y->left;
    // Perform rotation
    y->left = x;
    x->right = T2;
    // Update heights
    x->height = 1 + max(getheight(x->left), getheight(x->right));
    y->height = 1 + max(getheight(y->left), getheight(y->right));
    // New root
    return y;
}

tree *insert(tree *node, int key) {
    // 1. Normal BST insertion
    if (node == NULL)
        return create(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        // Equal keys not allowed (or handle as you wish)

        return node;
    // 2. Update height of this ancestor node

    node->height = 1 + max(getheight(node->left), getheight(node->right));

    // 3. Get the balance factor
    int bf = getbf(node);
    // 4. If node becomes unbalanced, then there are 4 cases:
    // Left Left Case
    if (bf > 1 && key < node->left->data)
        return rightrotate(node);
    // Right Right Case
    if (bf < -1 && key > node->right->data)
        return leftrotate(node);

    // Left Right Case
    if (bf > 1 && key > node->left->data) {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }

    // Right Left Case
    if (bf < -1 && key < node->right->data) {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }

    // 5. Return the (unchanged) node pointer
    return node;
}

// Simple inorder traversal to test
void inorder(tree *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    tree *root = NULL;
    int arr[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    printf("Inorder traversal of AVL tree:\n");
    inorder(root);
    printf("\n");
    return 0;
}
