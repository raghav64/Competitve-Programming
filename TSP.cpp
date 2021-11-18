
#include<bits/stdc++.h>
using namespace std;
#define INF 100005
int main()
{
    ios::sync_with_stdio(false);
    int i,j,mask,k,x,y,w,n,m,ans;
    cin>>n>>m;
    int adj[n+1][n+1];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
        adj[i][j]=INF;
        adj[j][i]=INF;
    }
    for(i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        adj[x][y]=w;
        adj[y][x]=w;
    }
    int dp[(1<<n)][n+1];
    for(i=0;i<(1<<n);i++)
    {
        for(j=0;j<n;j++)
            dp[i][j]=INF;
    }
    for(i=0;i<n;i++)
        dp[(1<<i)][i]=0;
    w=1<<n;
    w--;
    for(mask=0;mask<(1<<n);mask++)
    {
        for(j=0;j<n;j++)
        {
            if((mask&(1<<j))!=0)
            {
               for(k=0;k<n;k++)
               {
                   if((mask&(1<<k))==0)
                    dp[mask|(1<<k)][k]=min(dp[mask|(1<<k)][k],dp[mask][j]+adj[j][k]);
               }
            }
        }
    }
    ans=INT_MAX;
    for(i=0;i<n;i++)
    {
        ans=min(ans,dp[(1<<n)-1][i]);
    }
    if(ans==INF)
        cout<<"No such path exists\n";
    else
        cout<<ans<<"\n";
    return 0;
}
