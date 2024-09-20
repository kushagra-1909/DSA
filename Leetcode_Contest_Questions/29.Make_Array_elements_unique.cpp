// Given an array arr[ ] of N elements, your task is to find the minimum number of increment
// operations required to make all the elements of the array unique. ie- no value in the array
// should occur more than once. In an operation a value can be incremented by 1 only.
// Example 1:
// Input: N = 3 arr[] = {1,2,2}
// Output:
// 1
// Explanation:
// If we increase arr[2] by
// array becomes {1, 2, 3}
// Hence, the answer is 1
// 1 then the resulting
// and has all unique values.
// in this case.

// Input:
// N = 4 arr[] = {1,1,2,3}
// Output:
// 3
// Explanation:
// If we increase arr[0] by 3, then all array
// elements will be unique. Hence, the answer
// is 3 in this case.

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        sort(arr.begin(),arr.end());
        long long ans = 0;
        for(int i=1; i<N; i++){
            if(arr[i] <= arr[i-1]){
                ans += arr[i-1]-arr[i]+1;
                arr[i] = arr[i-1] + 1;
            }
        }
        return ans;
    }
};