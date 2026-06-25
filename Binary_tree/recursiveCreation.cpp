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
//recursive approach
Node *binaryTree(Node *root){
	int val;
	cin>>val;
	if(val==-1) return nullptr;
	Node *new_node=new Node(val);
	cout<<"enter left child of "<<val<<": ";
	new_node->left=binaryTree(new_node->left);
	cout<<"enter right child of: "<<val<<": ";
	new_node->right=binaryTree(new_node->right);
	return new_node;
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
	Node *root=binaryTree(root);
	cout<<"\nTree Created Successfully...\n";
	cout<<"\nInorder-> ";
	inorder(root);
	cout<<"\nPreorder-> ";
	preorder(root);
	cout<<"\nPostorder-> ";
	postorder(root);
	return 0;
}
