#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} l;

l* insertEndCircular(l* head, int value, l** tail) {
    l* newnode = (l*) malloc(sizeof(l));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        *tail = newnode;
        // For a single-node circular list, newnode->next should point to itself
        newnode->next = head;
    } else {
        (*tail)->next = newnode;
        *tail = newnode;
        (*tail)->next = head;
    }
    return head;
}

void display(l* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    l* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
/*
 * Reverses a circular singly linked list.
 * The function updates the head and tail pointers after reversal.
 * For a circular list, each node's next pointer is reversed, and the new head becomes the previous tail.
 * If the list is empty or has only one node, reversal is not performed.
 */
void reverse(l** head, l** tail) {
    if (*head == NULL || (*head)->next == *head) {
        printf("Cannot reverse: list is empty or has only one node.\n");
        return;
    }

    l* prev = *tail; // Start with tail as previous node
    l* current = *head; // Start with head as current node
    l* next = current->next; // Store next node

    // Traverse the circular list and reverse the next pointers
    do {
        current->next = prev;
        prev = current;
        current = next;
        next = current->next;
    } while (current != *head);

    // Update head and tail pointers after reversal
    *tail = *head;
    *head = prev;
}

int main() {
    l* head = NULL;
    l* tail = NULL;
    int n, value;

    printf("Enter the number of elements to be inserted in the linked list:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the value to be inserted:\n");
        scanf("%d", &value);
        head = createnode(head, value, &tail);
    }

    printf("The circular linked list is:\n");
        head = insertEndCircular(head, value, &tail);
    reverse(&head, &tail);
    printf("The reversed circular linked list is:\n");
    display(head);
    return 0;
}
