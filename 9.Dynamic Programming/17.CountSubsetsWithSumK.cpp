#define M 1000000007
int fun(int ind, int target, vector<int>&arr, vector<vector<int>>&dp){
	if(ind == 0){
		if(target == 0 && arr[0] == 0) return 2;
		if(target == 0 || target == arr[0]) return 1;
		return 0;
	}

	if(dp[ind][target] != -1){
		return dp[ind][target];
	}

	int notTake = fun(ind-1,target,arr,dp);
	int take = 0;
	if(target >= arr[ind]){
		take = fun(ind-1,target-arr[ind],arr,dp);
	}
	return dp[ind][target] = ((notTake)%M + (take)%M)%M;
}
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>>dp(n,vector<int>(k+1,-1));
	return fun(n-1,k,arr,dp);
}
