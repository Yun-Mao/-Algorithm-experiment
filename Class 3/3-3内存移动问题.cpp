#include <iostream>
using namespace std;
int gcb(int a , int b)
{
    if(b==0) return a;
    int r=a%b;
    if(r>b) gcb(r,b);
    else gcb(b,r);
}
int main()
{
    int q;
    q=gcb(10,4);//10����������4λ��
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int i,j;
    for(i=0;i<q;++i)
    {
        int tmp,p,p1,p2;
        j=10/q-1;//�ƶ�Ԫ�صĸ���
        p1=(i+j*4)%10;
        tmp=a[p1];
        for(j=j-1;j>=0;--j)
        {
            p2=(i+j*4)%10;
            a[p1]=a[p2];
            p1=p2;
        }
        a[p2]=tmp;
    }
    for(i=0;i<10;++i)
    {
       cout<<a[i];
    }

}
