#include<iostream>
using namespace std;
int main()
{
   int n;
   int **a;
   cin >> n;
   int i,j;
   int k=1;
   a=new int*[n];
   for(i=0;i<n;++i)
   {
       a[i]=new int[n];
   }
   for(i=0;i<n;++i)
   {
       for(j=0;j<n-i;++j)
       {
           a[i+j][j]=k;
           k++;
       }
   }
   for(i=0;i<n;++i)
   {
       for(j=0;j<i+1;++j)
       {
           cout<<a[i][j]<<" ";
       }
       cout<<endl;
   }
}
