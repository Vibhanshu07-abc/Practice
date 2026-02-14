#include<stdio.h>
 int main()
 {
    char str[100];
    char rev[100];
    int  i=0,size=0;
    char temp;
    int j;
    int choice ;
   
    while (choice !=2)
    {
   printf("enter 1: to reverse name or 2 to exit \n");
   scanf("%d",&choice);
    puts("enter a string \n");
    fgets(str,100,stdin);
    while(str[i]!='\0')
    {
       size++;
       i++;
    }
 for (i = 0, j = size - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
 }
    printf (" after reverse:\n");
    puts(str);
    return 0;
 }
}