/*
Q: You have an array Arr of N numbers ranging from 0 to 99. 
Also you have Q queries [L, R]. For each such query you must print 
V([L, R]) = ∑i=0..99 count(i)^2 * i 
where count(i) is the number of times i occurs in Arr[L..R].
*/
#include<bits/stdc++.h>
using namespace std;
#define ull long long int
#define mod 1000000007
#define INF 100000000000014
pair<pair<int,int> ,int >queries[100005];
int arr[100005];
int block_size;
int cnt[102],ans;
int answers[100005];
bool mo_cmp(const pair< pair<int, int>, int> &x,
            const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first/block_size;
    int block_y = y.first.first/block_size;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}
void add(int x)
{
    ans-= cnt[x]*cnt[x]*x;
    cnt[x]++;
    ans+= cnt[x]*cnt[x]*x;
}
void remove(int x)
{
    ans-= cnt[x]*cnt[x]*x;
    cnt[x]--;
    ans+= cnt[x]*cnt[x]*x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q,i,l,r;
    cin>>n>>q;
    block_size=sqrt(n);
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<q;i++)
    {
        cin>>l>>r;
        queries[i]=make_pair(make_pair(l,r),i);
    }
    sort(queries,queries+q,mo_cmp);
    int mo_left=0,mo_right=-1;
    ans=0;
    for(i=0;i<q;i++)
    {
        int left=queries[i].first.first;
        int right=queries[i].first.second;

        /* This is optional optimisation
        //optimisation if block changes
        if(i==0 or mo_left/block_size != left/block_size)
        {
            memset(cnt,0,sizeof(cnt));
            ans=0;
            for(ull j=left;j<=right;j++)
                add(arr[j]);

            mo_left=left;
            mo_right=right;
        }
        else
        {*/
            while(mo_right<right)
            {
                mo_right++;
                add(arr[mo_right]);
            }
            while(mo_right>right)
            {
                remove(arr[mo_right]);
                mo_right--;
            }
            while(mo_left<left)
            {
                remove(arr[mo_left]);
                mo_left++;
            }
            while(mo_left>left)
            {
                mo_left--;
                add(arr[mo_left]);
            }
        //}
        answers[queries[i].second]=ans;
    }
    for(i=0;i<q;i++)
        cout<<answers[i]<<"\n";
    return 0;
}
