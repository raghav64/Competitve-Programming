#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,i,j;
    cin>>n;
    int cost[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>cost[i][j];
    }
    int k = (1<<n) ;
    k--;

    int dp[k+2];
    memset(dp,INT_MAX,sizeof(dp));
    dp[0]=0;
    int mask;
    for(mask=0;mask<k;mask++)
    {
        i= __builtin_popcount(mask);// number of
        for(j=0;j<n;j++)
        {
            if((mask&(1<<j))==0)
                dp[mask|(1<<j)]=min(dp[mask|(1<<j)],dp[mask]+cost[i][j]);
        }
    }
    cout<<dp[k]<<"\n";
    return 0;
}
