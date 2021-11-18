// dp[mask][j] is true if subset represented by mask is visited with j being
// the last visited vertex 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,m,i,j,x,y,k,mask;
    cin>>n>>m;
    bool adj[n+1][n+1];
    memset(adj,false,sizeof(adj));
    for(i=0;i<m;i++){
        cin>>x>>y;
        adj[x][y]=true;
        adj[y][x]=true;
    }
    bool dp[(1<<n)][n+1];
    memset(dp,false,sizeof(dp));
    for(i=0;i<n;i++)
        dp[(1<<i)][i]=true;
    for(mask=0;mask<(1<<n);mask++)
    {
        for(j=0;j<n;j++)
        {
            if((mask&(1<<j))!=0)
            {
                if(dp[mask][j]==true)
                {
                    for(k=0;k<n;k++)
                    {
                        if((mask&(1<<k))==0)
                        {
                            if(adj[j][k]==true){
                                dp[mask|(1<<k)][k]=true;
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<n;i++){
        if(dp[(1<<n)-1][i]==true)
        {
            cout<<"YES\n";
            break;
        }
    }
    if(i==n)
        cout<<"NO\n";
    return 0;
}
