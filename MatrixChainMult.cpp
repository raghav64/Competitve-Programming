//Given an array p with pi-1*pi as matrix dimensions. Find optimal 
// way of multiplying these matrices
//n should be atleast 3 for 2 matrices

#include<bits/stdc++.h>
using namespace std;
#define ull long long int
#define mod 1000000007
#define INF 100000000000014
int arr[1003];
int dp[1003][1003];
int rec(int i,int j)
{
    if(i==j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans=mod;
    for(int k=i;k<j;k++)
    {
        ans=min(ans,rec(i,k)+rec(k+1,j)+arr[i-1]*arr[k]*arr[j]);
    }
    return dp[i][j]=ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i,j,n;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            dp[i][j]=-1;
    cout<<rec(1,n-1);
    return 0;
}