//Implementing SegTree for sum over range
#include<iostream>
using namespace std;
int seg[200000];
int n;
//To build a segment tree from 1 to n-1 using values from n to 2n-1
void build()
{
    //seg tree starts from index 1
    for(int i= n-1;i>0;i--)
        seg[i]=seg[i<<1]+seg[(i<<1)+1];//seg[i]=seg[2*i]+seg[2*i+1];
}
//To modify the value of the array and hence resulting in updation of each node
void modify(int position, int value)
{
    seg[position+=n]=value;//As original array starts from index n
    //Now update every parent related to the node
    for(;position>=1;position>>=1)
        seg[position>>1]=seg[position]+seg[position^1];//seg[pos/2]=seg[pos]+seg[pos+1] or vice-versa as xor gives pos or pos+1
}
//Answers the query of sum of given range[l,r) :: r is excluded but r+1 is passed in main
int query(int l,int r)
{
    int ans =0;
    l+=n;
    r+=n;
//Now we will include the left child if it's odd else nothing and
//right's even sibling if right is odd else nothing
    for(;l<r;l>>=1,r>>=1)
    {
        if(l&1)
        {
            ans+=seg[l];
            l++;//Making l even for l/2 to be correct
            //Also excludes it's parent as the range will be left than expected
        }
        if(r&1)
        {
            r--;
            //Including it's even sibling and checking for right parent
            ans+=seg[r];

        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int i,l,r;
    cout<<"Enter size\n";
    cin>>n;
    //Size of segment tree= twice the size of elements entered
    cout<<"Enter the array to be operated\n";
    for(i=0;i<n;i++)
        cin>>seg[n+i];
    build();//O(n)
    cout<<"Enter query range assuming 0 based indexing\n";
    cin>>l>>r;
    cout<<"Sum of given range="<<query(l,r+1)<<endl;//O(log(n))
    return 0;
}
