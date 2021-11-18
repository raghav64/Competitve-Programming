#include<bits/stdc++.h>
using namespace std;
vector<int>vec;
int k=3,sizee=10;
deque<int>deq;
void printmax()
{
    int cur=vec.size()-1;
    while(!deq.empty() && deq.front()<=cur-k)
        deq.pop_front();
    while(!deq.empty() && vec[cur]>=vec[deq.back()])
        deq.pop_back();
    deq.push_back(cur);
    cout<<vec[deq.front()]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p,i;
    vec.push_back(1);
    vec.push_back(-2);
    vec.push_back(5);
    //initialize first k elements in dequeue
    for(i=0;i<3;i++)
    {
        while((!deq.empty()) && vec[i]>=vec[deq.back()])
            deq.pop_back();

        deq.push_back(i);
    }
    cout<<vec[deq.front()]<<endl;
    for(i=3;i<10;i++)
    {
        cin>>p;
        vec.push_back(p);
        printmax();
    }
    return 0;
}
