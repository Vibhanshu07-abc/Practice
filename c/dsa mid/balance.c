#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10
typedef struct stack{
    char arr[max];
    int top;
    int count;
}s;
void push(s*b,char value){
    if(b->top==max-1){
        printf("full\n");
    }
    else{  b->top++;
        b->arr[b->top]=value;
    }
}
char pop(s*b){
    if(b->top==-1){
        printf("empty\n");
        return '\0';
    }
    else{
        return b->top--;
    }
}
int balanced(s*b,char string[]){
    char ch;
    for(int i=0;i<strlen(string);i++){
     ch=string[i];
     if(ch=='('||ch=='['||ch=='{'){
        push(b,ch);
     }
     else if(b->top!=-1&&((ch=='}'&&b->arr[b->top]=='{')||(ch==')'&&b->arr[b->top]=='(')||(ch==']'&&b->arr[b->top]=='['))){
        b->count=b->count+2;
        pop(b);
     }else{
        return 1;
     }
    }
        return 0;
    
}
int main(){
    s*b=(s*)malloc(sizeof(s));
    b->top=-1;
    b->count=0;
    int value;
    char str[max];
    printf("enter the string \n :");
    fgets(str,max,stdin);
    value=balanced(b,str);
if(value==0){
    printf("balanced :\n");
    printf("valid paranthesis %d",b->count);
    
}else{
    printf("not balanced :\n");
  printf("valid paranthesis %d",b->count);
}
}
/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
int top=-1;
char stack[max];
void push(char value){
    if(top==max-1){
        printf("full");
    }
    else{ 
        stack[++top]=value;
    }
}
char pop(){
    if(top==-1){
        printf("empty\n");
        return '\0';
    }else{
         return stack[top--];
    }
}
int main(){
    char ch,string[max];
    int num=0;
    printf("enter the string \n :");
    scanf("%s",string);
     for(int i=0;i<strlen(string);i++){
     ch=string[i];
     if(ch=='('||ch=='['||ch=='{'){
        push(ch);
     }
     else #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
int top=-1;
char stack[max];
void push(char value){
    if(top==max-1){
        printf("full");
    }
    else{ 
        stack[++top]=value;
    }
}
char pop(){
    if(top==-1){
        printf("empty\n");
        return '\0';
    }else{
         return stack[top--];
    }
}
int main(){
    char ch,string[max];
    int num=0;
    printf("enter the string \n :");
    fgets(string,max,stdin);
     for(int i=0;i<strlen(string);i++){
     ch=string[i];
     if(ch=='('||ch=='['||ch=='{'){
        push(ch);
     }
     else if(ch=='}'&&top!=-1&&stack[top]=='{'||ch==')'&&top!=-1&&stack[top]=='('||ch==']'&&top!=-1&&stack[top]=='['){
        pop();
     }
    }
    if(top==-1){
         printf("balanced :\n");
    }
    else{
    printf("not balanced :\n");
    while(top!=-1){
        num++;
        pop();
        
    }
    }  
    printf("no of closing braket needed is %d",num);
}{
        pop();
     }
    }
    if(top==-1){
         printf("balanced :\n");
    }
    else{
    printf("not balanced :\n");
    while(top!=-1){
        num++;
        pop();
        
    }
    }  
    printf("no of closing braket needed is %d",num);
}*/
