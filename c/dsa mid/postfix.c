#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define max 100
int top=-1;
int stack[max];

void push(int ch){
    if(top==max-1){
        printf("full\n");
        return;
    }else{
        stack[++top]=ch;
    }
}
int  pop (){
    if(top==-1){
        printf("empty\n");
        return 0;
    }else{
        return stack[top--];
    }
}
int postfixeval(char*expr ){
    int i,result;
    char ch;
    for(i=0;expr[i]!='\0';i++){
        ch=expr[i];
        if(ch==' '||ch=='\n'||ch=='\t')continue;
        else if(isdigit(ch)){
           int num=0 ;
            while(isdigit(expr[i])){
                 int temp=expr[i]-'0';
                 num=num*10+temp;
                 i++;
            }
            i--;
            push(num);
        }
         else if (ch == '+' || ch == '-' || ch == '*' || ch == '/'||ch =='^'){
            int a=pop();
            int b=pop();
            switch(ch){
                case '*' : result=b*a;
                      
                          break;
                case '/' :result=b/a;
                        
                          break;
                case '+'  :result=b+a;
                        
                          break;
                case '-'  :result=b-a;
                         
                          break;
                case '^'  : result=pow(b,a);
                        
                         break;
            }
            push(result);
        }
    }
      result=pop();
      return result;
}
int main(){
    char expr[max];
    int result;
    printf("enter postfix expression:\n");
    fgets(expr,max,stdin);
    printf("the result is :\n");
    result=postfixeval(expr);
    printf("%d :",result);
}