#include<iostream>
#include<stack>
#include<stdio.h>
#include<string.h>
using namespace std;
bool balanced(char arr[])
{
    stack<char>S;
    for(int i=0;i<strlen(arr);i++)
    {
        if(arr[i]=='{' || arr[i]=='(' || arr[i]=='[')
            {
                S.push(arr[i]);
            }
        else if(arr[i]=='}')
        {
            if(S.top()=='{')
                S.pop();
        }
        else if(arr[i]==')')
        {
            if(S.top()=='(')
                S.pop();
        }
        else if(arr[i]==']')
        {
            if(S.top()=='[')
                S.pop();
        }
    }
    if(S.empty())
        return true;
    return false;
}
int main()
{
    char arr[20];
    cout<<"Enter the expression with parentheses"<<endl;
    scanf("%s",arr);
    if(balanced(arr))
        cout<<"Expression is balanced"<<endl;
    else
        cout<<"Expression is not balanced"<<endl;
    return 0;
}
