//��������ɵ����������KС��Ԫ�أ�����Ƚϴ���
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#define SIZE 100
#define swap(a,b) {int t=b;b=a;a=t;}
using namespace std;
static int cn=2;//���徲̬ȫ�ֱ�����ͳ�ƱȽϴ���

int partition(int a[],int l,int r)//��������Ԫ��λ��
{
    int i=l-1,j=r;
    int v=a[r];//������Ԫ�ظ���V
    while(1)
    {
        while(a[++i]<v)
            cn++;
        while(v<a[--j])
            cn++;
        if(i>=j)
            break;
        swap(a[i],a[j]);//����Ԫ��
    }
    swap(a[i],a[r]);//��������Ԫ��
    return   i;//��������������Ԫ��λ��
}

int random_partition(int a[], int l, int r)//�õ���������ຯ��
{
    srand(time(0));//��ʼ������
    int i=rand()%(r-l+1)+l;//����Ԫ���������
    swap(a[i],a[r]);//������Ԫ�ط��ڿ�ͷλ��
    return   partition(a,l,r);//��������Ԫ��λ��
}

int random_select(int a[],int l,int r,int k)
{
    if(r<=l)
        return   a[r];
    int   i=random_partition(a,l,r);//��������Ԫ��λ��
    int   j=i-l+1;//���Ԫ�ظ���
    if(j==k)//�ж��Ƿ�Ϊ��KС�����򷵻ظ�Ԫ��
        return  a[i];
    if(j>k)//С�ڵ�KС��Ԫ�ظ�������K���������Ӽ���Ѱ�ҵ�KС��Ԫ�أ����������Ӽ���Ѱ��
        return   random_select(a,l,i-1,k);
    else
        return   random_select(a,i+1,r,k-j);

}

void  disp(int a[],int n)//���������ɵ�����Ԫ��
{
    int k=-1;
    for(int i=0; i<n; i++)
    {

        k++;
        if(k%5==0)
            cout<<endl;
        cout<<setw(2)<<i<<":"<<setiosflags(ios::left)<<setw(12)<<a[i];
    }
    cout<<endl;
}

int main()
{

    int i,a[SIZE];//��������
    srand((unsigned int)time(0));//��ʼ������
    for(i=0; i<=100; i++)
        a[i++]=rand();//���������
    cout<<"���ɵ������Ϊ:"<<endl;
    disp(a,SIZE);//������ɵ�����Ԫ��
    int k;
    cout<<"------���KС����------"<<endl;
    cout<<"������K:"<<endl;
    cin>>k;
    cout<<"��"<<k<<"С������:"<<(random_select(a,0,SIZE-1,k))<<endl;
    cout<<"�Ƚϴ���Ϊ:"<<cn<<endl;
    return 0;
}
