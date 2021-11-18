//Depth of a node=No. of edges from root to that node
//Height of a node=No. of edges in longest path from that node to a leaf node
//Binary tree=Tree having at most 2 nodes for each node
//Strictly binary=Having 2 or 0 children
//Max no of nodes at level i= 2^i
//perfect binary=each node has 2 nodes except leaves and all leaves are at same level
//height of complete binary tree=floor(log2(n)) where n is no of nodes
//min height of tree is floor(log2(n)) for complete binary tree and max height= n-1 for sparse tree
//For array implementation of complete binary tree the node at index i has:
// left child at 2i+1 index and right child at 2i+2 index provided i filled as level wise
//For BST the insert,search,remove operation has complexity of O(log2(n)) provided balanced
//BST: for BST value of all nodes in left subtree is lesser than the node and
//value of all nodes in right subtree is greater or equal than node
//Inorder successor of a node is min of right subtree
//Inorder predecessor of a node is max of left subtree
// IMPLEMENTING BST
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
bool found(node*head,int key)
{
    if(head==NULL)
        return false;
    else if(head->data==key)
        return true;
    else if(key<(head->data))
        return found(head->left,key);
    else if(key>(head->data))
        return found(head->right,key);
}
int findmin(node*head)
{
    if(head==NULL)
    {
        cout<<"Error"<<endl;
        return 0;
    }
    else if(head->left==NULL)
        return head->data;
    else
        return findmin(head->left);
}
int height (node*head)
{
    if(head==NULL)
        return -1;
    int h=1+max(height(head->left),height(head->right));
    return h;
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
    cout<<"Enter key"<<endl;
    cin>>key;
    if(found(root,key))
        cout<<"Found"<<endl;
    else
        cout<<"Not found"<<endl;
    cout<<"Min element="<<findmin(root)<<endl;
    cout<<"Height of tree="<<height(root)<<endl;
    return 0;
}
