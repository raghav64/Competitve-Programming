#include<iostream>
#include<string>
#include<math.h>
using namespace std;
#define ull long long int
#define mod 3
string seg[200000]={""};
string str;
void build_seg(ull node,ull start,ull end)
{
    if(start>end)
        return;
    if(start==end){
        seg[node]=str[start];
        return;
    }
    ull mid=(start+end)/2;
    build_seg(2*node,start,mid);
    build_seg(2*node+1,mid+1,end);
    seg[node]=seg[2*node]+seg[2*node+1];
}
void update_node(ull node,ull start,ull end,ull idx)
{
    if(start==end)
    {
        if(str[idx]=='0'){
            str[idx]='1';
            seg[node]='1';
        }
    }
    else
    {
        ull mid=(start+end)/2;
        if(start<=idx && idx<=mid)
            update_node(2*node,start,mid,idx);
        else
            update_node(2*node+1,mid+1,end,idx);
        seg[node]=seg[2*node]+seg[2*node+1];
    }
}
string query(ull node,ull start,ull end,ull l,ull r)
{
    if(l>end || r<start)
        return "";
    if(l<=start && r>=end)
        return seg[node];

     ull mid= (start+end)/2;
     string str1=query(2*node,start,mid,l,r);
     string str2=query(2*node+1,mid+1,end,l,r);
     return (str1+str2);
}
ull power(ull b,ull p)
{
 ull ans=1;
 b=b%3;
 while(p>0){
    if(p%2==1)
    {
        ans=(ans*b)%3;
    }
    p=p>>1;
    b=(b*b)%3;
 }
 return ans%3;
}
ull convert(string str)
{
    ull ans=0,n,i=0;
    n=str.length()-1;
    while(i<=n)
    {
        ans+=(power(2,i)*(str[n-i]-'0'));
        //ans%=mod;
        i++;
    }
    return ans%mod;
}
int main()
{
    ios::sync_with_stdio(false);
    ull n,q,l,r,k,idx;
    cin>>n>>str>>q;
    build_seg(1,0,n-1);
    while(q--)
    {
        cin>>k;
        if(k==0){
                cin>>l>>r;
            cout<<convert(query(1,0,n-1,l,r))<<"\n";
        }
        else{
                cin>>idx;
            update_node(1,0,n-1,idx);
        }
    }
    return 0;
}
