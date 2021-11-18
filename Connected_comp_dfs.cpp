//DFS can be implemented using stack or recursion. We choose a node as a starting point and push it's neighbours in stack and
//mark them as visited and pop the top off stack
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
bool visit[100]={false};
vector<int> vec[100];
void dfs(int s)
{
    visit[s]=true;
    for(int k=0;k<vec[s].size();k++)
        if(!(visit[vec[s][k]]))
            dfs(vec[s][k]);
}
int main()
{
    ios::sync_with_stdio(false);
    int x,y,i,n,e;
    cout<<"Enter the number of nodes\n";
    cin>>n;
    cout<<"Enter no of edges\n";
    cin>>e;
    cout<<"Enter the edges for undirected graph\n";
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    int connected_comp=0;
    for(i=1;i<=n;i++)
        if(!visit[i])
        {
            dfs(i);
            connected_comp++;
        }
    cout<<"Number of connected components are:"<<connected_comp<<endl;
    return 0;
}
