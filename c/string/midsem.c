#include<stdio.h>
int main()
{
    char str[100];
    int size=0;int i=0;
    int j=0;
    char ch;
    puts("enter a string\n");
    gets(str);
    printf("enter the character to search\n");
    scanf("%c",&ch);
    while(str[i]!='\0')
    {
        if(str[i]==ch)
        {
            j=i;
            break;
        }
        i++;
    }

    printf("the position of 1st occurence is :%d",j+1);
}