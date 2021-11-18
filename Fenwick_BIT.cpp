//Fenwick tree is applicable to only associative properties and having an inverse
//This code is for sum tree
//Time complexity is same as segtree but saves on space complexity
//1-based indexing is important to avoid infinite loop in update as for 0 last bit set is none
#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int BIT[100005];
int n;
void update(int idx,int val)
{
    for(;idx<=n;idx+=((idx)&(-idx)))
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
    int i;
    cout<<"Enter number of elements\n";
    cin>>n;
    cout<<"Enter array\n";
    for(i=1;i<=n;i++)
        cin>>arr[i];
    memset(BIT,0,sizeof(BIT));
    //To build BIT we update each node with corresponding array value
    for(i=1;i<=n;i++)
        update(i,arr[i]);
        cout<<query(3)<<"\n";
        update(1,2);
    for(i=1;i<=n;i++)
        cout<<"BIT["<<i<<"]="<<BIT[i]<<"\n";
    cout<<query(3)<<"\n";
    cout<<query(4)-query(1)<<"\n";//query(r)-query(l-1)
    return 0;
}
