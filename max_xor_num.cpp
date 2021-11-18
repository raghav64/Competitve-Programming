//Q: Given an array with 10^5 size and 10^5 queries having a number. Find the max
// xor element in array s.t xor of those 2 nums is max.

//A: O(nq) wont work.So we build a trie and answer queries in O(q*log(max_ele)) 
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
        else
            temp=temp->children[k];
    }
    return ((x)^(temp->val));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,i,q,k;
    cin>>n>>q;
    node*head=new node();
    for(i=0;i<n;i++){
        cin>>arr[i];
        insert(&head,arr[i]);
    }
    while(q--)
    {
        cin>>k;
        cout<<query(head,k)<<"\n";
    }
    return 0;
}