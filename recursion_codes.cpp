

//basic recursion to print numbers from right to left.
#include <iostream>
using namespace std;
int print(int n){
    if(n==0){
        return 0;
    }else{
        cout<<n<<" ";
        return print(n-1);
    }
}
int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    print(n);

    return 0;
}

//tower of hanoi
#include<iostream>
using namespace std;
void tower(int n, char beg, char aux, char end) {
    if(n<=0){
        cout<<"\nillegal entry.";
        return;
    }else if(n==1){
        cout<<"\nMove disc from "<<beg<<" to "<<end;
    }else{
        tower(n-1, beg, end, aux);
        tower(1, beg, aux, end);
        tower(n-1, aux, beg, end);
    }
}
int main(){
    int n;
    char a, b, c;
    cout<<"enter no of disks: ";
    cin>>n;
    cout<<"Tower of Hanoi of "<<n<<" discs."<<endl;
    tower(n,'a','b','c');
}

//is array sorted using recursion
#include<iostream>
using namespace std;
int isSorted(int arr[], int n){
    if(n==1){
        return 1;
    }
    return (arr[n-1]<arr[n-2])?0:isSorted(arr, n-1);
    //here we are making recursive call and checking backward whether the element at n-1 < n-2. if no then we will return 0 and if yes then it will recursively execute till the base case.
}
int main(){
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"entered array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int sorted=isSorted(arr, n);
    if(sorted==1){
        cout<<"Yes, it is a sorted array.";
    }else{
        cout<<"No, it is not a sorted array.";
    }
}

//decimal to binary using recursion.
#include<iostream>
using namespace std;
int DecToBin(int n){
    if(n==0){
        return 0;
    }else{
        return n%2+10*DecToBin(n/2);
    }
}
int main(){
    int d;
    cout<<"enter the decimal number: ";
    cin>>d;
    int binary=DecToBin(d);
    cout<<"Binary number of "<<d<<" is: "<<binary;
    return 0;
}


//first n fibonacci numbers
#include<iostream>
#include<vector>
using namespace std;

int fibo(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else{
    return fibo(n-2)+fibo(n-1);
    }
}
int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    vector<int>res;
    for(int i=0;i<n;i++){
        res.push_back(fibo(i));
    }
    cout<<"\nFibonacci sequence is: ";
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}

//reversing queue

#include <iostream>
#include <queue>
using namespace std;

// Recursive function to reverse the queue
void reverseQueue(queue<int> &q) {
    if (q.empty()) return; // base case
    
    int val = q.front(); // store front element
    q.pop();             // remove front element
    
    reverseQueue(q);     // reverse the remaining queue
    
    q.push(val);         // add stored element at the back
}

int main() {
    queue<int> q;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    // Reverse the queue
    reverseQueue(q);

    // Print reversed queue
    cout << "Reversed queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

