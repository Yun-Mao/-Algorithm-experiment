#include<iostream>
using namespace std;
int main()
{
   float S,T;
   int i,j,n;
   cin>>n;
   T=1;
   S=-1;
   for(i=2;i<=n;i++)
   {
       T+=1.0/(S*(2*i-2)*(2*i-1));
       S=-1*(S*(2*i-2)*(2*i-1));
   }
   cout<<T;
}
