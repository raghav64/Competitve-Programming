//Topological ordering must start from a vertex with no incoming edge then we can dfs from this node and keep track of
// finish time of each node. Decreasing finish time gives us order because node having smaller finish time can't have
// an edge to a node having greater finish time
// This is similar to kosaraju's first pass in which we push the vertices in stack according to their finish time
#include<bits/stdc++.h>
using namespace std;
int n,e,cur_time;
vector<vector<int> >graph;
stack<int> s;
bool visit[100005];
void dfs_topo(int x)
{
    visit[x]=true;
    for(int k=0;k<graph[x].size();k++)
    {
        if(!visit[graph[x][k]])
            dfs_topo(graph[x][k]);
    }
    s.push(x);
}
int main()
{
    ios::sync_with_stdio(false);
    int i,x,y;
    cout<<"Enter the nodes of DAG\n";
    cin>>n;
    cout<<"Enter no of edges\n";
    cin>>e;
    cout<<"Enter the edges of DAG\n";
    graph.resize(100005);
    memset(visit,false,sizeof(visit));
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        graph[x].push_back(y);
    }
    memset(visit,false,sizeof(visit));
    for(i=1;i<=n;i++)
        if(!visit[i])
            dfs_topo(i);
    cout<<"Topological Order:\n";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
