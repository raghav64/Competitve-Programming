#include<iostream>
using namespace std;
#define ull long long int
#define LIM 5000006
ull sp[LIM],pf[LIM];
int main()
{
    ios::sync_with_stdio(false);
    ull t,a,b,i,n,j;
    for(i=2;i<LIM;i+=2)
        sp[i]=2;
    for(i=3;i<LIM;i+=2)
    {
        if(sp[i]==0)
        {
            sp[i]=i;
            for(j=i;j*i<LIM;j++)
                if(sp[j*i]==0)
                    sp[j*i]=i;
        }
    }
    pf[1]=0;
    for(i=2;i<LIM;i++)
        pf[i]=1+pf[i/sp[i]];
    return 0;
}

