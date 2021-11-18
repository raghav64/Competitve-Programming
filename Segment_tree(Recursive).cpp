//Implementing SegTree for sum over range
#include<iostream>
using namespace std;
int seg[200000];
int arr[100000];
void build(int node,int start,int end)
{
    if(start==end)
        seg[node]=arr[start];
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        seg[node]=seg[2*node]+seg[2*node+1];
    }
}
void update(int node,int start,int end,int idx,int val)
{
    if(start==end)
    {
        arr[idx]+=val;
        seg[idx]+=val;
    }
    else
    {
        int mid= (start+end)/2;
        if(idx>=start && idx<=mid)
            update(2*node,start,mid,idx,val);
        else
            update(2*node+1,mid+1,end,idx,val);
        seg[node]=seg[2*node]+seg[2*node+1];
    }
}
//3 cases for query:Range completely inside,outside and partial
int query(int node,int start,int end,int l,int r)
{
    if(start>r || l>end)
        return 0;
    else if(l<=start && end<=r)
        return seg[node];

    int mid=(start+end)/2;
    int p1= query(2*node,start,mid,l,r);
    int p2= query(2*node+1,mid+1,end,l,r);
    return p1+p2;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,i,l,r;
    cout<<"Enter size\n";
    cin>>n;
    cout<<"Enter the array to be operated\n";
    for(i=0;i<n;i++)
        cin>>arr[i];
    build(1,0,n-1);
    cout<<"Tree:\n";
    for(i=1;i<2*n;i++)
        cout<<seg[i]<<" ";
    cout<<endl;
    cout<<"Enter the range assuming 0-based indexing\n";
    cin>>l>>r;
    cout<<"Ans="<<query(1,0,n-1,l,r);
    return 0;
}
