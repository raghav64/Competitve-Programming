#include<iostream>
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
node* findmin(node*head)
{
    if(head==NULL)
        return NULL;
    else if(head->left==NULL)
        return head;
    else
        return findmin(head->left);
}
void deletion(node**root,int data)
{
    if(*root==NULL)
        return;
    else if(data<((*root)->data))
        deletion(&((*root)->left),data);
    else if(data>((*root)->data))
        deletion(&((*root)->right),data);
    else
    {
        if(((*root)->left==NULL) && ((*root)->right==NULL))
        {
            node*temp=*root;
            *root=NULL;
            delete temp;
        }
        else if((*root)->left==NULL)
        {
            node*temp=*root;
            *root=(*root)->right;
            delete temp;
        }
        else if((*root)->right==NULL)
        {
            node*temp=*root;
            *root=(*root)->left;
            delete temp;
        }
        else
        {
            node*temp=findmin((*root)->right);
            (*root)->data=temp->data;
            deletion(&((*root)->right),temp->data);
        }
    }
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
    ios::sync_with_stdio(false);
    node*head=NULL;
    int data;
    cout<<"Enter data terminated by -1"<<endl;
    cin>>data;
    while(data!=-1)
    {
        ins(&head,data);
        cin>>data;
    }
    inorder(head);
    cout<<endl;
    deletion(&head,20);
    inorder(head);
    cout<<endl;
    deletion(&head,30);
    inorder(head);
    cout<<endl;
    deletion(&head,50);
    inorder(head);
    cout<<endl;
    return 0;
}
