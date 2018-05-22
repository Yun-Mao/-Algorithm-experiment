#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

class P_laying
{
public:
	int Ptsp(); //Determine the optimal routing scheme
	int n; // The number of elements
	int **a; //The cost of wiring between components
	int cc; // Record the cost of the current path
	int bestc; //Optimal value of wiring problem
};
class MinstackNode // Defining the data structure of the minimum heap
{
	friend class P_laying;
	friend class Minstack;
public:
	operator int() const
	{
		return lcost;
	};
private:
	int lcost; //The lower bound of the cost of subtrees
	int cc; //Record the cost of the current path
	int s; //Road x[0: s]
	int rcost; // x[s: n- 1]cost
	int *x; //Search node x[s+1: n- 1]
};
const int Maxstacksize = 1000;//the size of the heap
class Minstack // the minimum Stack
{
private:
	MinstackNode StackList[Maxstacksize]; //Store the heap element
	int top; //Pile top position
public:
	Minstack(void);
	void insert(MinstackNode item);
	MinstackNode get(void);
	int StackEmpty(void);
	int StackFull(void);
};
Minstack::
Minstack(void){
	top = -1;
}
void Minstack::
insert(MinstackNode item)
{
	if (top == Maxstacksize - 1)
	{
		cout << "Stack overflow! " << endl;
		exit(1);
	}
	top++;
	if (item.lcost>StackList[top - 1].lcost)
		do
		{
			StackList[top] = StackList[top - 1];
			StackList[top - 1] = item;
			top--;
		} while (top != -1);
	else
		StackList[top] = item;
}
MinstackNode Minstack::
get(void)
{
	MinstackNode temp;
	if (top == -1)
	{
		cout << "Attempt to pop an empty stack! " << endl;
		temp.cc = 0;
		return  temp;
	}
	temp = StackList[top];
	top--;
	return temp;
}
int Minstack::
StackEmpty(void)
{
	return top == -1;
}
int Minstack::
StackFull(void)
{
	return top == Maxstacksize - 1;
}
int *Minout;
int P_laying::
Ptsp(void)
{
	Minstack H;
	Minout = new int[n];
	int Minsum = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		int Min = 32767;
		for (int j = 0; j < n; j++)
			if (a[i][j] != 0 && a[i][j]<Min)
				Min = a[i][j];
		Minout[i] = Min;
		Minsum += Min;
	}
	MinstackNode E;
	E.x = new int[n];
	for (i = 0; i<n; i++)
		E.x[i] = i;
	E.s = 0;
	E.cc = 0;
	E.rcost = Minsum;
	bestc = 32767;
	while (E.s<n-1)
	{
		if (E.s == n - 2)
		{
			if (a[E.x[n - 2]][E.x[n - 1]] != 0 &&
				a[E.x[n - 2]][E.x[n - 1]]<bestc)
			{
				bestc = E.cc + a[E.x[n - 2]][E.x[n - 1]];
				E.cc = bestc;
				E.lcost = bestc;
				E.s++;
				cout<< E.x[n - 2] <<" "<< E.x[n - 1]<<endl;
				H.insert(E);
			}
			else
				delete[]E.x;
		}
		else
		{
			for (int i = E.s; i<n; i++)
				if (a[E.x[E.s]][E.x[i]] != 32767)
				{
					int cc = E.cc + a[E.x[E.s]][E.x[i]];
					int rcost = E.rcost - Minout[E.x[E.s]];
					int b = cc + rcost;
					if (b<bestc)
					{
						bestc = b;
						MinstackNode N;
						N.x = new int[n];
						for (int j = 0; j<n; j++)
							N.x[j] = E.x[j];
						N.x[E.s + 1] = E.x[i];
						N.x[i] = E.x[E.s + 1];
						N.cc = cc;
						N.s = E.s + 1;
						N.lcost = b;
						N.rcost = rcost;
						H.insert(N);
					}
				}
			delete[]E.x;
		}
		if (!H.StackEmpty()) //If the stack is not empty, take the next extension node
			E = H.get();

		else
		{
			break;
		}
	}
	return bestc;
}

int main()
{
	int i,j;
	P_laying aa;
	int n;
	cout << "input the number of the elements:";
	cin >> n;
	aa.n = n;
	aa.a = new int*[n];
	for (i = 0; i<n; ++i)
	{
		aa.a[i] = new int[3];
	}
	cout << "input the value:";
	for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
            cin >> aa.a[i][j];
    }
	int k;
	k = aa.Ptsp();
	cout << k;
	getchar();
}
