#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
#define MAX 20
using namespace std;
int n,m;
struct Edge//±ß
{
    int u,v;
};
struct Point
{
    int id;
    int degree,adj_degree;
} point[MAX];
vector<Edge> E;
vector<int> G[MAX];
int degree[MAX],adj_degree[MAX];//¶¥µã¶ÈÊý
bool del[MAX],vis[MAX];
int V_cnt,Vv_cnt,E_cnt;
void init_edge()
{
    E.clear();
    for(int i=1; i<=n; i++)
        G[i].clear();
}
void add_edge(int u,int v)
{
    E.push_back((Edge)
    {
        u,v
    });
    E.push_back((Edge)
    {
        v,u
    });
    int _size=E.size();
    G[u].push_back(_size-2);
    G[v].push_back(_size-1);
}
bool cmp(Point a,Point b)
{
    return a.adj_degree>b.adj_degree;
}
int pretreat()
{
    for(int i=1; i<=n; i++)
    {
        point[i].degree=0;
        if(del[i])
            continue;
        for(int j=0,_size=G[i].size(); j<_size; j++)
        {
            Edge& e=E[G[i][j]];
            if(!del[e.v])
                point[i].degree++;
        }
        if(point[i].degree==0)
            del[i]=1;
    }
    for(int i=1; i<=n; i++)
    {
        if(del[i])
        {
            point[i].adj_degree=0;
            continue;
        }
        point[i].adj_degree=point[i].degree;
        for(int j=0,_size=G[i].size(); j<_size; j++)
            point[i].adj_degree+=point[E[G[i][j]].v].degree;
    }
    sort(point+1,point+n+1,cmp);
}
void MinVC_MGA(bool ans[])
{
    memset(del,0,sizeof(del));
    for(int i=1; i<=n; i++)
        point[i].id=i;
    E_cnt=0;
    while( E_cnt < m )
    {
        memset(vis,0,sizeof(vis));
        pretreat();
        V_cnt=0;
        Vv_cnt=0;
        for(int i=1; i<=n; i++)
            if(!del[i])
                Vv_cnt++;
        for(int i=1; i<=n; i++)
        {
            if(del[point[i].id])
                continue;
            if(vis[point[i].id])
                continue;
            ans[point[i].id]=1;
            del[point[i].id]=1, Vv_cnt--;
            for(int j=0,_size=G[point[i].id].size(); j<_size; j++)
            {
                Edge& e=E[G[point[i].id][j]];
                if(del[e.v])
                    continue;
                E_cnt++;
                if(!vis[e.v])
                {
                    vis[e.v]=1;
                    V_cnt++;
                }
            }
            if(V_cnt>=Vv_cnt)
                break;
        }
    }
}

int main()
{
    while(scanf("%d %d\n",&n,&m)!=EOF)
    {
        init_edge();
        for(int i=1,u,v; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            add_edge(u,v);
        }
        bool ans[n+5];
        memset(ans,0,sizeof(ans));
        MinVC_MGA(ans);
        for(int i=1; i<=n; i++)
        {
            if(ans[i]==1)
            {
                cout<<i<<endl;
            }
        }
    }
}
