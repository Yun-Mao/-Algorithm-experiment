#include <iostream>
#include <cmath>
using namespace std;
#define SIGN(A)((A>0)?1:-1)
int divide(int x,int y,int n)
{
    int sign;
    sign=SIGN(x)*SIGN(y);
    x=abs(x);
    y=abs(y);
    if(x==0||y==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return sign*x*y;
    }
    else
    {
        int x1,x0,y1,y0,xy1,xy0,xy10;
        x1=x/pow(10,n/2);
        x0=x-x1*pow(10,n/2);
        y1=y/pow(10,n/2);
        y0=y-y1*pow(10,n/2);
        xy1=divide(x1,y1,n/2);
        xy0=divide(x0,y0,n/2);
        xy10=divide((x1-x0),(y0-y1),n/2)+xy0+xy1;
        return sign*(xy1*pow(10,n)+xy10*pow(10,n/2)+xy0);
    }
}
int main()
{
    cout<<divide(2012,1022,4)<<endl;

}
