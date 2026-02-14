#include<stdio.h>
#include<string.h>
#include<ctype.h>
int check(char str1[]){
    int i=0;
    int a=strlen(str1);
    int j=a-1;
    while(i<j){
       if(tolower(str1[i])!=tolower(str1[j])){
        return 0;
       }
       i++;
       j--;
    }
    return 1;
}

int main(){
   char str[100];
   char copy[100];
   printf("enter the string \n");
   scanf("%s",str);
   int a=check(str);
   if(a==1){
    printf("palindrome\n");
   }else{
    printf("not a plaindrome \n");
   }

}