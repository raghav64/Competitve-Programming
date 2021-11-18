// In trie the head is a empty string
#include<bits/stdc++.h>
using namespace std;
struct node
{
	node* children[26];
	bool isleaf;
	node() 
	{ 
		isleaf = false ;
		for(int i = 0 ; i < 26 ; i ++ )
			children[i] = NULL;
    }
};

void insert(node** head, string& data)
{
	node* temp = *head;
	int k;
    for(int i=0;i<data.length();i++)
    {
    	k=data[i]-'a';
    	if(temp->children[k]==NULL)
    	{
    		temp->children[k]=new node();
    	}
    	temp=temp->children[k];
    }
    temp->isleaf=true;
}
bool search(node*head,string& data)
{
	node* temp=head;
	int k;
	for(int i=0;i<data.length();i++)
	{
		k=data[i]-'a';
		
		if(temp->children[k]!=NULL)
			temp=temp->children[k];

		else
			return false;
	}
	if(temp!=NULL && temp->isleaf)
		return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	string s1="chu";
	string s2="chutti";
	string str = "chuti";

	node* head = new node();
	
	insert(&head,s1);
	insert(&head,s2);
	if(search(head,str))
		cout<<"found";
	else
		cout<<"not found";
return 0;
}