#include<iostream>
using namespace std;
class overloading{
    int x;
    public:
    overloading(){
        x=0;
    }
    overloading(int y){
        x=y;
    }
    void operator++(){
        x=x+10;
    }
    void operator--(){
        x=x-2;
    }
    void operator-(){
     x=-x;
    }
    void operator++(int){
       x++;
    }
    void show(){
        cout<<x<<endl;
    }
};
int main(){
    overloading a,b(5);
    a++;
    a.show();
    --b;
    b.show();
    b++;
    b.show();
}