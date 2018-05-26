#include <iostream>
using namespace std;
void Merge(int *A, int p, int q, int r)
{
	int i, j;
	int x, y;
	x = q - p + 1;
	y = r - q;
	//cout << x;
	//cout << y;
	int *B;
	B = new int[x];
	int *C;
	C = new int[y];
	for (i = 0; i<x; ++i)
	{
		B[i] = A[p + i];
		//cout << B[i]<<endl;
	}
	for (i = 0; i<y; ++i)
	{
		C[i] = A[q + i + 1];
		//cout << C[i]<<endl;
	}
	i = 0;
	j = 0;
	int k = p;
	while (i<x&&j<y)
	{
		if (B[i] <= C[j])
		{
			A[k] = B[i];
			++i;
		}
		else
		{
			A[k] = C[j];
			++j;
		}
		++k;
	}

	if (i>x)
	{
		for (i = 0; i<r-k+1; ++i)
		{
			A[k + i] = C[j + i];
		}
	}
	else {
		for (j = 0; j<r - k + 1; ++j)
		{
			A[k + j] = B[i + j];
		}
	}
}
void MergeSort(int *A, int p, int r)
{
	int q;
	if (p<r)
	{
		q = (p + r + 2) / 2 - 1;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}
int main()
{
	int A[3];
	int i;
	A[0] = 5;
	A[1] = 4;
	A[2] = 1;
	MergeSort(A, 0, 2);
	for (i = 0; i<3; ++i)
	{
		cout << A[i];
	}
}
