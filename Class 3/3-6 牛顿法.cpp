#include <iostream>
#include <cmath>
using namespace std;
double F(double x)
{
    return (9*x*x-sin(x)-1);
}
double F_d(double x)
{
    return (18*x-cos(x));
}
int main()
{
   double x1,x2;
   x1=0.4;
   x2=x1-F(x1)/F_d(x1);
   while(abs(x1-x2)>0.00001)
   {
      x1=x2;
      x2=x1-F(x1)/F_d(x1);
   }
   cout<<x1;
}
