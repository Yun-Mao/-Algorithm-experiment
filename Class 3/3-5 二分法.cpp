#include <iostream>
#include <cmath>
using namespace std;
double F(double x)
{
    return (9*x*x-sin(x)-1);
}
int main()
{
    double x1,x2;
    x1=0.0;
    x2=0.4;
    if(F(x1)*F(x2)<0)
    {
        double x3;
        double x;
        while(abs(x-x3)>0.00001)
        {
            x=(x1+x2)/2;
            if(F(x)==0)
                break;
            if(F(x1)*F(x)<0)
            {
                x3=x2;
                x2=x;
            }else{
                x3=x1;
                x1=x;
            }
        }
        cout<<x;
    }

}
