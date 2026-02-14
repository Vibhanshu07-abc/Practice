#include<iostream>
using namespace std;
class shape{
    public :
    int a,b;
    void getdata(int c,int d){
     a=c;
     b=d;
    }
    virtual void display(){}
};
class triangle:public shape{
    public :
    void display(){
        int res=0.5*a*b;
        cout<<res<<endl;
    }
};
class rectangle :public shape{
    public :
    void display(){
        int res=a*b;
        cout<<res<<endl;
    }
};
int main(){
    shape*ptr;
    triangle obj1;
    rectangle obj;
    int a,b;
    cout<<"enter the two numbers \n";
    cin>>a;
    cin>>b;
    int ch;
    cout<<"1 for tringle\n";
    cout<<"2 for rectangle\n";
    cin>>ch;
    if(ch==1){
        ptr=&obj1;
        ptr->getdata(a,b);
        ptr->display();
    }
    if (ch==2){
       ptr=&obj;
        ptr->getdata(a,b);
        ptr->display();
    }
}
