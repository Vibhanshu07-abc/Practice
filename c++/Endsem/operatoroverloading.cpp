#include<iostream>
#include<string>
using namespace std;
class demo{
    string sample;
    int number;
    public :
    demo(){
       sample=" ";
        number=0;
    }
    friend ostream &operator <<(ostream &output,demo &obj);
    friend istream &operator >>(istream &input,demo &obj);
};
ostream &operator <<(ostream &output,demo&a){
    output<<a.number<<"  "<< a.sample<<"\ttask completed\n";
    return output;
}
istream &operator >>(istream &input,demo&a){
    input>>a.number>>a.sample;
    return input;
}
int main(){
    cout<<"enter the details\n";
    demo obj;
    cin>>obj ;
    cout<<obj;
}