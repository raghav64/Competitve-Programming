//This algorithm will print all strongly connected components in a directed graph
#include<iostream>
#include<vector>
#include<string.h>
#include<stack>
using namespace std;
vector<vector<int> >graph;
vector<vector<int> >revgraph;
bool visit[100005];
stack<int> s;
void firstpass(int i)
{
    int j;
    visit[i]=true;
    for(j=0;j<graph[i].size();j++)
    {
        if(!visit[graph[i][j]])
            firstpass(graph[i][j]);
    }
    s.push(i);
}
void secondpass(int i)
{
    visit[i]=true;
    cout<<i<<" ";
    for(int j=0;j<revgraph[i].size();j++)
    {
        if(!visit[revgraph[i][j]])
            secondpass(revgraph[i][j]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int i,n,m,x,y;
    cout<<"Enter number of nodes and edges\n";
    cin>>n>>m;
    graph.resize(n+1);
    revgraph.resize(n+1);
    cout<<"Enter the edges(1-based indexing)\n";
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        revgraph[y].push_back(x);
    }
    memset(visit,false,sizeof(visit));
    for(i=1;i<=n;i++){
        if(!visit[i])
            firstpass(i);
    }
    memset(visit,false,sizeof(visit));
    cout<<"All sccs are:\n";
    while(!s.empty())
    {
        i=s.top();
        if(!visit[i]){
            secondpass(i);
        cout<<"\n";
        }
        s.pop();
    }
    return 0;
}
