#include<bits/stdc++.h>
using namespace std;
#define ull long long int
#define mod 1000000007
#define INF 100000000000014
struct node{
    node* children[2];
    bool isleaf;
    int val;
    node()
    {
        isleaf=false;
        val=0;
        for(int i=0;i<2;i++)
            children[i]=NULL;
    }
};
int arr[100005];
void insert(node**head,int num)
{
    int i;
    bool k;
    node*temp=*head;
    for(i=31;i>=0;i--)
    {
        k=((num)&(1<<i));
        if(temp->children[k]==NULL)
            temp->children[k]=new node();
        temp=temp->children[k];
    }
    temp->isleaf=true;
    temp->val=num;
}
int query(node*head,int x)
{
    int i;
    bool k;
    node*temp=head;
    for(i=31;i>=0;i--)
    {
        k=((x)&(1<<i));
        if(temp->children[1-k]!=NULL)
            temp=temp->children[1-k];
        else if(temp->children[k]!=NULL)
            temp=temp->children[k];
    }
    return ((x)^(temp->val));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,i,ans=-1,pre;
    cin>>n;
    node*head=new node();
    pre=0;//Note: we have to insert 0 in trie too
    for(i=0;i<n;i++){
        cin>>arr[i];
        insert(&head,pre);
        pre=pre^arr[i];
        ans=max(ans,query(head,pre));
    }
    cout<<ans<<"\n";
    return 0;
}