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
int n,m;
string str;
int mofo(char ch)
{
    int i=0,j=0,c=0,ans=1;
    while(i<n and j<n)
    {
        while(j<n)
        {
            if(str[j]!=ch)
                c++;
            if(c>m)
            {
                ans=max(ans,j-i);
                break;
            }
            j++;
        }
        ans=max(ans,j-i);
        while(i<n and j<n and str[i]==ch)
            i++;
        i++;
        j++;
        c--;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ull t,i,ans,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cin>>str;
        ans=-1;
        for(i=0;i<26;i++){
            char ch = char('a'+i);
            k=mofo(ch);
            ans=max(ans,k);
        }
        for(i=0;i<26;i++){
            char ch = char('A'+i);
            k=mofo(ch);
            ans=max(ans,k);
        }
        cout<<ans<<"\n";
    }
    return 0;
}