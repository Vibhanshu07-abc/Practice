#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} link;

//  correct iterative reverse function
link* reverseList(link *head) {
    link *prev = NULL;
    link *current = head;
    link *next = NULL;

    while (current != NULL) {
        next = current->next;        // pehle next ka address save karo
        current->next = prev;        // link ko reverse karo
        prev = current;              // prev ko aage seedha karo
        current = next;              // current ko update karo
    }
    return prev;  // prev ab nayi list ka head
}

// traversal function
void traversal(link *head) {
    link *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(void) {
    link *head = NULL, *temp = NULL, *newnode = NULL;
    int choice = 1;

    // insertion loop
    while (choice == 1) {
        newnode = malloc(sizeof(link));
        if (newnode == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Enter 1 to continue, 2 to stop: ");
        scanf("%d", &choice);
    }

    printf("\nOriginal list:\n");
    traversal(head);

    head = reverseList(head);  // yahan reverseList se head mil raha hai
    printf("\nReversed list:\n");
    traversal(head);
    return 0;
}
