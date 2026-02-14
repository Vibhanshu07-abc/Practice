#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 100
int top =-1;
void push(char stack[],char c){
 if(top==max-1)return ;
 else{
    top++;
    stack[top]=c;
 }
}
char pop(char stack[]){
    char c;
    if(top==-1)return -1;
    else{
        c=stack[top];
     top--;  
     return c;   
    }
}
bool ismatching(char open,char close){
    if((open=='('&&close==')')||(open=='{'&&close=='}')||(open=='['&& close==']'))
    return true;
    else{
        return false;
    }
}
int main(){
    char stack[max];
    char c;
    char str[max];
    int i=0;
  printf("enter the string :\n");
  fgets(str,sizeof(str),stdin);
  while(str[i]!='\0'&&str[i]!='\n'){
    if(str[i]=='('||str[i]=='{'||str[i]=='['){
        push(stack,str[i]);
    }
    else if(str[i]=='}'||str[i]==')'||str[i]==']'){
        if(top==-1){
            printf("string not balanced :\n");
            return 0;
        }
        c =pop(stack);
       if(ismatching(c,str[i])==false){
        printf("string is not balanced :\n");
        return 0;
       }
    }
    i++;
  }
  if(top==-1){
    printf("the string is balanced :\n");
  }
  else{
    printf("string is not balanced :\n");
  }
}
