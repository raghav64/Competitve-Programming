#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
int tree[100000];
int compare(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.first==p2.first){
//note that if the element values are equal the latter element of original array comes first
        return p1.second>p2.second;
    }
    return p1.first<p2.first;
}
//building tree -more like updating tree
void build_tree(int node,int start,int end,int idx,int val)
{
    //idx is index of original element
    //idx=pair.second
    //val=1+max of
    if(idx<start || idx>end)
        return;
    if(start==end)
        {
            tree[node]=val;
            return;
        }
    int mid=(start+end)/2;

    build_tree(2*node,start,mid,idx,val);
    build_tree(2*node+1,mid+1,end,idx,val);
    tree[node]=max(tree[2*node],tree[2*node+1]);

}
int findmax(int node,int start,int end,int l,int r)
{
    if(l>end || r<start)
        return 0;
    if(l<=start && r>=end){
        return tree[node];
    }

    int mid=(start+end)/2;
    return max(findmax(2*node,start,mid,l,r),findmax(2*node+1,mid+1,end,l,r));
}
int main()
{
    ios::sync_with_stdio(false);
    //cin.tie(0);
    int arr[]={3,1,2,8};
    int n=4;
    pair<int,int> p[n];
    for(int i=0;i<n;i++)
    {
        p[i].first=arr[i];
        p[i].second=i;
    }
    sort(p,p+n,compare);
    memset(tree,0,sizeof(tree));
    cout<<"Tree init:\n";
    for(int i=1;i<8;i++)
        cout<<tree[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        build_tree(1,0,n-1,p[i].second,1+
                   findmax(1,0,n-1,0,p[i].second));
    cout<<"TreeFinal:\n";
    for(int i=1;i<8;i++)
        cout<<tree[i]<<" ";
    cout<<endl;
    cout<<"Ans:"<<tree[1]<<endl;
    return 0;
}
