#include<bits/stdc++.h>
using namespace std;
bool BS(vector<vector<int>>&mat, int row, int target){
	int n=mat[0].size();
	int start=0, end=n;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(target==mat[row][mid]){
			return true;
		}else if(target<mat[row][mid]){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	return false;
}
bool find(vector<vector<int>>&mat, int target, int n, int m){
	int start=0, end=n-1;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(target>=mat[mid][0] && target<=mat[mid][m-1]){
			return BS(mat, mid, target);
		}
		else if(target<mat[mid][0]){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	return false;
}
int main(){
	vector<vector<int>>mat={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Matrix size: "<<mat.size();
	cout<<"Matrix[0] size: "<<mat[0].size();
	bool val=find(mat, 34, 3, 4);
	if(val){
		cout<<"found";
	}else{
		cout<<"not found";
	}
	return 0;
}
