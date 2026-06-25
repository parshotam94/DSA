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

//levelOrderTraversal
void levelorder(Node *root){
	queue<Node *>q;
	q.push(root);
	while(!q.empty()){
		Node *temp=q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
	}
}
int sizeOfTree(Node *root){
	if(!root) return 0;
	return 1+sizeOfTree(root->left)+sizeOfTree(root->right);
}
int main(){
	cout<<"enter root: ";
	Node *root=binaryTree(root);
	cout<<"\nTree Created Successfully...\n";
	cout<<"\nLevelOrder-> ";
	levelorder(root);
	cout<<"\nSize of Binary tree is: "<<sizeOfTree(root);
	return 0;
}
