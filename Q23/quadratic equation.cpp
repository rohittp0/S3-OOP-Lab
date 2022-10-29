// ROOT OF QUADRATIC EQUATION
#include<iostream>
#include<cmath>
using namespace std;
inline void quad(int a,int b,int c)
{
   float r1,r2;
    if(a==0)
{
   cout<< "not a quadratic equation ";
  return;
}
else
{
   float d=b*b-4*a*c;
 if(d>0)
{
   r1=(-b+sqrt(d))/(2*a);
   r2=(-b-sqrt(d))/(2*a);
cout<<"\nthe roots are real and distict : root1= "<<r1<<"\troot2= "<<r2;
}
else if(d==0)
{
   r1=-b/(2*a);

cout<<"\nthe roots are real and equal : root= "<<r1;
}
else
{
  
cout<<"\nthe roots are complex and imaginary : root1 = "<<-b/(2*a)<<'+'<<sqrt(-d)/(2*a)<<'i'<<"\nroot2= "<<-b/(2*a)<<'-'<<sqrt(-d)/(2*a)<<'i';
}
}}
int main()
{
  int a,b,c;
cout<<"enter the coefficients and constants of quadratic equation : ";
cin>>a>>b>>c;
quad(a,b,c);
return 0;
}