//在随机生成的数组中求第K小的元素，并求比较次数
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#define SIZE 100
#define swap(a,b) {int t=b;b=a;a=t;}
using namespace std;
static int cn=2;//定义静态全局变量，统计比较次数

int partition(int a[],int l,int r)//返回中枢元素位置
{
    int i=l-1,j=r;
    int v=a[r];//把中枢元素赋给V
    while(1)
    {
        while(a[++i]<v)
            cn++;
        while(v<a[--j])
            cn++;
        if(i>=j)
            break;
        swap(a[i],a[j]);//交换元素
    }
    swap(a[i],a[r]);//交换中枢元素
    return   i;//返回排序后的中枢元素位置
}

int random_partition(int a[], int l, int r)//得到随机的中枢函数
{
    srand(time(0));//初始化种子
    int i=rand()%(r-l+1)+l;//中枢元素随机划分
    swap(a[i],a[r]);//把中枢元素放在开头位置
    return   partition(a,l,r);//返回中枢元素位置
}

int random_select(int a[],int l,int r,int k)
{
    if(r<=l)
        return   a[r];
    int   i=random_partition(a,l,r);//返回中枢元素位置
    int   j=i-l+1;//求得元素个数
    if(j==k)//判断是否为第K小，是则返回该元素
        return  a[i];
    if(j>k)//小于第K小的元素个数多于K，则在左子集中寻找第K小的元素，否则在右子集中寻找
        return   random_select(a,l,i-1,k);
    else
        return   random_select(a,i+1,r,k-j);

}

void  disp(int a[],int n)//输出随机生成的数组元素
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

    int i,a[SIZE];//定义数组
    srand((unsigned int)time(0));//初始化种子
    for(i=0; i<=100; i++)
        a[i++]=rand();//随机化数组
    cout<<"生成的随机数为:"<<endl;
    disp(a,SIZE);//输出生成的数组元素
    int k;
    cout<<"------求第K小的数------"<<endl;
    cout<<"请输入K:"<<endl;
    cin>>k;
    cout<<"第"<<k<<"小的数是:"<<(random_select(a,0,SIZE-1,k))<<endl;
    cout<<"比较次数为:"<<cn<<endl;
    return 0;
}
