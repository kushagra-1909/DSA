#include <bits/stdc++.h>
int mod = (int)(1e9 + 7);
int fun(int ind, int sum, vector<int>&arr, vector<vector<int>>&dp){
    if(ind == 0){
        if(sum == 0 && arr[0] == 0) return 2;
        if(sum == 0 || arr[0] == sum) return 1;
        return 0;
    }

    if(dp[ind][sum] != -1){
        return dp[ind][sum];
    }

    int notTake = fun(ind-1, sum, arr,dp);
    int take = 0;
    if(sum >= arr[ind]){
        take = fun(ind-1,sum-arr[ind], arr,dp);
    }
    return dp[ind][sum] = (take + notTake)%mod;
} 
int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = 0;
    for(int i=0; i<n; i++){
        totSum += arr[i];
    }
    if(totSum - d < 0 || (totSum-d)%2 != 0) return 0;
    int k = (totSum-d)/2;
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return fun(n-1,k,arr,dp);
}


