#include<iostream>
using namespace std;
class shape{
    public:
    float a,b;
    static double pi;
    void getdata(float c,float d){
     a=c;
     b=d;
    }
    virtual void display_volume()=0;
    virtual~shape(){};
};
double shape::pi=3.1456;
class cone:public shape{
    public :
    void display_volume(){
        float res=(1.0/3.0)*pi*a*a*b;
        cout<<res<<endl;
    }
};
class hemisphere :public shape{
    public :
    void display_volume(){
        float res=(2.0/3.0)*pi*a*a*a;
        cout<<res<<endl;
    }
};
class cylinder :public shape{
    public :
    void display_volume(){
        float res=(22.0/7.0)*a*a*b;
        cout<<res<<endl;
    }
};
int main(){
    shape*ptr;
    hemisphere obj1;
    cone obj;
    cylinder obj3;
    int a,b;
    cout<<"enter the radius and height numbers \n";
    cin>>a;
    cin>>b;
    int ch;
    cout<<"1 for hemisphere\n";
    cout<<"2 for cone\n";
    cout<<"3 for cylinder\n";
    cin>>ch;
    if(ch==1){
        ptr=&obj1;
        ptr->getdata(a,b);
        ptr->display_volume();
    }
    if (ch==2){
       ptr=&obj;
        ptr->getdata(a,b);
        ptr->display_volume();
    }
    if(ch==3){
        ptr=&obj3;
        ptr->getdata(a,b);
        ptr->display_volume();
    }
}
