#include <iostream>
using namespace std;
int main()
{
    int dis=500,distance=1000;
    int oil=500;
    int n=1;
    while(dis<distance)
    {
        cout<<n<<" "<<dis<<" "<<oil<<endl;
        ++n;
        oil+=500;
        dis+=500/(2*n-1);
    }
    dis=distance-(dis-500/(2*n)-1);
    oil=oil-500+dis*(2*n-1);
    cout<<n<<" "<<distance<<" "<<oil<<endl;
}
