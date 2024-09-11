// Given an integer array nums and an integer k, return the number of good subarrays of nums.

// A good array is an array where the number of different integers in that array is exactly k.

// For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
// A subarray is a contiguous part of an array.

 

// Example 1:

// Input: nums = [1,2,1,2,3], k = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
// Example 2:

// Input: nums = [1,2,1,3,4], k = 3
// Output: 3
// Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

class Solution {
public:
    int fun(vector<int>nums, int k, int n){
        int l=0,r=0,cnt=0;
        unordered_map<int,int>mpp;
        if(k < 0) return 0;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            if(mpp.size() <=k){
                cnt += (r-l)+1;
            }
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = fun(nums,k,n)-fun(nums,k-1,n);
        return ans;
    }
};