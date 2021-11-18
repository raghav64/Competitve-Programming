//disc[i] is an array of time on which node i is discovered
//low[i] is value of lowest time node reachable from i'th node   
#include<bits/stdc++.h>
using namespace std;
#define ull long long int
#define mod 1000000007
#define INF 100000000000014
vector<vector<int> >graph;
bool visit[100005],ap[100005];
int disc[100005],low[100005],parent[100005];
int n,m,tim=0;
void dfs(int u)
{
    visit[u]=true;
    low[u]=disc[u]=++tim;
    int child=0;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(!visit[v])
        {
            parent[v]=u;
            child++;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(parent[u]!=-1 and low[v]>=disc[u])
                ap[u]=true;
            if(parent[u]==-1 and child>1)
                ap[u]=true;
        }
        else if(v!=parent[u])
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
    }
    for(i=1;i<=n;i++)
    {
        visit[i]=false;
        ap[i]=false;
        parent[i]=-1;
        low[i]=mod;
    }
    tim=0;
    for(i=1;i<=n;i++)
    {
        if(!visit[i])
            dfs(i);
    }
    x=0;
    cout<<"Articulation points=\n";
    for(i=1;i<=n;i++)
        if(ap[i]){
            cout<<i<<"\n";
            x++;
        }
    cout<<"Total number of aps="<<x<<endl;
    return 0;
}