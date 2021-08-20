#include <iostream>

using namespace std;

class Node{
public:
	int data;
	Node *left,*right;
};

Node *newnode(int a){
	Node *t=new Node();
	t->data=a;
	t->left=t->right=NULL;
	return t;
}

void Create(int a,Node *root)
{
	if(root->data > a)
	{
		if(root->left!=NULL)
			Create(a,root->left);
		else
			root->left=newnode(a);
	}
	else
	{
		if(root->right!=NULL)
			Create(a,root->right);
		else
			root->right=newnode(a);
	}
}

void in(Node *root)
{
	if(root)
	{
		in(root->left);
		cout << root->data << " ";
		in(root->right);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(0); 
	cin.tie(0);
	int n;	cin >> n;
	Node *root=NULL;
	for(int i=0; i < n ; ++i){
		int a;	cin >> a;
		if(root==NULL)
			root=newnode(a);
		else	
			Create(a,root);
	}
	in(root);
	return 0;
}