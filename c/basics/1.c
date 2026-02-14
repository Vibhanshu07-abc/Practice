#include<stdio.h>
int main(){
    char str1[50];
    char str2[50];
    int i=0,j=0;
    printf("enter the string \n");
    scanf("%s",str1);
    printf("enter the string \n");
    scanf("%s",str2);
    while(str1[i]!='\0'){
        i++;
    }
    str1[i]='#';
    i++;
    while(str2[j]!='\0'){
        str1[i]=str2[j];
        j++;
        i++;
    }
    str1[i]='\0';
    printf("%s\n",str1);
}