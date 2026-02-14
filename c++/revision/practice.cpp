#include<iostream>
using namespace std;
class stock{
    int n;
    int item[100];
    float averagesale;
    public:
     void input(){
        cout<<"enter number of days : "<<endl;
        cin>>n;
        cout<<"enter sales of each day :"<<endl;
        for(int i=0;i<n;i++){
            cin>>item[i];
        }
     }
     void max(){
        int maxsales=0;
        int maxday=1;
        for(int i=0;i<n;i++){
            if(maxsales<item[i]){
                maxsales=item[i];
                maxday=1+i;
            }
        }
        cout<<"maxsales sales is "<<maxsales<<endl;
        cout<<"maxday is "<<maxday<<endl;
     }
       void min(){
        int minsales=item[0];
        int minday=1;
        for(int i=1;i<n;i++){
            if(minsales>item[i]){
                minsales=item[i];
                minday=1+i;
            }
        }
        cout<<"minsales sales is "<<minsales<<endl;
        cout<<"minday is "<<minday<<endl;
     }
     void average(){
         averagesale=0;
        for(int i=0;i<n;i++){
            averagesale=averagesale+item[i];
        }
        averagesale=averagesale/n;
        cout<<"average sale is :"<<averagesale<<endl;
     }
    
     void daysaboveaverage(){
        int aboveaverage=0;
        int m=0;
        for(int i=0;i<n;i++){
            if(item[i]>averagesale){
                m++;
            }
        }
        cout<<"days above average are : "<<m<<endl;
     }   
};
int main(){
    stock s;
    s.input();
    s.average();
    s.daysaboveaverage();
    s.max();
    s.min();
}