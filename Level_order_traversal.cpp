#include<iostream>
#include<queue>
using namespace std;
struct node
{
    node*left;
    node*right;
    int data;
};
node* create(int data)
{
    node*temp=new node;
    temp->left=NULL;
    temp->right=NULL;
    temp->data=data;
    return temp;
}
void ins(node**head,int data)
{
    if(*head==NULL)
        *head=create(data);
    else if(data<((*head)->data))
        ins(&((*head)->left),data);
    else
        ins(&((*head)->right),data);
}
void levelorder(node*head)
{
    queue<node*>q;
    if(head==NULL)
        return;
    q.push(head);
    while(!(q.empty()))
    {
        node*current=q.front();
        if((current->left)!=NULL)q.push(current->left);
        if((current->right)!=NULL)q.push(current->right);
        cout<<(current)->data<<" ";
        q.pop();
    }
    return;
}
int main()
{
    node*head=NULL;
    int data;
    cout<<"Enter data terminated by -1"<<endl;
    cin>>data;
    while(data!=-1)
    {
        ins(&head,data);
        cin>>data;
    }
    cout<<"Level order print of tree="<<endl;
    levelorder(head);
    return 0;
}
