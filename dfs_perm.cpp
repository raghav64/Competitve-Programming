#include<iostream>
#include<string>
#include<string.h>
using namespace std;
void generateperms(string str, char arr[], int level, bool visit[])
{
    int n=str.length();
    if(level>=n-1){
        cout<<arr<<"\n";
        return;
    }
    for(int i=0;i<str.length();i++)
    {
        if(!visit[i])
        {
            arr[++level]=str[i];
            visit[i]=true;
            generateperms(str,arr,level,visit);
            visit[i]=false;
            level--;
        }
    }
    return;
}
int main()
{
    string str="ABCD";
    bool visit[str.length()+1];
    char arr[]="";
    memset(visit,false,sizeof(visit));
    generateperms(str,arr,-1,visit);
    return 0;
}
