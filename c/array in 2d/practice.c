#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m,n,i,j,k=0;
    printf("enter the no of rows and column ");
    scanf("%d %d",&m,&n);
    printf("enter the no of elements");
    int a[m][n];
    for (i=0; i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for (i=0; i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i>j&&a[i][j]!=0)
    {
            k=1;
    }
}
    }
   
if(k==1)
{
    printf("matrix is not upper triangular");

}
else
{
    printf("matrix is upper triangular ");
}
}
