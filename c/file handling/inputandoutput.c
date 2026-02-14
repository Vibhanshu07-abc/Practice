#include<stdio.h>
#include<string.h>
int main()
{
    FILE*ptr =NULL;
    char str[100];

    /*ptr=fopen("test.txt","r");
    fscanf(ptr,"%S",str);
    printf("%S",str);
    return 0;*/
    printf("enter a string\n");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    ptr=fopen("test.txt","w");
    fprintf(ptr,"%s",str);
    fclose(ptr);
    
}