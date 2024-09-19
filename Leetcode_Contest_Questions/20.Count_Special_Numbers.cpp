// You are given an array arr[ ] of size N consisting of only positive integers. Your task is to find
// the count of special numbers in the array. A number is said to be a special number if it is
// divisible by at least 1 other element of the array.
// Example 1:
// Input:
// arro
// Output:
// 1
// Explanation:
// The number 6 is the only special number in the
// array as it is divisible by the array elements 2
// and 3. Hence, the answer is 1 in this case.

// sieve of erathosenes
class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        int mx = *max_element(arr.begin(), arr.end());
        vector<int>special(mx+1,0);
        
        for(int i=0; i<N; i++){
            if(special[arr[i]] < 2){
                for(int j = arr[i]; j<=mx; j+=arr[i]){
                    special[j]++;
                }
            }
        }
        
        int ans = 0;
        for(auto it : arr){
            if(special[it] > 1){
                ans++;
            }
        }
        
        return ans;
    }
};