
#include<bits/stdc++.h>
using namespace std;
#define mod 5
#define ull long long int
string str;
ull powmod(ull a,ull b)
{
    if(b==0)
        return 1;
    ull k=powmod(a,b/2)%mod;
    if(b%2==1)
        return ((((k%mod)*(k%mod))%mod)*a)%mod;
    else
        return ((k%mod)*(k%mod))%mod;
}
ull driver(ull x)
{
    ull ans=1,i;
    for(i=str.size()-1;i>=0;i--)
    {
        ans=(ans*powmod(x,str[i]-'0'))%mod;
        x=powmod(x,10);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>str;
    ull res;
    res=driver(1)+driver(2)+driver(3)+driver(4);
    res%=mod;
    cout<<res;
    return 0;
}
