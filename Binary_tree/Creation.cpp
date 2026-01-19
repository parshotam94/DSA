#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node *left=nullptr, *right=nullptr;
	Node(int data){
		this->data=data;
		this->left=nullptr;
		this->right=nullptr;
	}
};
//1st approach Level Order
Node *levelOrderCreation(){
	int x, y;
	cin>>x;
	queue<Node*>q;
	Node *root=new Node(x);
	q.push(root);
	while(!q.empty()){
		Node *temp=q.front();
		q.pop();
		cout<<"enter left child of "<<temp->data<<": ";
		cin>>x;
		if(x!=-1){
			temp->left=new Node(x);
			q.push(temp->left);
		}
		cout<<"enter right child of "<<temp->data<<": ";
		cin>>y;
		if(y!=-1){
			temp->right=new Node(y);
			q.push(temp->right);
		}
	}
	return root;
}
void inorder(Node *root){
	if(!root) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void preorder(Node *root){
	if(!root) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(Node *root){
	if(!root) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
int main(){

	cout<<"enter root: ";
	Node *root=levelOrderCreation();
	cout<<"\nTree Created Successfully...\n";
	cout<<"\nInorder-> ";
	inorder(root);
	cout<<"\nPreorder-> ";
	preorder(root);
	cout<<"\nPostorder-> ";
	postorder(root);
	return 0;
}
