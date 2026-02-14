#include<stdio.h>
void main()
{
    int i,j,r,c,temp;
    printf("enter the rows of matix");
    scanf("%d",&r);
    printf("enter the column of matix");
    scanf("%d",&c);
    printf("enter the elements of matrix");
    int a[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)  
        {
            scanf("%d",&a[i][j]);
        }
    }
   printf("entered matrix is \n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)  
        {
            printf("    %d",a[i][j]);
        }
        printf("\n");
    }

for(int i=0;i<c;i++)
    {
        for(int j=i;j<r;j++)  
        {
           temp=a[i][j];
           a[i][j]=a[j][i];
           a[j][i]=temp;
        }
    }  
    printf("the transpose is \n") ;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)  
        {
            printf("    %d",a[i][j]);
        }
        printf("\n");
    }
}