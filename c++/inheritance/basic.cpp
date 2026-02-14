#include<iostream>
using namespace std; 
class A{
    public:
    int a=2;
    protected :
    int b=3;
    private: 
    int c=4;
};
class B :public A{
     public :
    void x(){
        cout<<a<<endl;
        cout<<b<<endl;
       // cout<<c<<endl;
    }
};
class c:protected B {
        public: 
        int num=7;
        protected : 
        int e=8;
        private :
        int f=10;
};
class d:private c{
     public :
        void y(){
            cout<<a<<endl;
            cout<<b<<endl;
            cout<<num<<endl;
            cout<<e<<endl;
           // cout<<f<<endl;
        }
};
int main(){
    d obj;
    obj.y();
    B a1;
    a1.x();
    
}