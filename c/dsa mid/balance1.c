#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
char stack[max];
int top=-1;
void push(char val){
if(top==max-1){
    printf("stack is full \n");
}
else{
    stack[++top]=val;
}
}
char pop(){
    if(top==-1){
        return '\0';
    }else{
        return stack[top--];
    }
}
int ismatching(char opening,char closing){
    if(opening == '(' && closing == ')') return 1;
    if(opening == '[' && closing == ']') return 1;
    if (opening == '{' && closing == '}') return 1;
    else{
        return -1;
    }
}

int main(){
    char str[max];
    char ch;
    int i=0;
    printf("enter the string");
    gets(str);
    while(str[i]!='\0'){
        if(str[i]=='('||str[i]=='['||str[i]=='{'){
            push(str[i]);
        }
        else if(ismatching(str[top],str[i])){
              pop();
        }else{
            printf("invalid \n");
            break;
        }
        i++;
    }
    printf("string balanced \n");
}