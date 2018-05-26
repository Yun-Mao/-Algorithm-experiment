#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, m;
	int i, j;
	cin >> n;
	m = n * log(n / 6);
	int *a;
	a = new int[m];
	for (i = 0; i<m; ++i)
	{
		a[i] = 0;
	}
	a[1] = 1;
	int len = 1;
	for (i = 2; i<=n; ++i)
	{
		int d = 0;//进位
		for (j = 1; j <= len; ++j)
		{
			int b;//结果
			b = a[j] * i + d;
			a[j] = b % 1000000;
			d = b / 1000000;
		}
		while(d)
		{
			a[j] = d% 1000000;
			d=d/1000000;
			len++;
		}
	}
	for (i = len ; i >0; --i)
	{
		cout << a[i];
		if(a[i]==0) cout<<"000000";
	}
}
