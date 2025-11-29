#include<bits/stdc++.h>
using namespace std;
class Node{
	public: 
	int data;
	Node *left, *right;
	Node(int key){
		data=key;
		left=right=nullptr;
	}
};
//Node *buildTree(){
//	int val;
//	cin>>val;
//	if(val==-1) return nullptr;
//	Node *newNode=new Node(val);
//	cout<<"enter left child of "<<newNode->data<<": ";
//	newNode->left=buildTree();
//	cout<<"enter right child of "<<newNode->data<<": ";
//	newNode->right=buildTree();
//	return newNode;
//}
//void preorder(Node *root){
//	if(!root) return;
//	cout<<root->data<<" ";
//	preorder(root->left);
//	preorder(root->right);
//}
vector<int>levelOrder(Node *root){
	queue<Node *>q;
	q.push(root);
	vector<int>ans;
	while(!q.empty()){
		Node *temp=q.front();
		q.pop();
		ans.push_back(temp->data);
		if(temp->left){
			q.push(temp->left);
		}
		if(temp->right){
			q.push(temp->right);
		}
	}
	return ans;
}
int totalNode(Node *root){
	if(root==NULL) return 0;
	return 1+(totalNode(root->left)+totalNode(root->right));
}
int totalSum(Node *root){
	if(root==NULL) return 0;
	return root->data+(totalSum(root->left)+totalSum(root->right));
}
int main(){
//	cout<<"enter root: ";
//	Node *root=buildTree();
//	cout<<"\nPreorder is: ";
//	preorder(root);

	int x, y;
	cout<<"enter root: ";
	cin>>x;
	queue<Node *>q;
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
	vector<int>res=levelOrder(root);
	cout<<"\nLevel order traversal is: ";
	for(auto &val: res){
		cout<<val<<" ";
	}
	cout<<"\nTotal Node are: "<<totalNode(root);
	cout<<"\nTotal Node's Sum is: "<<totalSum(root);
	return 0;
}
