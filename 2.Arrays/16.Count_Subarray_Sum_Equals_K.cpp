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

