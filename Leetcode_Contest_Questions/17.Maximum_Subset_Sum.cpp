

long long f(int ind, long long A[], int N, int taken, vector<vector<int>>&dp){
        if(ind >= N) return 0;
        
        if(dp[ind][taken] != -1) return dp[ind][taken];
        
        int take,notTake;
        if(taken == 0){
             take = A[ind] + f(ind+1,A,N,1,dp);
             return dp[ind][taken] = take;
        }
        
        take = A[ind] + f(ind+1,A,N,1,dp);
        notTake = f(ind+1,A,N,0,dp); 
        
        return dp[ind][taken] = max(take,notTake);
    }
    long long findMaxSubsetSum(long long A[], int N)
    {
        vector<vector<int>>dp(N+1, vector<int>(2,-1));
        return f(0,A,N,1,dp);
    }