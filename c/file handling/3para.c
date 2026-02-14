#include<stdio.h>
int main(){

    FILE*ptr=NULL;
    int consonants=0;
    char ch;
    int vowels=0;
    ptr=fopen("sample.txt","w");
    if(ptr==NULL){
        printf("error in opening file\n");
    }
    else{
        fprintf(ptr,"my name is vibhanshu i am btech 1st year student at graphic era hill university\n");
        fprintf(ptr,"my name is vibhanshu i am btech 1st year student at graphic era hill university\n");
        fprintf(ptr,"my name is vibhanshu i am btech 1st year student at graphic era hill university\n");
    }
    fclose(ptr);
    ptr=fopen("sample.txt","r");
    if(ptr==NULL){
        printf("error in opening file \n");
    }
    else{
        while((ch=fgetc(ptr))!=EOF){
            if(ch=='a'||ch=='e'||ch=='o'|| ch=='i'||ch=='u'||ch=='A'||ch=='E'||ch=='O'|| ch=='I'||ch=='U'){
                vowels++;
            }
             else if((ch>='A'&&ch<='Z') || (ch>='a'&&ch<='z')){
                consonants++;
            }
        }

    }
    printf("%d\n",vowels);
    printf("%d\n",consonants);
    fclose(ptr);
}