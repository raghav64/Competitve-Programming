//Max Heap
#include<bits/stdc++.h>
using namespace std;
int arr[100],n;
void heapify(int i,int n)
{
    int left,right,largest;
    left=2*i;
    right=2*i+1;
    largest=i;
    if(left<=n && arr[left]>arr[largest])
        largest=left;
    if(right<=n && arr[right]>arr[largest])
        largest=right;
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(largest,n);
    }
    return;
}
void build_heap(int n)
{
    for(int i=n/2;i>0;i--)
        heapify(i,n);
}
int main()
{
    ios::sync_with_stdio(false);
    int i,n;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>arr[i];
    build_heap(n);
    int sizee=n;
    while(sizee>0)
    {
        cout<<arr[1]<<" ";
        arr[1]=INT_MIN;
        heapify(1,sizee);
        sizee--;
    }
    return 0;
}
