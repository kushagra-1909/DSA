int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totsum = 0;
    for(int i=0; i<arr.size(); i++){
        totsum += arr[i];
    }
    int k = totsum;
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i=0; i<n; i++) dp[i][0] = true;
    if(arr[0] <= k) dp[0][arr[0]] = true;
    for(int ind =1 ; ind<n; ind++){
        for(int target =1; target<=k; target++){
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(arr[ind] <= target) take = dp[ind-1][target-arr[ind]];
            dp[ind][target] = take | notTake;
        }
    }

    int mini = 1e9;
    for(int s1=0; s1<=totsum/2; s1++){
        if(dp[n-1][s1] == true){
            mini = min(mini,abs((totsum-s1)-s1));
        }
    }
    return mini;
}
