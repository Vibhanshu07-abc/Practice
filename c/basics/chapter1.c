#include<stdio.h>
int main()
{
  
    int ch,sub,add,multiply,divide,a,b,c;
    printf("enter first number");
    scanf("%d",&a);
    printf("enter second number");
    scanf("%d",&b);
    printf("enter the choice \n");
    printf("1 for multiply,2 for divide,3 for addition,4 for subtraction");
    scanf("%d",&ch);
    switch(ch){
        case 1: c = a*b;
        printf("%d",c);
        break;
        case 2: c = a/b;
        printf("%d",c);
        break;
        case 3: c = a+b;
        printf("%d",c);
        break;
        case 4: c = a-b;
        printf("%d",c);
        break;
        default: printf("invalid input");
        break;
    }
      return 0;
}