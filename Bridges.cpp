#include<bits/stdc++.h>
using namespace std;
#define ull long long int
#define mod 1000000007
#define INF 100000000000014
vector<vector<int> >graph;
vector<pair<int,int> >edges;
int n,m;
bool visit[10004];
int low[10004],disc[10004],parent[10004],tim;
set<pair<int,int> >ans;
void dfs(int u)
{
    visit[u]=true;
    low[u]=disc[u]=++tim;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(!visit[v])
        {
            parent[v]=u;
            dfs(v);

            low[u]=min(low[u],low[v]);

            if(low[v]>disc[u])
                ans.insert(make_pair(u,v));
        }
        else if(parent[u]!=v)
            low[u]=min(low[u],disc[v]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i,x,y;
    cin>>n>>m;
    graph.resize(n+3);
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        edges.push_back(make_pair(x,y));
    }
    memset(disc,0,sizeof(disc));
    for(i=1;i<=n;i++)
    {
        visit[i]=false;
        parent[i]=-1;
        low[i]=mod;
    }
    tim=0;
    for(i=1;i<=n;i++)
    {
        if(!visit[i])
            dfs(i);
    }
    for(i=0;i<edges.size();i++)
    {
        x=edges[i].first;
        y=edges[i].second;
        if(ans.find(make_pair(x,y))!=ans.end() or ans.find(make_pair(y,x))!=ans.end())
            cout<<x<<"->"<<y<<" is a bridge\n";
    }
    return 0;
}