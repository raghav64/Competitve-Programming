//Undirected graph
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cout<<"Enter the number of nodes"<<endl;
    int n;
    cin>>n;
    bool adj[n+1][n+1];
    memset(adj,false,sizeof(adj));
    int x,y,i,k;
    cout<<"Enter no of edges\n";
    cin>>k;
    cout<<"Enter the edges\n";
    for(i=0;i<k;i++)
    {
        cin>>x>>y;
        adj[x][y]=true;
        adj[y][x]=true;
    }
    cout<<"Enter -1 -1 to break"<<endl;
    while(1){
        cout<<"Enter the node numbers"<<endl;
        cin>>x>>y;
            if(x==-1 && y==-1)
            break;
        if(adj[x][y])
            cout<<"Connected"<<endl;
        else
            cout<<"Not connected"<<endl;
    }
    return 0;
}
