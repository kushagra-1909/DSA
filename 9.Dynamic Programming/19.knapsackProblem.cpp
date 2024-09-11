#include <bits/stdc++.h> 
int fun(vector<int>weight, vector<int>value, int ind, int maxWeight, vector<vector<int>>&dp){
	if(ind == 0){
		if(maxWeight >= weight[0]) return value[0];
		else return 0;
	}
	if(dp[ind][maxWeight] != -1){
		return dp[ind][maxWeight];
	}
	int notTake = 0 + fun(weight,value,ind-1,maxWeight,dp);
	int take = INT_MIN;
	if(maxWeight >= weight[ind]){
		take = value[ind] + fun(weight,value,ind-1,maxWeight-weight[ind],dp);
	}
	return dp[ind][maxWeight] = max(take,notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return fun(weight,value,n-1,maxWeight,dp);
}