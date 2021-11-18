//Bellman ford runs n-1 times relaxing each edge in a random order.After n-1 iterations we have shortest distance path
// then we check for negative weight cycle(cycle with total weight negative) by doing one more iteration
// If dist of any node further decreases then graph contains negative cycle and shortest path can never be achieved.
//THIS CODE IS FOR DIRECTED GRAPH
#include<bits/stdc++.h>
using namespace std;
#define INF 10000007
vector<pair<int,pair<int,int> > >vec;
int dist[100005],n,e;
void bellman(int x)
{
    int p,q;
    for(p=0;p<n-1;p++){
        for(q=0;q<e;q++)
        {
            int weight=vec[q].first;
            int src=vec[q].second.first;
            int dest=vec[q].second.second;
           if(dist[src]!=INF && dist[dest]>dist[src]+weight)
                dist[dest]=dist[src]+weight;
        }
    }
    for(p=0;p<e;p++)
    {
        int weight=vec[p].first;
        int src=vec[p].second.first;
        int dest=vec[p].second.second;
        if(dist[src]!=INF && dist[dest]>dist[src]+weight)
            {
                cout<<"Negative cycle found\n";
                break;
            }
    }
    if(p==e)
    {
        for(int i=1;i<=n;i++)
            cout<<dist[i]<<" ";
        cout<<"\n";
    }
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    int i,x,y,w;
    cout<<"DIRECTED GRAPH\n";
    cout<<"Enter number of nodes\n";
    cin>>n;
    cout<<"Enter number of edges\n";
    cin>>e;
    cout<<"Enter edges with weight\n";
    vec.clear();
    for(i=0;i<e;i++)
    {
        cin>>x>>y>>w;
        vec.push_back(make_pair(w,make_pair(x,y)));
    }
    cout<<"Enter source\n";
    cin>>x;
    for(i=1;i<=n;i++)
        dist[i]=INF;
    dist[x]=0;
    bellman(x);
    return 0;
}
