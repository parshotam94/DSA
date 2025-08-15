#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//move all zeroes to the end.
int main() {
    vector<int>arr={0,2,3,0,4,0};
    int j=-1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<arr.size();i++){
        if(arr[i]!=0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
//TC: O(n)
//SC: O(1)


//union of two sorted arrays
int main(){
    vector<int>arr1={1,2,2,3,4,5};
    vector<int>arr2={2,3,4,4,5};
    vector<int>unionArr;
    int n1=arr1.size();
    int n2=arr2.size();
    int i=0, j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(unionArr.size()==0 || unionArr.back()!=arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;
        }else{
            if(unionArr.size()==0 || unionArr.back()!=arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if(unionArr.size()==0 || unionArr.back()!=arr1[i]){
            unionArr.push_back(arr1[i]);
        }
        i++;
    }
    while(j<n2){
        if(unionArr.size()==0 || unionArr.back()!=arr2[j]){
            unionArr.push_back(arr2[j]);
        }
        j++;
    }
    cout<<"Union list is: ";
    for(int i=0;i<unionArr.size();i++){
        cout<<unionArr[i]<<" ";
    }
    return 0;
}
TC:O(n+m)
SC:O(n+m)

//insertion of two sorted arrays;
int main(){
    vector<int>arr1={1,2,2,3,4,5};
    vector<int>arr2={2,3,4,4,5};
    vector<int>insArr;
    int n1=arr1.size();
    int n2=arr2.size();
    int i=0, j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j])
            i++;
        else if(arr1[i]>arr2[j])
            j++;
        else{
            insArr.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    cout<<"Intersection list is: ";
    for(int i=0;i<insArr.size();i++){
        cout<<insArr[i]<<" ";
    }
    return 0;
}
//TC: O(n+m)
//SC: O(min(n, m));

//longest subarray with sum k;
int main(){
    vector<int>arr={1,2,3,1,1,1,1,4,2,3};
    int sum=0, maxlen=0;
    int left=0;
    int k=3;
    int n=arr.size();
    for(int right=0;right<n;right++){
        sum+=arr[right]; //it will add current element.
        
        while(sum>k && left<=right){//this loop will shrink our window till we get sum<=k;
            sum-=arr[left];
            left++;
        }
        if(sum==k){ //this will return maxlen;
            maxlen=max(maxlen, right-left+1);
        }
    }
    cout<<"The longest subarray with sum "<<k<<" is: "<<maxlen;
    return 0;
}
//TC: O(n)
//SC: O(1)

//Dutch national flag
int main(){
	vector<int>arr={0, 1, 0, 0, 2, 1, 1, 2, 2};
	int low=0, mid=0, high=arr.size()-1;
	while(mid<=high){
		if(arr[mid]==0){
			swap(arr[mid], arr[low]);
			low++;
			mid++;
		}
		else if(arr[mid]==1){
			mid++;
		}
		else{
			swap(arr[mid], arr[high]);
			high--;
		}
	}
	cout<<"Solved array is: ";
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
//TC: O(n)
//SC: O(1)
//other approaches: naive approach-> use sort function to sort, Better approach-> count number of 0, 1, 2 and arrange accordingly using for or while loop;

//majority element
int main(){
	unordered_map<int, int> mpp;
	vector<int>arr={1, 2, 2, 2, 2, 4, 3};
	int ans;
	for(int i=0;i<arr.size();i++){
		mpp[arr[i]]++;
	}
	for(auto it: mpp){
		if(it.second>arr.size()/2){
			ans=it.first;
		}
	}
	cout<<"element occuring greater than half of the size of array is: "<<ans;
	return 0;
}
//TC: O(nlogn)
//SC: O(1)


//Kadane's Algorithm (Max Subarray Sum)
int main(){
	vector<int>arr={1, 5, -2, 6, -5, 8, 3};
	int n=arr.size(), sum=0, maxSum=INT_MIN;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		if(sum>maxSum){
			maxSum=sum;
		}
		if(sum<0){
			sum=0;
		}
	}
	cout<<"Max sum is: "<<maxSum;
	return 0;
}
//TC: O(n)
//SC: O(1)
