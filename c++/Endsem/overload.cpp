#include<iostream>
using namespace std;
class overloading{
    public :
    int a;
    int b;
    int operator++(){
        a++;
        int c=a;
        return c;
    }
     friend int operator++(overloading &,int );
    friend int  operator+(overloading &,overloading &);
    int operator-(overloading &B){
        int temp=this->b;
          temp=temp-B.b;
        return temp;
    }
};
   int  operator+(overloading & e,overloading &f){
       int temp=e.b+f.b;
       return temp;
   }
int operator++(overloading & b,int ab){
    int temp=b.a++;
    return temp;
}
int main(){
    overloading obj1,obj2;
    obj1.a=20;
    obj1.b=30;
    obj2.b=40;
    int y=++obj1.a;
    cout<<y<<endl;;
    y=obj1.a++;
   cout<<obj1.a<<endl;
   int var =obj1+obj2;
   cout<<var<<endl;
   int sub=obj1-obj2;
   cout<<sub<<endl;
}