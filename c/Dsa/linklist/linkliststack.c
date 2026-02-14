#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int data;
    struct stack *next;
} st;

st* pop(st *top) {
    st *p1 = top;
    if (p1 == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Node to be deleted is %d\n", top->data);
        top = top->next;
        free(p1);
    }
    return top;
}

st* push(st *top, int value) {
    st *temp = (st*)malloc(sizeof(st));
    if (temp == NULL) {
        printf("Stack is full\n");
    } else {
        temp->data = value;
        temp->next = top;
        top = temp;
    }
    return top;
}

void display(st *top) {
    st *temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    int value;
    st *top = NULL;
    do {
        printf("Enter choice: 1 to push, 2 to pop, 3 to display, 4 to exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &value);
                top = push(top, value);
                break;
            case 2: 
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);
    return 0;
}
