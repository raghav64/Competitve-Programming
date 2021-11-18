//Priority queue is by default max heap To convert it into min heap we do the following:
// priority_queue<int,vector<int>,greater<int> >pq; for user defined class we change int to other datatype and also use cmp func
// instead of greater
#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int> > >graph;
bool visit[100005]={false};
int n,e;
//bfs type
int prim(int x)
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
    long mincost=0;
    pair<int,int> p;
    pq.push(make_pair(0,x));
    while(!pq.empty())
    {
        p=pq.top();
        pq.pop();
        x=p.second;
        if(!visit[x])
        {
            visit[x]=true;
            mincost+=p.first;
            for(int i=0;i<graph[x].size();i++)
            {
                if(!visit[graph[x][i].second])
                    pq.push(graph[x][i]);
            }
        }
    }
    return mincost;
}
int main()
{
    ios::sync_with_stdio(false);
    cout<<"Enter number of nodes and edges\n";
    int i,x,y,w;
    cin>>n>>e;
    graph.resize(n+1);
    cout<<"Enter the edges with weights\n";
    for(i=0;i<e;i++)
    {
        cin>>x>>y>>w;
        graph[x].push_back(make_pair(w,y));
        graph[y].push_back(make_pair(w,x));
    }
    cout<<"Mincost="<<prim(1)<<endl;
    return 0;
}
