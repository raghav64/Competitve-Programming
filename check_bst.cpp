#include<iostream>
#include<limits.h>
using namespace std;
bool bst;
int val;
struct node
{
    int data;
    node*left;
    node*right;
};
node* newnode(int data)
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
        *head=newnode(data);
    else if(data<((*head)->data))
        ins(&((*head)->left),data);
    else
        ins(&((*head)->right),data);
}
void inorder(node*head)
{
    if(head==NULL)
        return;
    inorder(head->left);
    cout<<head->data<<" ";
    inorder(head->right);
}
void check_bst(node*head)
{
    if(head==NULL)
        return;
    check_bst(head->left);
    if(head->data > val)
        val=head->data;
    else{
        bst=false;
        return;
    }
    check_bst(head->right);
}
int main()
{
    //node*head=NULL;
    int data;
    //NOTE:This insertion by ins function inserts only as bst hence any type of data inserted will
    // be organised into bst on its own
    /*cout<<"Enter data terminated by -1"<<endl;
    cin>>data;
    while(data!=-1)
    {
        ins(&head,data);
        cin>>data;
    }*/
    //inorder(head);
    //For checking the check function try this:
    node*head=newnode(5);
    head->left=newnode(3);
    head->right=newnode(6);
    head->left->left=newnode(1);
    head->left->right=newnode(8);
    inorder(head);
    bst=true;
    val=INT_MIN;
    check_bst(head);
    if(bst)
        cout<<"Given tree is bst"<<endl;
    else
        cout<<"Given tree is not bst"<<endl;
    return 0;
}
