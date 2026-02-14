#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} tree;

// Create a new node
tree *create_node(int key) {
    tree *newnode = (tree *)malloc(sizeof(tree));
    if (!newnode) {
        perror("malloc failed");
        exit(1);
    }
    newnode->data = key;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Insert into BST
void insert(tree **root, int key) {
    if (*root == NULL) {
        *root = create_node(key);
        return;
    }

    if (key < (*root)->data) {
        insert(&(*root)->left, key);
    } else if (key > (*root)->data) {
        insert(&(*root)->right, key);
    }
    // if key == (*root)->data, you can decide to ignore or handle duplicates
}

// Height of tree
int height(tree *p) {
    if (p == NULL) return 0;  // IMPORTANT base case

    int x = height(p->left);
    int y = height(p->right);
    return x > y ? x + 1 : y + 1;
}

// Inorder predecessor: max in left subtree
tree *inorder_pre(tree *p) {
    if (!p || !p->left) return NULL;
    p = p->left;
    while (p->right != NULL) {
        p = p->right;
    }
    return p;
}

// Inorder successor: min in right subtree
tree *inorder_succ(tree *p) {
    if (!p || !p->right) return NULL;
    p = p->right;
    while (p->left != NULL) {
        p = p->left;
    }
    return p;
}

// Find a key and print its inorder successor (if any)
tree *find(tree *root, int key) {
    if (root == NULL) {
        printf("not found\n");
        return NULL;
    }

    if (key < root->data) {
        return find(root->left, key);
    } else if (key > root->data) {
        return find(root->right, key);
    } else {
        // Found
        tree *succ = inorder_succ(root);
        if (succ)
            printf("data found, inorder successor = %d\n", succ->data);
        else
            printf("data found, no inorder successor\n");
        return root;
    }
}

// Delete a node from BST
tree *delete_node(tree *root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data) {
        root->left = delete_node(root->left, key);
    } else if (key > root->data) {
        root->right = delete_node(root->right, key);
    } else {
        // Node found
        if (root->left == NULL && root->right == NULL) {
            // leaf
            free(root);
            return NULL;
        } else if (root->left && root->right) {
            // two children – choose pred or succ based on height
            if (height(root->left) > height(root->right)) {
                tree *q = inorder_pre(root);
                root->data = q->data;
                root->left = delete_node(root->left, q->data);
            } else {
                tree *q = inorder_succ(root);
                root->data = q->data;
                root->right = delete_node(root->right, q->data);
            }
        } else {
            // one child
            tree *child = root->left ? root->left : root->right;
            free(root);
            return child;
        }
    }
    return root;
}

// Inorder traversal for checking
void inorder(tree *p) {
    if (!p) return;
    inorder(p->left);
    printf("%d ", p->data);
    inorder(p->right);
}

int main() {
    tree *root = NULL;
    int key;

    // Insert 10 keys from user
    for (int i = 0; i < 10; i++) {
        printf("enter key: ");
        if (scanf("%d", &key) != 1) {
            printf("invalid input\n");
            return 1;
        }
        insert(&root, key);
    }

    printf("Inorder traversal: ");
    inorder(root);
    printf("\nHeight: %d\n", height(root));

    printf("Enter key to search: ");
    if (scanf("%d", &key) == 1) {
        find(root, key);
    }

    printf("Enter key to delete: ");
    if (scanf("%d", &key) == 1) {
        root = delete_node(root, key);
    }

    printf("Inorder after delete: ");
    inorder(root);
    printf("\n");

    return 0;
}
