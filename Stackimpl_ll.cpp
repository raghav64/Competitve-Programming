//Implementation from ll inserts and deletes at beginning
#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
node*top=NULL;

void push(int x)
{
    node*temp=new node;
    temp->data=x;
    temp->next=top;
    top=temp;
    return;
}

void pop()
{
    node*temp=top;
    if(temp==NULL)
    {
        cout<<"Nothing to pop"<<endl;
        return;
    }
    top=top->next;
    delete temp;
    return;
}

void Top()
{
    if(top==NULL)
        {
            cout<<"Nothing to show"<<endl;
            return;
        }
    cout<<"Top="<<top->data<<endl;
    return;
}

int main()
{
    //push(2);
    //push(5);
    /*Top();
    push(6);
    push(9);*/
    Top();
    pop();
    //pop();
    Top();
    return 0;
}
