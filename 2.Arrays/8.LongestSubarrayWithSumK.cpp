#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    int len = 0;
    for(int i=0; i<nums.size(); i++){
        for(int j=i; j<nums.size(); j++){
            int sum = 0;
            for(int m = i; m<=j; m++){
                sum += nums[m];
            }
            if(sum == k){
                len = max(len,j-i+1);
            }
        }
    }
    return len;
}

// better approach with hashing work only when only positive elements present in array
int getLongestSubarray(vector<int>& nums, int k){
    int n = nums.size();
    unordered_map<int,int>mpp; // sum->index
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
        if(sum == k){
            len = max(len,i+1);
        }
        if(mpp.find(sum-k) != mpp.end()){
            len = max(len,i-mpp[sum-k]);
        }
        mpp[sum] = i;
    }
} 

// work with both positives and negatives elements in array
int getLongestSubarray(vector<int>& nums, int k){
    int n = nums.size();
    int sum = 0;
    unordered_map<int,int>mpp; // sum->index
    int len = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
        if(sum == k){
            len = max(len,i+1);
        }
        if(mpp.find(sum-k) != mpp.end()){
            len = max(len,i-mpp[sum-k]);
        }
        if(mpp.find(sum) == mpp.end()){
            mpp[sum] = i;
        }
    }
} 

// two pointer approach -> O(n)
int getLongestSubarray(vector<int>& nums, int k){
    int left = 0;
    int right = 0;
    int n = nums.size();
    int len = 0;
    while(right < n){
        while(sum > k){
            sum -= nums[left];
            left++;
        }

        if(sum == k){
            len = max(right-left+1, len);
        }

        right++;
        if(right < n) sum += nums[right];
    }
} 