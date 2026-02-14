#include<iostream>
#include<string>
using namespace std;
class product{
    private :
    int id;
    string name;
    int price;
    int qty;
    public:
    void set(){
        cout<<"enter the product id : "<<endl;
        cin>>id;
        cout<<"enter price : "<<endl;
        cin>>price;
        cin.ignore();
        cout<<"enter the name : "<<endl;
        getline(cin,name);
        cout<<"enter the quantity : "<<endl;
        cin>>qty;
    }
    void calc(){
        int bill;
        bill=price*qty;
        cout<<"bill is : "<<bill<<endl;
    }
    void display(){
        cout<<"name :"<<name<<endl;
        cout<<"product id :"<<id<<endl;
        cout<<"quantity of the product is :"<<qty<<endl;
        cout<<"price is : "<<price<<endl;

    }
};
int main(){
    product a;
    a.set();
    a.calc();
    a.display();
}