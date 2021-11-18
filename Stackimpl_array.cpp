#include<iostream>
using namespace std;
#define MAX_SIZE 10
int top=-1;
int a[MAX_SIZE];

void push(int x)
{
    top=top+1;
    if(top==MAX_SIZE)
    {
        cout<<"Stack overflow"<<endl;
        return;
    }
    a[top]=x;
    return ;
}
void pop()
{
    if(top==-1){
        cout<<"Underflow"<<endl;
        return;
    }
    top--;
    return;
}

void Top()
{
    cout<<"Top="<<a[top]<<endl;
    return;
}

int main()
{
    push(2);
    push(5);
    push(7);
    push(9);
    Top();
    pop();
    pop();
    Top();
    return 0;
}
