#include<iostream>
using namespace std;
int arr[20];
int size_tree[20];
int root(int i)
{
    while(arr[i]!=i)
        {
            arr[i]=arr[arr[i]];//This line is useful for compression as it updates the root of arr[i] to its
            i=arr[i];          //grandparent so next time lookup gives answer in O(1).This makes order=inverse ackerman function
                               //which is nearly constant.
        }
    return i;
}
bool found_link(int a, int b)
{
    if(root(a)==root(b))
        return true;
    return false;
}
void union_nodes(int a,int b)
{
    int root_a=root(a);
    int root_b=root(b);
    if(size_tree[root_a]>size_tree[root_b])
    {
        arr[root_b]=arr[root_a];//arr[root_b]=root_a  as root_a=arr[root_a];
        size_tree[root_a]+=size_tree[root_b];
    }
    else
        arr[root_a]=arr[root_b];
        size_tree[root_b]+=size_tree[root_a];
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    int i,n;
    cout<<"Enter the number of elements\n";
    cin>>n;
    for(i=0;i<n;i++)
    {
        arr[i]=i;
        size_tree[i]=1;
    }
    return 0;
}
