#include<iostream>
using namespace std;
struct Node
{
    char name[10];//name of the road
    int color;//the number of color
};
struct Color
{
    int *number_road;//node;
    int number;//number
};
int main()
{
    int now_color = 1;
    Color *color;//improve the algorithm
    int i, j, k;
    int n;//the number of the road
    cout << "print the number of the roads:" << endl;
    cin >> n;
    Node *v;
    v = new Node[n];
    for (i = 0; i<n; ++i)
    {
        cout << "haha";
        cin >> v[i].name;
        v[i].color = 0;
    }//create nodes;
    color = new Color[n];
    for (i = 0; i<n; ++i)
    {
        color[i].number_road = new int[n];
        color[i].number = 0;
    }
    int **e;
    e = new int*[n];
    for (i = 0; i < n; ++i)
    {
        e[i] = new int[n];
    }// create the edge;
    cout << "print the connection of the roads:" << endl;
    for (i = 0; i<n; ++i)
    {
        for (j = 0; j<n; ++j)
        {
            cin >> e[i][j];
        }
    }
    for (i = 0; i<n; ++i)
    {
        if (v[i].color == 0)
        {
            v[i].color = now_color;
            cout << "the node" << v[i].name << " 's color is " << now_color << endl;
            color[now_color].number_road[color[now_color].number] = i;
            color[now_color].number++;
            for (j = 1; j<n; ++j)
            {
                if (e[i][j] == 0 && v[j].color == 0)
                {
                    int flag = 1;
                    for (k = 0; k < color[now_color].number; ++k)
                    {
                        if (e[color[now_color].number_road[k]][j] == 1)
                        {
                            flag = 0;
                        }
                    }
                    if (flag == 1)
                    {
                        v[j].color = now_color;
                        cout << "the node" << v[j].name << " 's color is " << now_color << endl;
                        color[now_color].number_road[color[now_color].number] = j;
                        color[now_color].number++;
                    }

                }
            }
            now_color++;
        }
    }
    cout << now_color - 1;
}
