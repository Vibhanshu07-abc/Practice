#include<stdio.h>
int main(){
    FILE*fp,*even;
    fp=fopen("num.txt","w");
    int num=0,n;
    printf("enter number of integers \n");
    scanf("%d",&n);
    printf("enter the numbers in the file\n");
    for(int i=0;i<n;i++){
   scanf("%d",&num);
   fprintf(fp,"%d\n",num);
    }
    fclose(fp);
    fp=fopen("num.txt","r");
    even=fopen("even.txt","w");
    while((fscanf(fp,"%d",&num))!=EOF){
        if(num%2==0){
            fprintf(even,"%d\n",num);
            printf("thee number %d is added in txt file\n",num);
        }
    }
    fclose(fp);
    fclose(even);
}