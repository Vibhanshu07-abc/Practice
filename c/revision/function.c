/*
  // pascal Triangle\\ 
#include<stdio.h>
int fact(int x)
{    int fact=1;
    if (x==1 || x==0)
    {
        return 1;
    }
    else
    {  for(int i=2;i<=x;i++)
        {
            fact=fact*i;
        }
        return fact;
    }

}
int main()
{
    int ncr;
int i,j;
int n;
printf("enter the size of pascal traiangle \n");
scanf("%d",&n);
for(i=0;i<=n;i++)
{
    for(j=0;j<=i;j++)
    {
        ncr=fact(i)/(fact(j)*fact(i-j));
        printf("    %d",ncr);
    }
    printf("\n");
}
return 0;
}
*/
  //     RECURSSION 

/*
#include<stdio.h>
void formation();
int main()
{
    int n; 
    printf("enter the number :\n");
    scanf("%d",&n);
    formation(n);
} 
int x=1;
void formation(int n){
    if (n==0) return;
    printf("%d\n",n);
    formation(n-1);
    printf("%d\n",n);
    return;

}  
#include<stdio.h>
int  whole(int n){
 if (n==0||n==1) return 1;
 int total= n + whole(n-1);
    return total;
}
int main()
{
    int n,sum;
    printf("enter the number :");
    scanf("%d",&n);
  sum=whole(n);
   printf("sum is %d",sum);
      return 0;
}*/
#include<stdlib.h>
#include<stdio.h>
typedef struct node {
    int data ;
    struct node*next ;
}l;
void push(l**top,int item){
    l*newnode;
    newnode=(l*)malloc(sizeof(l));
    if(newnode==NULL){
        printf("memory allocation failed \n");
    }
    else{
        newnode->next=(*top);
        newnode->data=item;
        (*top)=newnode;
    }
}
 void pop(l**top){
     l*temp=*top;
     if(*top==NULL){
         printf("stack  is empty \n");
     }
     else{ 
         printf(" the deleted elemnt is %d\n",temp->data);
         (*top)=(*top)->next;
         free(temp);
     }
 }
 void display(l*top){
     l*temp=top;
     if(top==NULL){
         printf("stack empty \n");
     }
     else{
         printf("the elemnts of the stack are \n");
         while(temp!=NULL){
             printf(" %d\n",temp->data);
             temp=temp->next;
         }
     }
 }
 int main(){
     l*top=NULL;
     int item,choice;
     while(1){
         printf("enter the choice \n");
         printf("1.pop\n2.push\n3.display\n4.exit\n");
         scanf("%d",&choice);
         switch(choice){
             case 1: pop(&top);
                     break;
             case 2: printf("enter the elemnt to enter in stack \n");
                     scanf("%d",&item);
                     push(&top,item);
                     break;
            case 3: display(top);
                    break;
            case 4: printf("exiting......");
            return 0;
            default:printf("invalid choice ");
         }
     }
     
 }
