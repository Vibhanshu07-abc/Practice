#include<stdio.h>
#include<stdlib.h>
#define max 10
int push(int stack[],int item,int top){
    if (top==max-1){
        printf("overflow\n");
        return top;
    }
    else{
      top++;
     stack[top] =item;
     return top;
    }
}
int pop(int stack[],int top){
    int value;
    if (top==-1){
        printf("underflow\n");
        return top;
    }
    else{
        value=stack[top];
        printf("value to be popped is %d\n",value);
        top--;
        return top;
    }
}
void peek(int stack[],int top){
    int value;
    if(top==-1){
        printf("stack empty\n");
    }
    else{
       value=stack[top] ;
       printf("current value of stack is %d\n",value);
    }
}
void display(int stack[],int top){
    int i;
    if(top==-1){
        printf("stack is empty\n");
    }
    else{ i=top;
        while(i>=0){
            printf("  %d",stack[i]);
            printf("\n");
            i--;
        }
    }
}

int main(){
int stack[max];
int value;
int ch;
int top=-1;
do{
    printf("enter the choice 1: push 2:peek 3:pop 4:display 5:exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1: 
        printf("enter value to be pushed\n");
        scanf("%d",&value);
       top= push(stack,value,top);
       break;
       case 2:
       peek(stack,top);
       break;
       case 3:
       top=pop(stack,top);
       break;
       case 4:
       display(stack,top);
       break;
       case 5:
       exit(0);
       default: 
       printf("invalid input");
       break;
    }
}while(1);
}