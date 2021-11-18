#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> vec[20];
bool visit[20]={false};
void bfs(int s)
{
    queue<int> q;
    int p,j;
    q.push(s);
    visit[s]=true;
    while(!q.empty())
    {
        p=q.front();
        cout<<p<<" ";
        q.pop();
        for(j=0;j<vec[p].size();j++)
            if(!(visit[vec[p][j]]))
                {visit[vec[p][j]]=true;q.push(vec[p][j]);}
    }
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
    cout<<"Enter starting point\n";
    cin>>x;
    bfs(x);
    return 0;
}
