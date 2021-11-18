//MST of a given graph is a subgraph that is a tree connecting all the vertices
//Time complexity = O(E Log(V))
#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int sizee[100005];
vector<pair<int,pair<int,int> > >vec;
int n,e;
int root(int i)
{
    while(arr[i]!=i)
    {
        arr[i]=arr[arr[i]];
        i=arr[i];
    }
    return i;
}
void union_nodes(int a,int b)
{
    int ra=root(a);
    int rb=root(b);
    if(sizee[ra]>sizee[rb])
    {
        arr[rb]=ra;
        sizee[ra]+=sizee[rb];
    }
    else{
        arr[ra]=rb;
        sizee[rb]+=sizee[ra];
    }
    return ;
}
int kruksal(vector<pair<int,pair<int,int> > > & vec)
{
    long int ctr=0,mincost=0,cost;
    for(int i=0;i<vec.size();i++)
    {
        cost=vec[i].first;
        int x= vec[i].second.first;
        int y= vec[i].second.second;
        if(root(x)!=root(y)){
            mincost+=cost;
            union_nodes(x,y);
            ctr++;
            if(ctr==n-1)// optimization to stop iteration as we know MST will have n-1 edges strictly (tree property)
                break;
        }
    }
    return mincost;
}
int main()
{
    ios::sync_with_stdio(false);
    cout<<"Enter no of nodes and edges\n";
    int i,x,y,w;
    cin>>n>>e;
    for(i=1;i<=n;i++)
    {
        arr[i]=i;
        sizee[i]=1;
    }
    cout<<"Enter edges with their weights\n";
    for(i=0;i<e;i++)
    {
        cin>>x>>y>>w;
        vec.push_back(make_pair(w,make_pair(x,y)));
    }
    sort(vec.begin(),vec.end());
    cout<<"Minimum cost="<<kruksal(vec)<<"\n";
    return 0;
}
