//  Count Number of Nice Subarrays
// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
// Example 2:

// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There are no odd numbers in the array.
// Example 3:

// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16

// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.
// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// Example 2:

// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15

// Count number of Subarray whose sum is equal to k

// prefix Sum concept using hashing
unordered_map<int,int>mpp // sum -> index
int preSum = 0;
int cnt = 0;
mpp[0] = 1;

for(int i=0; i<n; i++){
    sum += arr[i];
    int remove = preSum-k;
    cnt += mpp[remove];
    mpp[preSum] += 1;
}
return cnt;

// T.C -> o(n) && S.C -> O(1)  without any hashing
// find the number of subarrays whose sum <= goal - find the number of subarrays whose sum <= goal-1 => then we will have number of subarrays whose sum is equal to goal

class Solution {
public:
    int fun(vector<int>nums, int k, int n){
        int l=0,r=0,cnt=0;
        int sum  =0;
        if(k < 0) return 0;
        while(r<n){
            sum += (nums[r])%2;
            while(sum > k){
                sum-=(nums[l])%2;
                l++;
            }
            if(sum <= k){
                cnt = cnt + (r-l+1);
            }
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans = fun(nums,goal,n) - fun(nums,goal-1,n);
        return ans;
    }
};

