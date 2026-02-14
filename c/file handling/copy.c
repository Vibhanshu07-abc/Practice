#include<stdio.h>
int main()
{
    FILE*ptr1=NULL;
    FILE*ptr2=NULL;
    char ch;
    int i=0;
    char str[200];
    ptr1=fopen("test.txt","r");
    ptr2=fopen("sample.txt","w");
    if(ptr1==NULL)
    {
        printf("error in opening file \n");
    }
    else{
        while((ch=fgetc(ptr1))!=EOF && i<(sizeof(str)-1)){
            if(ch!=' '){
                
            str[i]=ch;
            i++;
        }
    }
        str[i]='\0';
    }
    if(ptr2==NULL){
        printf("error in opening file");
    }
     else{ 
        fprintf(ptr2,"%s",str);
     }
     fclose(ptr1);
     fclose(ptr2);
  return 0;
}