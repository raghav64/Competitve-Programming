#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string.h>
#include <limits.h>
#include <cmath>
using namespace std;
#define ull long long int
#define mod 1000000007
#define INF 100000000000014
#define LIM 1000006
int dp[LIM];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,x,i,j;
    for(i=0;i<LIM;i++)
        dp[i]=LIM;
    dp[1]=1;
    for(i=2;i<LIM;i++)
    {
        dp[i]=min(dp[i],1+dp[i-1]);
        for(j=1;j<=i and i*j<LIM;j++)
            dp[i*j]=min(1+dp[i],dp[i*j]);
    }
    cin>>t;
    while(t--)
    {
        cin>>x;
        cout<<dp[x]<<"\n";
    }
    return 0;
}