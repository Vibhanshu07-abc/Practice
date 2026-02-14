#include<stdio.h>
int main(){
    char str[100];
    char str1[100];
    char temp=0;
    int j,i,m,n;
    printf("enter the string \n");
    scanf("%s",str);
    printf("enter the first index to reverse ");
    scanf("%d",&m);
    printf("enter the second index to reverse ");
    scanf("%d",&n);
    while(str[i]!='\0'){
        for(i=m;i<=n;i++)
        {
            for(j=n;j>=m;j--)
            {
                temp=str[i];
                str[i]=str[j];
                str[j]=temp;
            }
        }
        str1[i]=str[i];
       i++;
    }
    printf("the new string is :\n");
    printf("%s",str1);

}