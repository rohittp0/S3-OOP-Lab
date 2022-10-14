#include<iostream>
using namespace std;

class Time{
    public:
   int min,hr;
   Time(int m){
      min=m%60;
      hr=m/60;
   }
   
   void input(){
       cout<<"Enter the hours: ";
       cin>>hr;
       cout<<"Enter the minutes: ";
       cin>>min;
   }
   void display(){
       cout<<"Time in minutes: "<<hr<<":"<<min<<endl;
   }

   operator int(){
       return min+hr*60;
   }

};

int main(){
    int min;
    cout<<"Enter time in minutes: ";
    cin>>min;
    Time t = min;
    t.display();
    t.input();
    min=t;
    cout<<"Converted to minutes only: "<<min;
    return 0;

}
