#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int push1(int top1, int top2, int arr[], int value) {
    if ((top1 + 1) == top2) {
        printf("Stack is full (Overflow):\n");
    } else {
        top1 = top1 + 1;
        arr[top1] = value;
    }
    return top1;
}

int push2(int top1, int top2, int arr[], int value) {
    if ((top2 - 1) == top1) {
        printf("Stack is full (Overflow):\n");
    } else {
        top2 = top2 - 1;
        arr[top2] = value;
    }
    return top2;
}

int pop1(int top1, int arr[]) {
    int value;
    if (top1 == -1) {
        printf("Stack 1 is empty (Underflow):\n");
    } else {
        value = arr[top1];
        printf("Value popped from Stack 1 is %d\n", value);
        top1--;
    }
    return top1;
}

int pop2(int top2, int arr[], int N) {
    if (top2 == N) {
        printf("Stack 2 is empty (Underflow):\n");
    } else {
        int value = arr[top2];
        printf("Value popped from Stack 2 is %d\n", value);
        top2 = top2 + 1;
    }
    return top2;
}

void display1(int arr[], int top1) {
    if (top1 == -1) {
        printf("Stack 1 is empty\n");
    } else {
        printf("Stack 1 elements:\n");
        for (int i = 0; i <= top1; i++) {
            printf(" %d\n", arr[i]);
        }
    }
}

void display2(int arr[], int top2, int N) {
    if (top2 == N) {
        printf("Stack 2 is empty\n");
    } else {
        printf("Stack 2 elements:\n");
        for (int i = N - 1; i >= top2; i--) {
            printf(" %d\n", arr[i]);
        }
    }
}

int main() {
    int arr[MAX];
    int N;
    printf("Enter the size of array (max %d):\n", MAX);
    scanf("%d", &N);

    int top1 = -1;
    int top2 = N;
    int choice, value;

    do {
        printf("\nEnter choice:\n");
        printf("1. Push in Stack 1\n");
        printf("2. Push in Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Display Stack 1\n");
        printf("6. Display Stack 2\n");
        printf("7. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push into Stack 1:\n");
                scanf("%d", &value);
                top1 = push1(top1, top2, arr, value);
                break;
            case 2:
                printf("Enter value to push into Stack 2:\n");
                scanf("%d", &value);
                top2 = push2(top1, top2, arr, value);
                break;
            case 3:
                top1 = pop1(top1, arr);
                break;
            case 4:
                top2 = pop2(top2, arr, N);
                break;
            case 5:
                display1(arr, top1);
                break;
            case 6:
                display2(arr, top2, N);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}
