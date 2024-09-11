#include <bits/stdc++.h> 
// variable starting and ending point in 2d Matrix
int fun(int i, int j, vector<vector<int>>&matrix, int n, int m, vector<vector<int>>&dp){
    if(j<0 || j>=m){
        return -1e9;
    }
    if(i == 0){
        return matrix[i][j];
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int up = matrix[i][j] + fun(i-1,j,matrix,n,m,dp);
    int dgl = matrix[i][j] + fun(i-1,j-1,matrix,n,m,dp);
    int dgr = matrix[i][j] + fun(i-1,j+1,matrix,n,m,dp);

    return dp[i][j] = max(up,max(dgl,dgr));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{   
    int n = matrix.size(); // no. of rows
    int m = matrix[0].size(); // no. of cols
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int maxi = INT_MIN;
    for(int j = 0; j<m; j++){
        maxi = max(maxi,fun(n-1,j,matrix,n,m,dp));
    }
    return maxi;
}