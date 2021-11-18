#include<iostream>
using namespace std;
struct node
{
    int data;
    node*left;
    node*right;
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
node* findmin(node*head)
{
    if(head==NULL)
        return NULL;
    else if(head->left==NULL)
        return head;
    else
        return findmin(head->left);
}
node*searchop(node*head,int key)
{
    if(head==NULL)
        return NULL;
    if(key<(head->data))
        return searchop(head->left,key);
    else if(key>(head->data))
        return searchop(head->right,key);
    else
        return head;
}
node* successor(node*head,int data)
{
    node*temp=searchop(head,data);
    if(temp->right!=NULL)
        return findmin(head->right);
    while(head!=NULL)
    {
        if(data<(head->data))
        {
            temp=head;
            head=head->left;
        }
        else if(data>(head->data))
            head=head->right;
        else break;
    }
    return temp;
}
void inorder(node*head)
{
    if(head==NULL)
        return;
    inorder(head->left);
    cout<<head->data<<" ";
    inorder(head->right);
}
int main()
{
    node*root=NULL;
    int data,key;
    cout<<"Enter data terminated by -1"<<endl;
    cin>>data;
    while(data!=-1)
    {
        ins(&root,data);
        cin>>data;
    }
    inorder(root);
    cout<<endl;
    cout<<successor(root,5)->data<<endl;
    return 0;
}
