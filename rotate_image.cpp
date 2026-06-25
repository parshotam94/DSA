#include<bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>>&mat){
	//transpose
	int n=mat.size();
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			swap(mat[i][j], mat[j][i]);
		}
	}
	//rotate
	for(int i=0;i<mat.size();i++){
		reverse(mat[i].begin(), mat[i].end());
	}
	
	//print
	for(auto row: mat){
		for(auto val: row){
			cout<<val<<" ";
		}
		cout<<endl;
	}
}
int main(){
	vector<vector<int>>mat={{1,2,3},{4,5,6},{7,8,9}};
	cout<<"original image is: "<<endl;
	for(auto row: mat){
		for(auto val: row){
			cout<<val<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"rotated image is: "<<endl;
	rotate(mat);
	return 0;
}
