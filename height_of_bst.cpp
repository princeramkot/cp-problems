#include <iostream>
#include<bits/stdc++.h>

#include <algorithm>
#define lli long long int
#define li long int
#define ld long double
#define ll long long 
using namespace std;

class treee
{
	int val;
	treee *left;
	treee *right;
	public:
	treee()
	{
		val=0;
		left=right=NULL;
	}
	treee(int v){
		val=v;
		left=right=NULL;
		
		}

	treee *insert(treee *root,int value)
	{
		if(root==NULL)
		{
		return new treee(value);
		}
		
		if(value>root->val)
		{
			root->right=insert(root->right,value);
		}
		else
		root->left=insert(root->left,value);
		return root;
	}
	
	
	void inorder(treee *root)
	{   if(!root) 
    { 
        return; 
    } 
    inorder(root->left); 
    cout << root->val << endl; 
    inorder(root->right); 
		
	}
	int height(treee *root)
	{
		queue<treee *> q;
		int height=0;
		q.push(root);
		while(1)
		{
			int nodecount=q.size();
			
			if(nodecount==0)
			return height;
			height++;
			while(nodecount>0)
			{
				treee *node=q.front();
				q.pop();
				if(node->left!=NULL)
				q.push(node->left);
				if(node->right!=NULL)
				q.push(node->right);
				nodecount--;
			}
			
			
		}
		
	}
	
};

int main()
{ 
 treee b, *root=NULL;
 
int n;cin>>n;
int input;
for(int i=0;i<n;i++)
{cin>>input;
	if(i==0)
	root=b.insert(root,input);
	else
	b.insert(root,input);
}
//b.inorder(root);
cout<<b.height(root)<<endl;
    return 0;
}
