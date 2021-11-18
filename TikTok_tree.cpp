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

vector<vector<int> >graph;
bool visit[30];
bool treePart[30];
int indegree[30];
bool isCyclic = false;

void cycleDFS(int x){
    visit[x] = true;
    for(int i=0;i<graph[x].size();i++){

        if(!visit[graph[x][i]])
            cycleDFS(graph[x][i]);

        else{
            isCyclic = true;
            return;
        }
    }
}

string constructExpression(int x){

    if(graph[x].size()==0){
        string ans = "(";
        ans += char(x+'A');
        ans += ")";
        return ans;
    }

    sort(graph[x].begin(), graph[x].end());
    
    string str = "";
    str += "(";
    str += char(x+'A');

    for(int i=0;i<graph[x].size();i++){
        str+=constructExpression(graph[x][i]);
    }
    str+=")";
    return str;
}

int main()
{
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    string str;
    getline(cin,str);

    graph.resize(30);
    memset(treePart, false, sizeof(treePart));
    memset(indegree, 0, sizeof(indegree));

    bool E2 = false;

    for(int i=1;i<str.length();i+=6){
        int a = str[i]-'A';
        int b = str[i+2]-'A';

        treePart[a] = true;
        treePart[b] = true;
        
        if(find(graph[a].begin(), graph[a].end(), b) != graph[a].end())
            E2 = true;

        else{
            graph[a].push_back(b);
            indegree[b]++;
        }

        if(graph[a].size()>2){
            cout<<"E1";
            return 0;
        }
    }
    if(E2){
        cout<<"E2";
        return 0;
    }

    // Check for E4
    int cntRoot = 0;
    int root;
    for(int i=0;i<26;i++){
        if(treePart[i] and indegree[i] == 0){
            cntRoot++;
            root = i;
        }
    }
    if(cntRoot == 0){
        cout<<"E5";
        return 0;
    }
    if(cntRoot>1){
        cout<<"E4";
        return 0;
    }

    // Check for cycle using DFS
    memset(visit,false,sizeof(visit));
    cycleDFS(root);

    if(isCyclic){
        cout<<"E3";
        return 0;
    }

    cout<<constructExpression(root);

    return 0;
}

