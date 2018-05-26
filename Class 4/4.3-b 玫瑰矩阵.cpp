#include <iostream>
using namespace std;
int main()
{
    int i, k, j;
    int s[2];
    s[0] = -1;
    s[1] = 0;
    k = 1;
    int a[5][5];
    int n = 5;
    int hc, index, t;
    t = 1;
    i = n;
    while (k <= n * n)
    {
        for (hc = 1; hc<2 * i; ++hc)
        {
            index = hc / (i + 1);
            s[index] = s[index] + t;
            a[s[0]][s[1]] = k;
            k++;
        }
        --i;
        t = -t;
    }
    for (i = 0; i<n; ++i)
    {
        for (j = 0; j<n; ++j)
        {
            cout << a[i][j]<<"  ";
        }
        cout<<endl;
    }
}
