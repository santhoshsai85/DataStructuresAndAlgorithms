	#include<iostream>
#include <vector>
#include<set>
#include<algorithm>
#include<deque>
#include<stack>
#include<queue>
#include<iterator>

using namespace std;

class Node{
public:
	int data;
	Node *left;
	Node *right;
};

void printa(int arr[],int n);


Node* newNode(int data) 
{ 
    Node* node = new Node(); 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
}


// Input is given as array:
/*Node *insertorder(int a[],Node *root ,int i,int n)
{
	if(i < n)
	{
		Node *temp=newNode(a[i]);
		root=temp;
		root->left = insertorder(a, root->left, 2 * i + 1, n);
        root->right = insertorder(a,root->right, 2 * i + 2, n); 
	}
	return root;
}*/
static int m=0;
vector<int > v;


void printall(Node * root , int path[],int l)
{
	if(!root)
	{
		return;
	}
	path[l++]=root->data;
	if(root->left==NULL and root->right==NULL){
		printa(path,l);
		if( l > m){
			v.clear();
			for(int i = 0 ; i < l ; ++i){
				v.push_back(path[i]);
			}
			m=l;
		}
	}
	printall(root->left,path,l);
	printall(root->right,path,l);
}

void printa(int arr[],int n)
{
	for(int i=0; i < n ; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}


//Creating just adding children nodes:
void insertorder(Node *temp ,int key)
{
	queue<Node *> q;
	if(temp == NULL)
		temp=newNode(key);
	q.push(temp);
	while(!q.empty())
	{
		Node *temp=q.front();
		q.pop();
		if(temp->left==NULL){
			temp->left=newNode(key);
			break;
		}
		else
			q.push(temp->left);
		if(temp->right==NULL){
			temp->right=newNode(key);
			break;
		}
		else
			q.push(temp->right);
	}
}

void deletion(Node *root,Node *leaf)
{
	queue<Node *> q;
	q.push(root);
	while(!q.empty())
	{
		Node *t=q.front();
		q.pop();
		if(t->left==leaf)
		{
			t->left=NULL;
			delete(leaf);
			return;
		}
		else
			q.push(t->left);
		if(t->right==leaf)
		{
			t->right=NULL;
			delete(leaf);
			return;
		}
		else
			q.push(t->right);
	}

}

Node* deletenode(Node *root, int key)
{
	if(root==NULL){
		return NULL;
	}
	queue<Node *> q;
	q.push(root);
	Node *dn=NULL;
	Node *t;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t->data==key)
			dn=t;
		if(t->left)
			q.push(t->left);
		if(t->right)
			q.push(t->right);
	}
	if(dn==NULL)
		return root;
	else
	{
		if(t!=dn)
		{
			int t1=t->data;
			deletion(root,t);
			dn->data=t1;
		}
		else
			deletion(root,t);
	}
	return root;
}


//Printing level by level
void print(Node *root)
{
	queue<Node *> q;
	q.push(root);
	int i;
		while(!q.empty())
		{
			i=q.size();
			while(i!=0)
			{	
				Node *temp=q.front();
				cout << temp->data << " ";
				q.pop();
				if(temp->left!=NULL)
					q.push(temp->left);
				if(temp->right!=NULL)
					q.push(temp->right);
				i--;
			}
			cout << "\n";
		}
}


void iR(Node *root)
{
	stack<Node *> s;
	Node *cur=root;
	while(cur!=NULL or s.empty()==false){
		while(cur!=NULL){
			s.push(cur);
			cur=cur->left;
		}
		cur=s.top();
		s.pop();
		cout << cur->data <<" " ;
		cur=cur->right;
	}
}




int main() 
{ 
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	/*int t; 
	cin >> t; */
	Node *root=NULL;
	// while (t--) { 
		int n; 
		cin >> n;
		int a[n];
		for(int i=0; i < n; i++){
			cin >> a[i];
			if(root == NULL)
			    root=newNode(a[i]);
			else
			    insertorder(root,a[i]);
		}
		int path[1000];
		printall(root,path,0);
		cout << "The max pathlen is "<< m<< "\n";
		vector<int > :: iterator it;
		for(it=v.begin() ; it!=v.end() ; it++)
			cout << *it << " ";
		// root=insertorder(a,root,0,node);
		// int a; cin >> a;
		// print(root);
		// deletenode(root,3);
		// print(root);
		// iR(root);

	// } 
	return 0; 
} 
