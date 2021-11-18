#include<bits/stdc++.h>
using namespace std;
int BIT[100005]={0},n,me=INT_MIN;
void update(int idx,int val)
{
    for(;idx<=me;idx+=((idx)&(-idx)))//we can order the elements acc to sorted array and avoid me by replacing it with n.See gfg
        BIT[idx]+=val;
}
int query(int idx)
{
    int sum=0;
    for(;idx>0;idx-=((idx)&(-idx)))
        sum+=BIT[idx];
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    int i,ans=0;
    cin>>n;
    int arr[n+1];
    for(i=0;i<n;i++){
        cin>>arr[i];
        me=max(me,arr[i]);
    }
    for(i=n-1;i>=0;i--)
    {
        update(arr[i],1);
        ans+=query(arr[i]-1);
    }
    cout<<"Inversions: "<<ans<<"\n";
    return 0;
}
