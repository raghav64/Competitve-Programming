//This code is for directed graph
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    vector<int> vec[10];// array of vectors
    cout<<"Enter the number of nodes"<<endl;
    int x,y,i,e,n,j;
    cin>>n;
    cout<<"Enter no of edges"<<endl;
    cin>>e;
    cout<<"Enter the edges\n";
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        vec[x].push_back(y);
    }
    cout<<"Adjacency list is:"<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<i<<"->";
        for(j=0;j<vec[i].size();j++)
        {
            if(j==vec[i].size()-1)
                cout<<vec[i][j];
            else
                cout<<vec[i][j]<<",";
        }
        cout<<endl;
    }
    return 0;
}
