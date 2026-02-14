#include<stdio.h>
int main()
{
    int r,c,p,q,i,j; 
    printf("enter the no of rows of 1st matrix");
    scanf("%d",&r);
    printf("enter the no of column of 1st matrix");
    scanf("%d",&c);
    printf("enter the no of elements in 1st matrix");
    int a[r][c];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter the no of rows of 2nd matrix");
    scanf("%d",&p);
    printf("enter the no of column of 2nd matrix");
    scanf("%d",&q);
    printf("enter the no of elements in 2nd matrix");
    int b[p][q];
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    if(c!=p)
    {
        printf("cannot multiply");
        return ;

    }
    else
    {
        int res[r][q];
        for(i=0;i<r;i++)
        {
            for(j=0; j<q;j++)
            { 
                //pehle column ke bdle k aega fir row ke bdle k
               res[i][j]= 0 ;
            
               for(int k=0;k<c;k++)
             {
                res[i][j]+=a[i][k]*b[k][j];
             }        
            }
        }
        }
    printf("the result is :\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("  %d",res[i][j]);
        }
        printf("\n");
    }
}