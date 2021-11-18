//Simply O(n^3) relaxation based on k as intermediate vertex
//THIS CODE IS FOR DIRECTED EDGES
#include<bits/stdc++.h>
using namespace std;
#define INF 10000007
int edges[100][100],dist[100][100];
int n,e;
void warshall(int x)
{
    int i,j,k;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            dist[i][j]=edges[i][j];

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                if(dist[i][k]!=INF && dist[k][j]!=INF && dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<dist[i][j]<<" ";
        cout<<"\n";
    }
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    int x,y,w,i,j;
    cout<<"Enter no of nodes\n";
    cin>>n;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            edges[i][j]=INF;
    cout<<"Enter no edges\n";
    cin>>e;
    cout<<"Enter edges with weights\n";
    for(i=0;i<e;i++)
    {
        cin>>x>>y>>w;
        edges[x][x]=0;
        edges[y][y]=0;
        edges[x][y]=w;
    }
    cout<<"Enter starting vertex\n";
    cin>>x;
    warshall(x);
    return 0;
}
