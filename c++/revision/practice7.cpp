#include<iostream>
using namespace std;
class time{
    int minutes,hour,second;
    public:
    time(){
     minutes=0;
     hour=0;
     second=0;
    }
    time(int hr,int min,int sec){
        minutes=min;
        second=sec;
        hour=hr;
    }
    time operator +(const time &c){
        time t;
        t.second=second+c.second;
        t.minutes=minutes+c.minutes+(t.second/60);
        t.hour=hour+c.hour+(t.minutes/60);
        t.minutes=t.minutes%60;
        t.second=t.second%60;
        return t;

    }
    void display(){
        if(hour<10){
            cout<<"0";
        }
        cout<<hour<<":";
        if(minutes<10){
            cout<<"0";
        }
        cout<<minutes<<":";
        if (second<10){
            cout<<"0";
        }
        cout<<second;
    }
};
int main(){
    time t1(3,4,5);
    time t2(4,5,6);
    time t3;
    t3=t1+t2;
    t3.display();
}