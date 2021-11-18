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
ull n,bit1[1000006],bit2[1000006];
vector<ull> vec,arr;
void update(ull BIT[],ull idx,ull val)
{
    for(;idx<=n;idx+=((idx)&(-idx)))
        BIT[idx]+=val;
}
ull query(ull BIT[],ull idx)
{
    ull sum=0;
    for(;idx>0;idx-=((idx)&(-idx)))
        sum+=BIT[idx];
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ull i,j,k,ans;
    memset(bit1,0,sizeof(bit1));
    memset(bit2,0,sizeof(bit2));
    cin>>n;
    for(i=0;i<n;i++){
        cin>>j;
        arr.push_back(j);
        vec.push_back(j);
    }
    sort(vec.begin(),vec.end());
    for(i=0;i<arr.size();i++)
    {
        k=arr[i];
        arr[i]=lower_bound(vec.begin(),vec.end(),k)-vec.begin()+1;
    }
    ans=0;
    for(i=arr.size()-1;i>=0;i--)
    {
        update(bit1,arr[i],1);
        j=query(bit1,arr[i]-1);
        update(bit2,arr[i],j);
        ans+=query(bit2,arr[i]-1);
    }
    cout<<ans;
    vec.clear();
    arr.clear();
    return 0;
}