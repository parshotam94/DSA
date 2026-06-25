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
//count leaves in Btree
void countLeaves(Node *root, int &cnt){
	if(!root) return;
	if(!root->left && !root->right){
		cnt++;
	}
	if(root->left) countLeaves(root->left, cnt);
	if(root->right) countLeaves(root->right, cnt);
}
int main(){
	cout<<"enter root: ";
	Node *root=binaryTree(root);
	cout<<"\nTree Created Successfully...\n";
	cout<<"\nLevelOrder-> ";
	levelorder(root);
	int cnt=0;
	countLeaves(root, cnt);
	cout<<"\nTotal leaves of Binary tree are: "<<cnt;
	return 0;
}
