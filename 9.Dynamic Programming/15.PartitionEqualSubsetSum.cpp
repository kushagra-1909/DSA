bool fun(int ind, int target, vector<int>&arr, vector<vector<int>>&dp){
	if(target == 0) return true;
	if(ind == 0) return arr[0] == target;
	if(dp[ind][target] != -1){
		return dp[ind][target];
	}

	bool notTake = fun(ind-1, target, arr, dp);
	bool take = false;
	if(target >= arr[ind]){
		take = fun(ind-1,target-arr[ind],arr,dp);
	}
	return dp[ind][target] = take | notTake;
}
bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(int i=0; i<arr.size(); i++){
		sum += arr[i];
	}
	int target = 0;
	if(sum %2 == 0){
		target = sum/2;
	}
	else{
		return false;
	}
	vector<vector<int>>dp(n,vector<int>(target+1,-1));
	return fun(n-1,target,arr,dp);
}
