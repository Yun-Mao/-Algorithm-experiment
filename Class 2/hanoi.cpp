#include <iostream>
using namespace std;
void Hanoi(char A,char B,char C,int n)
{
    if(n==1)
    {
        cout<<A<<"->"<<C<<endl;
    }
    else{
        Hanoi(A,C,B,n-1);
        cout<<A<<"->"<<C<<endl;
        Hanoi(B,A,C,n-1);
    }
}
int main()
{
    Hanoi('A','B','C',3);
}
