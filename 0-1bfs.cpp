//We make a pair which stores the neighbouring nodes as first and min distance of first and that node
#include<iostream>
#include<deque>
#include<vector>
#include<string.h>
#include<limits.h>
using namespace std;
int dist[20]={INT_MAX};
vector<pair<int ,int> > vec[20];
void bfs01(int s)
{
    deque<int> deq;
    deq.push_back(s);
    dist[s]=0;
    int p;
    while(!deq.empty())
    {
        p=deq.front();
        deq.pop_front();
        for(int i=0;i<vec[p].size();i++)
        {
            if(dist[vec[p][i].first]> dist[p]+ vec[p][i].second)
            {
                dist[vec[p][i].first]=dist[p]+vec[p][i].second;
                if(!vec[p][i].second)
                    deq.push_front(vec[p][i].first);
                else
                    deq.push_back(vec[p][i].first);
            }
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    int x,y,i,n,e,w;
    cout<<"Enter the number of nodes\n";
    cin>>n;
    cout<<"Enter no of edges\n";
    cin>>e;
    cout<<"Enter the edges for undirected graph with weights\n";
    for(i=0;i<e;i++)
    {
        cin>>x>>y>>w;
        vec[x].push_back(make_pair(y,w));
        vec[y].push_back(make_pair(x,w));
    }
    cout<<"Enter the starting point\n";
    cin>>x;
    bfs01(x);
    //cout<<"Distance of n4="<<dist[4]<<endl;
    for(i=0;i<n;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
    return 0;
}
