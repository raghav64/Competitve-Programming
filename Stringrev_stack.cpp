#include<iostream>
#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
void Reverse(char [],int);
int main()
{
    char arr[20];
    cout<<"Enter the string"<<endl;
    //scanf("%s",arr);
    gets(arr);
    //cout<<arr;
    Reverse(arr,strlen(arr));
    cout<<arr<<endl;
    return 0;
}

void Reverse(char arr[20],int n)
{
    stack<char>S;
    for(int i=0;i<n;i++)
    {
        S.push(arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=S.top();
        S.pop();
    }
    return;
}
