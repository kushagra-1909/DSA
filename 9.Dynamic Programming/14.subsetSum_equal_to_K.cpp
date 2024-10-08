#include <bits/stdc++.h>
bool fun(int ind, int target, vector<int> & arr, vector<vector<int>>&dp){
    if(target == 0) return true;
    if(ind == 0) return arr[0] == target;
    if(dp[ind][target] != -1){
        return dp[ind][target];
    }

    bool notTake = fun(ind-1,target,arr,dp);
    bool take = false;
    if(target >= arr[ind]){
        take = fun(ind-1,target-arr[ind],arr,dp);
    } 
    return dp[ind][target] =  (take) || (notTake);
} 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return fun(n-1,k,arr,dp);
}