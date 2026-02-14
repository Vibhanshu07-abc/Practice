#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

int precedence(char c) {
    switch(c) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

int isRightAssociative(char c) {
    return (c == '^');
}

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) {
        return '\0';
    } else {
        return stack[top--];
    }
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char ch;

    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];

        if (ch == ' ' || ch == '\t' || ch == '\n')
            continue;

        if (isalnum(ch)) {  
            postfix[j++] = ch;
        } 
        else if (ch == '(') {
            push(ch);
        } 
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        } 
        else { // Operator
            while (top != -1 && 
                  ((precedence(peek()) > precedence(ch)) ||
                  (precedence(peek()) == precedence(ch) && !isRightAssociative(ch))) &&
                  peek() != '(') {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter the infix expression: ");
    fgets(infix, MAX, stdin);
      printf("%s",infix);
    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
