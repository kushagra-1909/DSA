#include <bits/stdc++.h>
int fun(int ind, int x, vector<int>&num, vector<vector<int>>&dp){
    if(ind == 0){
        if(x % num[0] == 0) return x/num[0];
        else return  1e9;
    }
    if(dp[ind][x] != -1){
        return dp[ind][x];
    }
    int notTake = 0 + fun(ind-1,x,num,dp);
    int take = INT_MAX;
    if(x >= num[ind]){
        take = 1 + fun(ind,x-num[ind],num,dp);
    }
    return dp[ind][x] = min(take,notTake);
} 
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>>dp(n,vector<int>(x+1,-1));
    int ans = fun(n-1,x,num,dp);
    if(ans >= 1e9){
        return -1;
    }
}