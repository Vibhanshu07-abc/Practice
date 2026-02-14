#include<stdio.h>
int main()
{
    FILE*ptr=NULL;
    char str[200];
    char ch ;
    ptr=fopen("sakshi.txt","w");
    printf("enter a string\n");
    scanf("%s",&str);
    fprintf(ptr,"%s",str);
   // fscanf(ptr,"%s",str);
   // printf("%s",str);
    fclose(ptr);
}