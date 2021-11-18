#include<iostream>
#include<string.h>
using namespace std;
int arr[100000];
int tree[200000];
int lazy[200000];
void build_tree(int node,int start,int end)
{
    if(start>end)
        return;
    if(start==end){
        tree[node]=arr[start];
        return;
    }
    build_tree(2*node,start,(start+end)/2);
    build_tree(2*node+1,((start+end)/2)+1,end);
    tree[node]=tree[2*node]+tree[2*node+1];
}
//Adds val to arr[idx]
void update_node(int node,int start,int end,int idx,int val)
{
    if(start==end)
    {
        arr[idx]+=val;//updates the original array
        tree[node]+=val;
    }
    else
    {
        int mid= (start+end)/2;
        if(start<=idx && idx<=mid)
            update_node(2*node,start,mid,idx,val);
        else
            update_node(2*node+1,mid+1,end,idx,val);

        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
int query(int node,int start,int end,int l,int r)
{
    if(r<start || l>end)
        return 0;
    if(start>=l && end<=r)
        return tree[node];//Think of it as a base case or at start==end what would be returned.Here arr[i] would be tree[start] at base.

    int mid=(start+end)/2;
    int p1=query(2*node,start,mid,l,r);
    int p2=query(2*node+1,mid+1,end,l,r);
    return (p1+p2);
}
//Updates values in range l to r in O(nlog(n)) whereas lazy prop does in O(log(n))
void updateRange(int node,int start,int end,int l,int r,int val)
{
    if(start>r || end<l || start>end)
        return;

    if(start==end)
    {
        tree[node]+=val;
    }
    else
    {
        int mid=(start+end)/2;
        updateRange(2*node,start,mid,l,r,val);
        updateRange(2*node+1,mid+1,end,l,r,val);

        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
//Lazy propagation
void updatelazy(int node,int start,int end,int l,int r,int val)
{
    //update irrespective of range check for start and end
    if(lazy[node]!=0)
    {
        tree[node]+=(end-start+1)*lazy[node];
//As in a segment tree a node (tree[node] )gives sum of array values it covers ,
//so we updated tree node as tree[node]+=(end-start+1)*v ,later we will update left and right node
//For RMQ we don't need to do this.Just add val to node
        if(start!=end)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>end || r<start || l>end)
        return;
    if(l<=start && r>=end)
    {
        tree[node]+=(end-start+1)*val;
        if(start!=end)
        {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return;
    }
    int mid=(start+end)/2;
    updatelazy(2*node,start,mid,l,r,val);
    updatelazy(2*node+1,mid+1,end,l,r,val);
    tree[node]=tree[2*node]+tree[2*node+1];
}
int querylazy(int node,int start,int end,int l,int r)
{
    //update irrespective of range check for start and end #imp
    if(lazy[node]!=0)
    {
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>end || r<start || l>end)
        return 0;
    if(l<=start && r>=end)
        return tree[node];

    int mid=(start+end)/2;
    int p1=querylazy(2*node,start,mid,l,r);
    int p2=querylazy(2*node+1,mid+1,end,l,r);
    return (p1+p2);
}
int main()
{
    ios::sync_with_stdio(false);
    int n,i,l,r;
    memset(lazy,0,sizeof(lazy));
    cout<<"Enter size\n";
    cin>>n;
    cout<<"Enter the array to be operated\n";
    for(i=0;i<n;i++)
        cin>>arr[i];
    build_tree(1,0,n-1);
    cout<<"Tree:\n";
    for(i=1;i<2*n;i++)
        cout<<tree[i]<<" ";
    cout<<endl;
    cout<<"Enter l and r assuming 0-based indexing\n";
    cin>>l>>r;
    cout<<"Ans:"<</*query(1,0,n-1,l,r)<<*/querylazy(1,0,n-1,l,r)<<"\n";
    update_node(1,0,n-1,1,3);
    cout<<"Tree:\n";
    for(i=1;i<2*n;i++)
        cout<<tree[i]<<" ";
    cout<<endl;
    cout<<"Enter l and r assuming 0-based indexing\n";
    cin>>l>>r;
    cout<<"Ans:"<<query(1,0,n-1,l,r)<<"\n";
    //updateRange(1,0,n-1,0,2,1);
    updatelazy(1,0,n-1,0,2,1);
    cout<<"Tree:\n";
    for(i=1;i<2*n;i++)
        cout<<tree[i]<<" ";
    cout<<endl;
    cout<<"Lazy:\n";
    for(i=1;i<2*n;i++)
        cout<<lazy[i]<<" ";
    cout<<endl;
    cout<<"Enter l and r assuming 0-based indexing\n";
    cin>>l>>r;
    cout<<"Ans:"<</*query(1,0,n-1,l,r)*/querylazy(1,0,n-1,l,r)<<"\n";
    cout<<"Lazy:\n";
    for(i=1;i<2*n;i++)
        cout<<lazy[i]<<" ";
    cout<<endl;
    return 0;
}
