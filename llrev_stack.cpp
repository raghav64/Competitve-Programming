#include<iostream>
#include<stack>
using namespace std;
struct node
{
    int data;
    node*next;
};

void llinsert(node**head, int n)
{
    node*temp=new node;
    temp->data=n;
    temp->next=*head;
    *head=temp;
    return;
}

void Reversal(node*head)
{
    stack<node*>S;
    node*temp=head;
    while(temp!=NULL)
    {
        S.push(temp);
        temp=temp->next;
    }
    cout<<"LL after Reversal is:"<<endl;
    while(!S.empty())
    {
        cout<<(S.top())->data<<" ";
        S.pop();
    }
    return;
}

int main()
{
    node*head=NULL;
    int n;
    cout<<"Enter data to be terminated by -1"<<endl;
    cin>>n;
    // Inserts new element at beginning only
    while(n!=-1)
    {
        llinsert(&head,n);
        cin>>n;
    }
    node*start=head;
    cout<<"Original ll:"<<endl;
    while(start!=NULL)
    {
        cout<<start->data<<" ";
        start=start->next;
    }
    cout<<endl;
    Reversal(head);
    return 0;
}
