//next permutation
/*
1: Find Breakpoint

Traverse from right ? left, find the first index i where
nums[i] < nums[i+1].

If no such index exists ? the array is the last permutation ? reverse it.

2: Find Just Larger Element

3: Again traverse from right ? left, find the first index j where
nums[j] > nums[i].

Swap nums[i] and nums[j].

4: Reverse the Suffix

5: Reverse the subarray from i+1 to end.
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int bpi = -1;

        // Step 1: find breakpoint index
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                bpi = i;
                break;
            }
        }

        // Step 2: if no breakpoint -> reverse whole array
        if (bpi == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: find element just greater than nums[bpi] (from right)
        for (int j = n - 1; j > bpi; j--) {
            if (nums[j] > nums[bpi]) {
                swap(nums[j], nums[bpi]);
                break;  // ? stop after first valid swap
            }
        }

        // Step 4: reverse suffix
        reverse(nums.begin() + bpi + 1, nums.end());
    }
};

// Search in rotated sorted array 1
/*
Initialize st = 0, end = n-1, pivot = -1.

Find pivot:

Traverse array from i = 0 to n-2.

If nums[i] > nums[i+1], set pivot = i and break.

If pivot == -1 (array not rotated):

Apply BinarySearch(nums, st, end, target).

Else (array rotated):

Apply BinarySearch(nums, st, pivot, target).

If found, return index.

Otherwise, apply BinarySearch(nums, pivot+1, end, target).

If not found in either half, return -1.
*/
class Solution {
public:
    int BinarySearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;  // not found
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, end = n - 1;
        int pivot = -1;

        // Find pivot (point where array rotates)
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) { 
            // array not rotated
            return BinarySearch(nums, st, end, target);
        }

        // Search in both halves
        int ans1 = BinarySearch(nums, st, pivot, target);
        if (ans1 != -1) return ans1;

        return BinarySearch(nums, pivot + 1, end, target);
    }
};


//search in rotated sorted array 2(leetcode 81)
/*
Initialize st = 0, end = n-1, pivot = -1.

Find Pivot:

Traverse array from i = 0 to n-2.

If nums[i] > nums[i+1], set pivot = i and break.

If pivot == -1 (array not rotated):

Apply BinarySearch(nums, st, end, target).

Return result (true if found, false otherwise).

Else (array rotated):

Apply BinarySearch(nums, st, pivot, target).

If found, return true.

Otherwise, apply BinarySearch(nums, pivot+1, end, target).

Return result (true if found, false otherwise).
*/
class Solution {
public:
    bool BinarySearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, end = n - 1;
        int pivot = -1;
        // Find pivot (point where array rotates)
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        if (pivot == -1) { 
            // array not rotated
            return BinarySearch(nums, st, end, target);
        }
        // Search in first half
        bool ans1 = BinarySearch(nums, st, pivot, target);
        if(ans1==true) return true;
        //if ans1==-1 then we will search second half
        return BinarySearch(nums, pivot + 1, end, target);
    }
};

//maximum product subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int prod=1;

        for(int i=0;i<nums.size();i++)
        {
          prod*=nums[i];
          maxi=max(prod,maxi);
          if(prod==0)
           prod=1;
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
          prod*=nums[i];

          maxi=max(prod,maxi);
          if(prod==0)
           prod=1;
        }
        return maxi;
    }
};

//3sum
/*
Initialize maxi = -8 (to store maximum product).

Set prod = 1.

Left to Right Pass:
3. Loop i from 0 to n-1:

Multiply prod = prod * nums[i].

Update maxi = max(maxi, prod).

If prod == 0, reset prod = 1.

Right to Left Pass:
4. Reset prod = 1.
5. Loop i from n-1 down to 0:

Multiply prod = prod * nums[i].

Update maxi = max(maxi, prod).

If prod == 0, reset prod = 1.

Return maxi as the maximum product subarray.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end());
        for(int i=0;i<n;i++){
            if(i>0 && arr[i]==arr[i-1]) continue; ///for i duplicates
            int j=i+1;
            int k=n-1;
            while(j<k){
                long long sum=(long long)arr[i]+(long long)arr[j]+(long long)arr[k];
                if(sum<0){
                    j++;
                }else if(sum>0){
                    k--;
                }else{
                    ans.push_back({arr[i], arr[j], arr[k]});
                    j++, k--;
                    while(j<k && arr[j]==arr[j-1]) j++; //for removing duplicates
                    while(j<k && arr[k]==arr[k+1]) k--;
                }
            }
        }
        return ans;
    }
};

//4sum
/*
Sort the input array arr.

Initialize result list ans = [].

Loop i from 0 to n-1:

If i > 0 and arr[i] == arr[i-1], skip to avoid duplicates.

Loop j from i+1 to n-1:

If j > i+1 and arr[j] == arr[j-1], skip to avoid duplicates.

Set two pointers:

k = j+1, l = n-1.

While k < l:

Compute sum = arr[i] + arr[j] + arr[k] + arr[l].

If sum == target:

Add quadruplet [arr[i], arr[j], arr[k], arr[l]] to ans.

Move k++, l--.

Skip duplicate values for k and l.

Else if sum < target: move k++.

Else: move l--.

After all iterations, return ans as the list of unique quadruplets.
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end());
        for(int i=0;i<n;i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && arr[j]==arr[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=(long long)arr[i]+(long long)arr[j]+(long long)arr[k]+(long long)arr[l];
                    if (sum == target) {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && arr[k] == arr[k - 1]) k++;
                    while (k < l && arr[l] == arr[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
                }
            }
        }
        return ans;
    }
};

//rearrange array elements by sign
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int pos[n/2];
        int neg[n/2];
        int j=0, k=0;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                neg[j++]=nums[i];
            }else{
                pos[k++]=nums[i];
            }
        }
        j=0, k=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i]=pos[j++];
            }else{
                nums[i]=neg[k++];
            }
        }
        return nums;
    }
};

//sort colors(Dutch National Flag)
/*
Initialize three pointers:

low = 0 ? boundary for 0s

mid = 0 ? current element being checked

high = n-1 ? boundary for 2s

While mid <= high:

If nums[mid] == 0:

Swap nums[low] and nums[mid].

Increment both low and mid.

Else if nums[mid] == 1:

Just increment mid.

Else (nums[mid] == 2):

Swap nums[mid] and nums[high].

Decrement high.

Continue until mid > high.

Array is now sorted with all 0s, then 1s, then 2s.
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0, mid=0, high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++, mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

