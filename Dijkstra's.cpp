//O(ElogV) time complexity
#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int> > >graph;
#define INF 100000008
int dist[100005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
bool finalize[100005];
void dijkstra(int x)
{
    int p,vertex,weight;
    pq.push(make_pair(0,x));
    while(!pq.empty())
    {
        p=pq.top().second;
        pq.pop();
        if(finalize[p])//if any node's min dist has been finalized it should not be calculated again
            continue;
        for(int i=0;i<graph[p].size();i++)
        {
            vertex=graph[p][i].first;
            weight=graph[p][i].second;
            if(!finalize[vertex] && dist[vertex]>dist[p]+weight){
                dist[vertex]=dist[p]+weight;
                pq.push(make_pair(dist[vertex],vertex));
            }
        }
        finalize[p]=true;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,i,e,x,y,w;
    cout<<"Enter number of nodes\n";
    cin>>n;
    graph.resize(n+2);
    cout<<"Enter no of edges\n";
    cin>>e;
    cout<<"Enter the edges with weights\n";
    for(i=0;i<e;i++)
    {
        cin>>x>>y>>w;
        graph[x].push_back(make_pair(y,w));
        graph[y].push_back(make_pair(x,w));
    }
    memset(dist,INF,sizeof(dist));
    memset(finalize,false,sizeof(finalize));
    cout<<"Enter the starting point\n";
    cin>>x;
    dist[x]=0;
    dijkstra(x);
    for(i=1;i<=n;i++)
        cout<<dist[i]<<" ";
    return 0;
}
