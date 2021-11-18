//This code will print out all indices of occurences of string t in string s in nlogn time
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <string.h>
#include <limits.h>
#include <cmath>
using namespace std;
#define ull long long int
#define mod 1000000007
#define INF 100000000000014

int stringCompare(string a, string b){


    // int l = min(a.length(), b.length());
    // a = a.substr(0,l);
    // b = b.substr(0,l);

    int l = a.length();

    // it is redundant to compare for lengths greater than pattern length
    if(b.length()>l)
        b = b.substr(0,l);

    const char *p = a.c_str();
    const char *q = b.c_str();
    return strcmp(p,q);
}

int main()
{
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);
    
    string s,t;

    int suffix[1003],i;
    map<string, int> mymap;
    map<string, int>:: iterator it;
    map<int, string> revmap;

    cin>>s>>t;

    string temp = "";
    for(i=s.length()-1;i>=0;i--){
        temp = s[i] + temp;
        mymap[temp] = i;
        revmap[i] = temp;
    }
    
    i=0;

    for(it=mymap.begin();it!=mymap.end();it++){
        suffix[i] = it->second;
        i++;
    }

    vector<int> comparisons,ans;

    for(i=0;i<s.length();i++){
        comparisons.push_back(stringCompare(t, revmap[suffix[i]]));
    }

    for(i=0;i<s.length();i++){
        if(comparisons[i] == 0)
            ans.push_back(suffix[i]);
    }
    sort(ans.begin(), ans.end());
    for(i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<"\n";

    return 0;
}

