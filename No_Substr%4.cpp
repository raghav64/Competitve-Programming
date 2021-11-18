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
string str;
ull dp[300005][11];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ull i,j;
    cin>>str;
    dp[i][(str[0]-'0')%4]++;
    for(i=1;i<str.length();i++)//Here i denotes length. Now extend the dp
    {
        dp[i][(str[i]-'0')%4]++;
        for(j=0;j<10;j++)
        {
            dp[i][(j*10+str[i]-'0')%4]+=dp[i-1][j];
        }
    }
    ull ans=0;
    for(i=0;i<str.length();i++)
        ans+=dp[i][0];
    cout<<ans;
    return 0;
}