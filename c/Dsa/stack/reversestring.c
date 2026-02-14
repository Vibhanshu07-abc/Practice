#include<stdio.h>
#include<stdlib.h>
#define max 1000
int top=-1;
void  push(char stack[],char c){
    if(top==max-1){
        printf("stack is full :\n");
    }
    else{
        top=top+1;
        stack[top]=c;
    }
}
char pop(char stack[]){
    char c='\0';
    if(top==-1){
        printf("stack is empty :\n");
    }
    else{
        c=stack[top];
        printf("%c",c);
        top--;
    }
    return c;
}
int main(){
    int i=0;
    char stack[max];
    char str[max];
    char c;
    printf("enter the string :\n");
    fgets(str,sizeof(str),stdin);
    while(str[i]!='\0'&&str[i]!='\n'){
     push(stack,str[i]);
       i++;
    }
    while(top!=-1){
    pop(stack);
    }
return 0;
}